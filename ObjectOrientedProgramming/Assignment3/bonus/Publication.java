import java.time.LocalDate;

public class Publication {
    private String title;
    private String author;
    private int copyright;
    private Patron loanedTo;
    private LocalDate dueDate;

    public Publication(String title, String author, int copyright){
        if (copyright < 1900 || copyright > LocalDate.now().getYear()) {
            throw new IllegalArgumentException("Invalid copyright year. It should be between 1900 and the current year.");
        }
        this.title = title;
        this.author = author;
        this.copyright = copyright;
    }
    public void checkOut(Patron patron){
        this.loanedTo = patron;
        this.dueDate = LocalDate.now().plusDays(14);
        System.out.println("================================================");
        System.out.println(loanedTo + " checked out " + this.title + ", it is due on " + dueDate);

    }
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