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
    /**
    * Creates a Library instance.
    *
    * @param name the name of the Library
    * @since 1.0
    */
    public Library(String name) {
        this.name = name;
        publications = new ArrayList<>();
    }
    /**
    * Add publication to Library.
    *
    * @param publication the publication added to the Library
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
    * @param patron the patron checking out the publication
    * @since 1.0
    */
    public void checkOut(int publicationIndex, String patron) {
        try {
            // Attempt to get the Publication at the specified index
            Publication publication = publications.get(publicationIndex);

            // Call the checkout method on the Publication
            publication.checkOut(patron);
        } catch (IndexOutOfBoundsException e) {
            // Handle the case where publicationIndex is out of bounds
            System.err.println("Invalid publication index. Please provide a valid index.");
        }
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
