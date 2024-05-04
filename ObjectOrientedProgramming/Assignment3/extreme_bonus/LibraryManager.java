import java.util.Scanner;
public class LibraryManager {
    public static void PrintSection() {
        System.out.println("====================================");
    }
    public static void main(String[] args) {
        //Create publication objects
        Scanner input = new Scanner(System.in);
        Publication book0 = new Publication("Java For Dummies", "BarryBurd", 2015);
        Publication book1 = new Publication("Effective Java", "JoshuaBloch", 2017);
        Publication book2 = new Publication("Clean Code", "RobertMartin", 2008);

        //Construct library object
        Library library = new Library("Java Library");

        //Add publication to library
        library.addPublication(book0);
        library.addPublication(book1);
        library.addPublication(book2);
        PrintSection();
        System.out.println("Welcome back, " + System.getProperty("user.name") + "!");
        PrintSection();

        System.out.println("What would you like to do today?");
        System.out.println("1. Returning a book \n2. Checking out a book?");
        int checkInOut = input.nextInt();
        // Consume the newline character
        input.nextLine(); 
        PrintSection();

        boolean validInput = false;
        
        while (!validInput) {
            switch(checkInOut){
                case 1: //Start returning a book
                    System.out.println("For security, please tell me which book are you returning?");
                    String bookReturn = input.nextLine();
                    if (bookReturn.toLowerCase().equals("java for dummies")) {
                        book0.checkIn();
                        System.out.println("You have returned Java For Dummies, thank you!");
                        validInput = true;

                    } else if (bookReturn.toLowerCase().equals("clean code")) {
                        book1.checkIn();
                        System.out.println("You have returned Clean Code, thank you!");
                        validInput = true;
                    } else if (bookReturn.toLowerCase().equals("effective java")) {
                        book2.checkIn();
                        System.out.println("You have returned Effective Java, thank you!");
                        validInput = true;
                    } else {
                        System.out.println("That book is not in our library or the input is invalid. Please try again.");
                        validInput = false;
                        PrintSection();
                    }
                    break;
                    //Finish returning a book
                case 2: //Start checking out a book
                
                    System.out.println(library);
                    PrintSection();
                    System.out.println("Choose a book to check out:");
                    int bookChoice = input.nextInt();
                    // Consume the newline character
                    input.nextLine(); 
                    switch(bookChoice){
                        case 1:
                            book0.checkOut(System.getProperty("user.name"));
                            System.out.println("You have checked out Java For Dummies, good choice!");
                            validInput = true;
                            break;
                        case 2:
                            book1.checkOut(System.getProperty("user.name"));
                            System.out.println("You have checked out Clean Code, good choice!");
                            validInput = true;
                            break;
                        case 3:
                            book2.checkOut(System.getProperty("user.name"));
                            System.out.println("You have checked out Effective Java, good choice!");
                            validInput = true;
                            break;
                        default:
                            System.out.println("That is not a valid input. Please try again.");
                            validInput = false;
                            PrintSection();

                            break;
                    }
                    break;
                    //Finsh checking out a book
                default:
                    System.out.println("That is not a valid input. Please try again.");
                    validInput = false;
                    break;
            }
        }
        
        //Check out a book
        input.close();
    }
}
