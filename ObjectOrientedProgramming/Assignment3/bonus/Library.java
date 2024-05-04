import java.util.ArrayList;

public class Library {
    private String name;
    private ArrayList<Publication> publications;
    private ArrayList<Patron> patrons;

    public Library(String name) {
        this.name = name;
        publications = new ArrayList<>();
        patrons = new ArrayList<>();
    }

    public void addPatron(Patron patron) {
        patrons.add(patron);
    }

    public void addPublication(Publication publication) {
        publications.add(publication);
        System.out.println("Added " + publication + " to the library.");
    }

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
