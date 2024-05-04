package library;

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

    @Override
    public String toString(){
        return "Patron >" + name + "< (" + email + ")";
    }
}