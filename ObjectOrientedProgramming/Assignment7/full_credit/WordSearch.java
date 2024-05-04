import java.util.Arrays;

import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.LinkedList;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class WordSearch {
    private static final String usage = "usage: java WordSearch [-h] [-v] [#threads] [#puzzles] [puzzleFile]...";

    public WordSearch(List<String> args) {
    
        // Validate the command line arguments
        if(args.size() > 0 && args.get(0).equals("-h")) {
            System.out.println(usage);
            System.exit(0);
        }
        if(args.size() > 0 && args.get(0).equals("-v")) {
             verbose = true;
             args.remove(0);
        } else {
             verbose = false;
        }
        int threads = 0;
        try {
           
            threads = Integer.parseInt(args.get(0));
            args.remove(0);
        } catch(Exception e) {
            System.err.println("Error: Invalid number of threads\n" + usage);
            System.exit(-1);
        }
        NUM_THREADS = threads;
        int numPuzzles = 0;
        try {
            
            numPuzzles = Integer.parseInt(args.get(0));
            args.remove(0);
        } catch(Exception e) {
            System.err.println("Error: Invalid number of puzzles\n" + usage);
            System.exit(-1);
        }

        // Load the puzzles!
        for(String puzzleName : args) {
            try(BufferedReader br = new BufferedReader(new FileReader(puzzleName))) {
                puzzles.add(new Puzzle(puzzleName, br));
            } catch(IOException e) {
                System.err.println("Unable to load puzzle " + puzzleName);
            }
        }
        
        if(puzzles.size() != args.size()) System.exit(-3);
        
        if(numPuzzles < puzzles.size()) puzzles.subList(numPuzzles, puzzles.size()).clear();
        else if (numPuzzles > puzzles.size()) {
            for(int i=puzzles.size(); i<numPuzzles; ++i)
                puzzles.add(puzzles.get(i%puzzles.size()));
        }
        NUM_PUZZLES = puzzles.size();
        
    }

    public void solve() {
        System.err.println("\n" + NUM_PUZZLES + " puzzles with " + NUM_THREADS + " threads");
        
        // Calculate the range of puzzles for each thread
        int puzzlesPerThread = NUM_PUZZLES / NUM_THREADS;
        int remainingPuzzles = NUM_PUZZLES % NUM_THREADS;
    
        List<Thread> threads = new ArrayList<>(); // To store the created threads.
    
        for (int threadID = 0; threadID < NUM_THREADS; ++threadID) {
            int startPuzzle = threadID * puzzlesPerThread;
            int endPuzzle = (threadID + 1) * puzzlesPerThread;
    
            if (threadID < remainingPuzzles) {
                // Distribute the remaining puzzles equally among the first few threads
                endPuzzle += 1;
            }
    
            final int finalThreadID = threadID; // Make a copy of threadID
            final int finalEndPuzzle = endPuzzle; // Make a copy of endPuzzle
    
            // Create a new thread to solve puzzles for the current thread
            Thread thread = new Thread(() -> solve(finalThreadID, startPuzzle, finalEndPuzzle));
            threads.add(thread);
    
            // Start the thread
            thread.start();
        }
    
        // Wait for all threads to finish
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                System.err.println("Thread interrupted: " + e.getMessage());
            }
        }
    }
    
    
    

    public void solve(final int threadID, final int firstPuzzle, final int lastPuzzlePlusOne) {
        System.err.println("Thread " + threadID + ": " + firstPuzzle + "-" + (lastPuzzlePlusOne - 1));
        for (int i = firstPuzzle; i < lastPuzzlePlusOne; ++i) {
            Puzzle p;
            synchronized (puzzles) {
                if (i < puzzles.size()) {
                    p = puzzles.get(i);
                } else {
                    break; // Ensure that we don't access an index out of bounds
                }
            }
    
            Solver solver = new Solver(p);
            for (String word : p.getWords()) {
                try {
                    Solution s = solver.solve(word);
                    if (s == null) {
                        System.err.println("#### Failed to solve " + p.name() + " for '" + word + "'");
                    } else {
                        synchronized (solutions) {
                            solutions.add(s);
                        }
                    }
                } catch (Exception e) {
                    System.err.println("#### Exception solving " + p.name()
                            + " for " + word + ": " + e.getMessage());
                }
            }
        }
    }
    
    public void printSolutions() {
        for(Solution s : solutions)
            System.out.println(s);
    }
    public static void main(String[] args) {
        WordSearch ws = new WordSearch(new LinkedList<>(Arrays.asList(args)));
        ws.solve();
        if(ws.verbose) ws.printSolutions();
    }

    public final int NUM_THREADS;
    public final int NUM_PUZZLES;
    public final boolean verbose;

    private List<Puzzle> puzzles = new ArrayList<>();
    private SortedSet<Solution> solutions = new TreeSet<>();
}
