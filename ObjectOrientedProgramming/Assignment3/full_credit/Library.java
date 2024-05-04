import java.util.ArrayList;
public class Library{
    private String name;
    private ArrayList<Publication> publications;

    public Library(String name){
        this.name = name;
        publications = new ArrayList<>();

    }
    public void addPublication(Publication publication) {
        publications.add(publication);
        System.out.println("Added " + publication + " to the library.");
    }
    
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