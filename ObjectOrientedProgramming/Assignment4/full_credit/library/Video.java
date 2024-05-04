package library;
import java.time.Duration;

/**
* A library video that can be checked out by a patron.
*
* @author Tien Dung Le
* @version 1.0
* @since 1.0
* @license.agreement Gnu General Public License 3.0
*/
public class Video extends Publication {
    
    private Duration runtime;

    /**
    * Video constructor.
    *
    * @param title the title of video
    * @param author the author of video
    * @param copyright the year of video
    * @param runtime the length of video

    * @since 1.0
    */
    public Video(String title, String author, int copyright, int runtime) {
        super(title, author, copyright);
        if (runtime <= 0) {
            throw new InvalidRuntimeException(title, Integer.toString(runtime));
        }
        this.runtime = Duration.ofMinutes(runtime);
    }

    @Override
    public String toString() {
        return super.toString() + ", " + this.runtime.toMinutes() + " minutes long";
    }
}
