package library;
import java.lang.ArithmeticException;
/**
* Invalid runtime exception
*
* @author Tien Dung Le
* @version 1.0
* @since 1.0
* @license.agreement Gnu General Public License 3.0
*/
public class InvalidRuntimeException extends ArithmeticException {
    /**
    * Creates an Invalid Runtime Exception instance.
    * @since 1.0
    */
    public InvalidRuntimeException() {
        super();
    }
    /**
    * Creates an Invalid Runtime Exception instance.
    *
    * @param message the name of the exception
    * @since 1.0
    */
    public InvalidRuntimeException(String message) {
        super(message);
    }
    /**
    * Creates a Library instance.
    *
    * @param title the title of the video
    * @param runtime the video duration of the video
    * @since 1.0
    */
    public InvalidRuntimeException(String title, String runtime) {
        super(title + " has invalid runtime of " + runtime+ " minutes. Runtime should be more than 0 minutes.");
    }
}
