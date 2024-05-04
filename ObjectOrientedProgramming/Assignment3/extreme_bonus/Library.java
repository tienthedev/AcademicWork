
public class Library{
    private String name;
    private Publication[] publications;

    public Library(String name){
        this.name = name;
    }
    public void addPublication(Publication publication){
        if (publications == null) {
            publications = new Publication[3];
        }
    
        // Find the first available slot to add the publication
        for (int i = 0; i < publications.length; i++) {
            if (publications[i] == null) {
                publications[i] = publication;
                return; // Exit the loop once added
            }
        }
    
        System.out.println("Library is full. Cannot add more publications.");
    }
    
    public void checkOut(int publicationIndex, String patron){

    }

    @Override
    public String toString(){
        return this.name  + " contains: \n1. " + publications[0] + "\n2. " + publications[1] + "\n3. " + publications[2];
    }
}