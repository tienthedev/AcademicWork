package library;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
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
    public Video(BufferedReader br) throws IOException {
        // Call the superclass's constructor to initialize inherited fields
        super(br);
        // Read the runtime as minutes (assuming runtime is a Duration object)
        int runtime = Integer.parseInt(br.readLine());
        this.runtime = Duration.ofMinutes(runtime);
        
    }
    public void save(BufferedWriter bw) {
        try {
            // Call the superclass's save method to write inherited fields
            super.save(bw);
            // Write the runtime as minutes (assuming runtime is a Duration object)
            bw.write(this.runtime.toMinutes() + "");
            bw.newLine();
        } catch (Exception e) {
            System.err.println("Error writing to file.");
        }
    }
    
    @Override
    public String toString() {
        return super.toString() + ", " + this.runtime.toMinutes() + " minutes long";
    }
}
