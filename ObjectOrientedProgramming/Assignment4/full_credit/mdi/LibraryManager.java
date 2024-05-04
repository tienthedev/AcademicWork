package mdi;
import library.Library;
import library.Publication;
import library.Video;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
* Menu-Driven Interface for Library Management System
*
* @author Tien Dung Le
* @version 1.0
* @since 1.0
* @license.agreement Gnu General Public License 3.0
*/


public class LibraryManager {
    
    public static void main(String[] args) {
        //Create publication objects
        Scanner input = new Scanner(System.in);
        Publication book0 = new Publication("Java For Dummies", "BarryBurd", 2015);
        Publication book1 = new Publication("Effective Java", "JoshuaBloch", 2017);
        Publication book2 = new Publication("Clean Code", "RobertMartin", 2008);

        Video video0 = new Video("Unbroken", "Laura Hillenbrand", 2014, 137);
        Video video1 = new Video("Unbroken: Path to Redemption", "Laura Hillenbrand", 2018, 98);
        Video video2 = new Video("The Fast and the Furious: Tokyo Drift", "Chris Morgan", 2006, 104);

        //Construct library object
        Library library = new Library("Java Library");
        
        //Add publication to library
        library.addPublication(book0);
        library.addPublication(book1);
        library.addPublication(book2);
        library.addPublication(video0);
        library.addPublication(video1);
        library.addPublication(video2);

        System.out.println("================================================");
        System.out.println("Welcome to Java Library!");
        System.out.println("================================================");
        System.out.println("Creating a new patron profile...");
        System.out.print("Enter Patron's name:\n> ");
        String patronName = input.nextLine();
        String patron = patronName;
        System.out.println("================================================");
        System.out.println("Profile created for " + patron);
        System.out.println("================================================");
        
        

        boolean validInput = false;

do {
    System.out.println("================================================");
    System.out.print("What would you like to do today?\n1. Returning item\n2. Checking out an item\n3. Exit\n> ");
    int checkInOut;
    try {
        checkInOut = input.nextInt();
        input.nextLine(); // Consume the newline character
        System.out.println("================================================");
        switch (checkInOut) {
            case 1: // Start returning a book
                System.out.println("================================================");
                System.out.println(library);
                System.out.print("Choose an item to return:\n> ");
                input.nextLine(); // Consume the newline character
                // Implement book return logic here
                
                System.out.println("Item returned successfully!");
                break; // Finish returning a book
    
            case 2: // Start checking out a book
                System.out.println("================================================");
                System.out.println(library);
                System.out.print("Choose an item to check out:\n> ");
                int itemCheckout;
                try {
                    itemCheckout = input.nextInt();
                    input.nextLine(); // Consume the newline character
                    library.checkOut(itemCheckout - 1, patron);
                } catch (InputMismatchException e) {
                    System.err.println("Invalid input. Please enter a valid integer for item selection.");
                    input.nextLine(); // Clear the input buffer
                }
                break; // Finish checking out a book
    
            case 3:
                System.out.println("Thank you for using Java Library. Have a wonderful day!");
                validInput = true;
                break;
    
            default:
                System.out.println("That is not a valid input. Please try again.");
                break;
        }
    } catch (InputMismatchException e) {
        System.err.println("Invalid input. Please enter a valid integer for menu selection.");
        input.nextLine(); // Clear the input buffer
    }
} while (!validInput);


        input.close();
    }
}
