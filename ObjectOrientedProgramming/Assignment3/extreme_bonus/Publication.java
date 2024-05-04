import java.time.LocalDate;

public class Publication {
    private String title;
    private String author;
    private int copyright;
    private String loanedTo;
    private LocalDate dueDate;

    public Publication(String title, String author, int copyright){
        this.title = title;
        this.author = author;
        this.copyright = copyright;
    }
    public void checkOut(String patron){
        this.loanedTo = patron;
        this.dueDate = LocalDate.now().plusWeeks(3);
    }
    public void checkIn(){
        this.loanedTo = null;
        this.dueDate = null;
    }
    @Override
    public String toString(){
        return this.title + " by " + this.author + ", published on " + this.copyright;
    }
}