package library;
import java.time.LocalDate;
/**
* A library resource that can be checked out by a patron.
*
* @author Tien Dung Le
* @version 1.0
* @since 1.0
* @license.agreement Gnu General Public License 3.0
*/
public class Publication {
    private String title;
    private String author;
    private int copyright;
    private Patron loanedTo;
    private LocalDate dueDate;
    /**
    * Publicatation constructor.
    *
    * @param title the title of the publication
    * @param author the author of the publication
    * @param copyright the year of book publication

    * @since 1.0
    */
    public Publication(String title, String author, int copyright){
        if (copyright < 1900 || copyright > LocalDate.now().getYear()) {
            throw new IllegalArgumentException("Invalid copyright year. It should be between 1900 and the current year.");
        }
        this.title = title;
        this.author = author;
        this.copyright = copyright;
    }

    /**
    * Assign publication from Library to patron.
    *
    * @param patron the patron object checking out the publication
    * @since 1.0
    */
    public void checkOut(Patron patron){
        this.loanedTo = patron;
        this.dueDate = LocalDate.now().plusDays(14);
        System.out.println("================================================");
        System.out.println(loanedTo + " checked out " + this.title + ", it is due on " + dueDate);

    }
    /**
    * Checkin publication from Library.
    *
    * @since 1.0
    */
    public void checkIn(){
        System.out.println("================================================");
        System.out.println("You've returned " + this.title + " successfully!");
        this.loanedTo = null;
        this.dueDate = null;

    }
    @Override
    public String toString() {
        String publicationInfo = this.title + " by " + this.author + ", published on " + this.copyright;
    
        if (this.loanedTo != null && this.dueDate != null) {
            publicationInfo += ", loaned to " + this.loanedTo + ", due back on " + this.dueDate;
        }
    
        return publicationInfo;
    }
}