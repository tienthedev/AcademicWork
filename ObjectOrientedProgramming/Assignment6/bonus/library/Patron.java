package library;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

/**
* Patron object for library MDI
*
* @author Tien Dung Le
* @version 1.0
* @since 1.0
* @license.agreement Gnu General Public License 3.0
*/

public class Patron{

    
    private String name;
    private String email;
    /**
    * Patron constructor.
    *@param name the name of patron
    *@param email the email of patron
    * @since 1.0
    */
    public Patron(String name, String email){
        this.name = name;
        this.email = email;
    }
    public Patron(BufferedReader br) throws IOException  {
        this.name = br.readLine();
        System.out.println("Loading " + this.name + "...");
        this.email = br.readLine();
        System.out.println("Loading " + this.email + "...");
    }
    public void save(BufferedWriter bw) {
        try {
            bw.write(this.name);
            bw.newLine();
            bw.write(this.email);
            bw.newLine();
        } catch (IOException e) {
            System.err.println("Error writing to file.");
        }
    }

    @Override
    public String toString(){
        return "Patron >" + name + "< (" + email + ")";
    }
}