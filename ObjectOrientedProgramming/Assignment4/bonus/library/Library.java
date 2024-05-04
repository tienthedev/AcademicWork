package library;
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
    /**
    * Print list of patrons in Library.
    * @return the list of patrons in Library
    * @since 1.0
    */
    public String patronMenu() {
        StringBuilder menu = new StringBuilder("List of Patrons:\n");
        for (int i = 0; i < patrons.size(); i++) {
            menu.append(i + 1).append(". ").append(patrons.get(i)).append("\n");
        }
        return menu.toString();
    }
    

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.name).append(" contains:\n");
        for (int i = 0; i < publications.size(); i++) {
            sb.append(i + 1).append(". ").append(publications.get(i)).append("\n");
        }
        return sb.toString();
    }
}
