package mdi;
import library.InvalidRuntimeException;
import library.Library;
import library.Publication;
import library.Video;
import library.Patron;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;


public class LibraryManager {
    private Library library;
    private Scanner input;
    public LibraryManager() {
        library = new Library("TD Library");
        input = new Scanner(System.in);
    }
    public void printDivider() {
        System.out.println("====================================================");
    }
    public void listPatron(){
        System.out.println(library.patronMenu());
    }
    public void checkOutPublication(){
        listPatron();
        if (library.patronMenu().contains("No patrons in")) {
            return;
        }
        System.out.print("Which patron is checking out?\n> ");
        int patronCheckout;
        try {
            patronCheckout = input.nextInt();
            input.nextLine(); // Consume the newline character
            printDivider();
            System.out.println(library);
            if(library.toString().contains("No publications in")){
                return;
            }
            System.out.print("Choose a book to check out:\n> ");
            int bookCheckout;
            try {
                bookCheckout = input.nextInt();
                input.nextLine(); // Consume the newline character
                library.checkOut(bookCheckout - 1, patronCheckout - 1);
            } catch (InputMismatchException ex) {
                System.err.println("Invalid input. Please enter a valid integer for book selection.");
                input.nextLine(); // Clear the input buffer
            }
        } catch (InputMismatchException e) {
            System.err.println("Invalid input. Please enter a valid integer for patron selection.");
            input.nextLine(); // Clear the input buffer
        }
    }
    public void checkInPublication(){
        listPatron();
        if (library.patronMenu().contains("No patrons in")) {
            return;
        }
        System.out.print("Which patron is returning?\n> ");
        try {
            int patronReturn = input.nextInt();
            input.nextLine(); // Consume the newline character
            printDivider();
            System.out.println(library);
            if(library.toString().contains("No publications in")){
                return;
            }
            System.out.print("Choose an item to return:\n> ");
            int bookReturn = input.nextInt();
            input.nextLine(); // Consume the newline character
            // Implement book return logic here
            library.checkIn(bookReturn - 1);
        } catch (InputMismatchException e) {
            System.err.println("Invalid input. Please enter a valid integer for patron or item selection.");
            input.nextLine(); // Clear the input buffer
        }

    }
    public void addPatron() {
        while (true) {
            System.out.println("Creating a new patron profile...");
            System.out.print("Enter Patron's name:\n> ");
            String patronName = input.nextLine();
            System.out.print("Patron's email:\n> ");
            String patronEmail = input.nextLine();
            Patron patron = new Patron(patronName, patronEmail);
            library.addPatron(patron);
            printDivider();
            System.out.println("Profile created for " + patron);
            printDivider();
            System.out.print("Do you want to create another patron's profile? (Y/N):");
            String createAnother = input.nextLine();
            if (createAnother.toLowerCase().equals("n")) {
                System.out.println(library.patronMenu());
                break;
            }
        }
    }
    public void addPublication() {
        try {
            System.out.print("Enter the title of the publication:\n> ");
            String title = input.nextLine();
            System.out.print("Enter the author of the publication:\n> ");
            String author = input.nextLine();
            System.out.print("Enter the year of the publication:\n> ");
            int copyright = input.nextInt();
            Publication publication = new Publication(title, author, copyright);
            library.addPublication(publication);
        } catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        }
    }
    public void addVideo() {
        try {
            System.out.print("Enter the title of the video:\n> ");
            String title = input.nextLine();
            System.out.print("Enter the author of the video:\n> ");
            String author = input.nextLine();
            System.out.print("Enter the year of the video:\n> ");
            int copyright = input.nextInt();
            System.out.print("Enter the length of the video in minutes:\n> ");
            int duration = input.nextInt();
            Video video = new Video(title, author, copyright, duration);
            library.addPublication(video);
        } catch (InvalidRuntimeException | IllegalArgumentException e) {
            System.err.println(e.getMessage());
        }
    }
    public void saveLibrary() {
        System.out.print("Enter filename to save:\n>");
        String filename = input.nextLine();
        try(BufferedWriter bw = new BufferedWriter(new FileWriter(filename));) {
            library.save(bw);
            System.out.println("Library data saved to " + filename);
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
        
    }
    public void openLibrary() {
        System.out.print("Enter filename to open:\n>");
        String filename = input.nextLine();
        try(BufferedReader br = new BufferedReader(new FileReader(filename));){
            library = new Library(br); 
            System.out.println("Library data loaded from " + filename);
        } catch (IOException e) {
            System.err.println("Error opening file: " + e.getMessage());
        }
        
    }

    public void run() throws IOException, InterruptedException {
        String os = System.getProperty("os.name").toLowerCase();
        
        ProcessBuilder processBuilder;
        if (os.contains("win")) {
            processBuilder = new ProcessBuilder("cmd", "/c", "cls");
        } else {
            processBuilder = new ProcessBuilder("clear");
        }

        Process process = processBuilder.inheritIO().start();
        process.waitFor();

        boolean validInput = false;

        do {
            printDivider();
            System.out.printf("%30s\n\n", "TD Library");

            System.out.print("Main Menu\n1. List Patrons\n2. List Publications\n3. Check In\n4. Check Out\n5. Add\n6. Open Library\n7. Save Library\n8. Exit\n> ");
            int checkInOut;
            try {
                checkInOut = input.nextInt();
                input.nextLine(); 
                switch (checkInOut) {
                    case 3:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        checkInPublication();
                        break;

                    case 4:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        checkOutPublication();
                        break;

                    case 5:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        System.out.print("1. New Patron\n2. New Publication\n3. New Video\n>");
                        int c = input.nextInt();
                        input.nextLine();
                        switch(c){
                            case 1:
                                process = processBuilder.inheritIO().start();
                                process.waitFor();
                                addPatron();
                                break;
                            case 2:
                                process = processBuilder.inheritIO().start();
                                process.waitFor();
                                addPublication();
                                break;
                            case 3:
                                process = processBuilder.inheritIO().start();
                                process.waitFor();
                                addVideo();
                                break;
                            default:
                                System.out.println("That is not a valid input. Please try again.");
                                break;
                        }
                        break;

                    case 1:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        listPatron();
                        break;

                    case 2:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        System.out.println(library);
                        break;

                    case 6:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        openLibrary();
                        break;

                    case 7:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        saveLibrary();
                        break;

                    case 8:
                        process = processBuilder.inheritIO().start();
                        process.waitFor();
                        System.out.println("\n\n\n\n\n\n\n\n\nThank you for using TD Library. Have a wonderful day!\n\n\n\n\n\n\n\n");
                        validInput = true;
                        break;

                    default:
                        System.out.println("That is not a valid input. Please try again.");
                        break;
                }
            } catch (InputMismatchException e) {
                System.err.println("Invalid input. Please enter a valid integer for menu selection.");
                input.nextLine();
            }
        } while (!validInput);

        input.close();
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        LibraryManager manager = new LibraryManager();
        manager.run();
    }
}
