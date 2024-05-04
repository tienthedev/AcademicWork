package library;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
/**
 * Models a library containing various publications.
 *
 * @author Tien Dung Le
 * @version 1.0
 * @since 1.0
 * @license.agreement GNU General Public License 3.0
 */

public class Library {
    private String name;
    private ArrayList<Publication> publications;
    private ArrayList<Patron> patrons;
    /**
    * Creates a Library instance.
    *
    * @param name the name of the Library
    * @since 1.0
    */
    public Library(String name) {
        this.name = name;
        publications = new ArrayList<>();
        patrons = new ArrayList<>();
    }
    public Library(BufferedReader br) throws IOException {
        // Call the constructor that initializes name and an empty ArrayList
        this.name = br.readLine();
        publications = new ArrayList<>();
        patrons = new ArrayList<>();

        // Read the number of objects written to the file
        int size = Integer.parseInt(br.readLine());
        System.out.println("Found: " + size + " objects...");
        System.out.println("Loading in process, do not close program...");

        // Loop to restore publications
        for (int i = 0; i < size; i++) {
            String type = br.readLine();        
            if ("publication".equals(type)) {
                System.out.println("Loading publications...");
                addPublication(new Publication(br));
            } 
            else if ("video".equals(type)) {
                System.out.println("Loading videos...");
                addPublication(new Video(br));
            }
            else if ("patron".equals(type)) {
                System.out.println("Loading patrons...");
                addPatron(new Patron(br));
            }
            
        }

    }
    public void save(BufferedWriter bw) {
        try {
            bw.write(this.name);
            bw.newLine();             
            bw.write(Integer.toString(publications.size() + patrons.size()));
            bw.newLine();

            for (Publication publication : publications) {
                if (publication instanceof Video) {
                    bw.write("video"); 
                }
                else {
                    bw.write("publication");
                }
                bw.newLine();
                publication.save(bw); 
            }

            for (Patron patron : patrons) {
                bw.write("patron"); 
                bw.newLine();
                patron.save(bw);
            }
        } catch (IOException e) {
            System.err.println("Error writing to file.");
        }
    }
    /**
    * Add patron to Library list of patron.
    *
    * @param patron the patron object added to the list of patrons
    * @since 1.0
    */
    public void addPatron(Patron patron) {
        patrons.add(patron);
    }
    /**
    * Add publication to Library.
    *
    * @param publication the publication object added to the Library
    * @since 1.0
    */
    public void addPublication(Publication publication) {
        publications.add(publication);
        System.out.println("Added " + publication + " to the library.");
    }
    /**
    * Checkout publication from Library.
    *
    * @param publicationIndex the index of the publication in the Library array
    * @param patronIndex the index of patron checking out the publication
    * @since 1.0
    */

    public void checkOut(int publicationIndex, int patronIndex) {
        // Implement checkout logic here
        try {
            Publication publication = publications.get(publicationIndex);
            Patron patron = patrons.get(patronIndex);
            publication.checkOut(patron);
        } catch (IndexOutOfBoundsException e) {
            // Handle the case where publicationIndex is out of bounds
            System.err.println("Invalid publication index. Please provide a valid index.");
        }
    }
    public void checkIn(int publicationIndex) {
        // Implement checkin logic here
        try {
            Publication publication = publications.get(publicationIndex);
            publication.checkIn();
        } catch (IndexOutOfBoundsException e) {
            // Handle the case where publicationIndex is out of bounds
            System.err.println("Invalid publication index. Please provide a valid index.");
        }
    }
    /**
    * Print list of patrons in Library.
    * @return the list of patrons in Library
    * @since 1.0
    */
    public String patronMenu() {
        if(patrons.isEmpty()){
            return "No patrons in " + this.name + ", please add a patron first.";
        }
        StringBuilder menu = new StringBuilder("List of Patrons:\n");
        for (int i = 0; i < patrons.size(); i++) {
            menu.append(i + 1).append(". ").append(patrons.get(i)).append("\n");
        }
        return menu.toString();
    }
    
    
    @Override
    public String toString() {
        if (publications.isEmpty()) {
            return "No publications in " + this.name;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(this.name).append(" contains:\n");
        for (int i = 0; i < publications.size(); i++) {
            sb.append(i + 1).append(". ").append(publications.get(i)).append("\n");
        }
        return sb.toString();
    }
}
