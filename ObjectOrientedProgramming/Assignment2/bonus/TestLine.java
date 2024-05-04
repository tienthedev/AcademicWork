public class TestLine {
    public static void main(String[] args) {
        //Create 4 lines with different coordinates and colors

        Line line1 = new Line(1.574, 2.012, 3.742, 4.267, Color.EBONY);
        Line line2 = new Line(1.123, 0.563, 5.392, 2.712, Color.FLAX);
        Line line3 = new Line(2.856, 3.212, 2.156, 5.941, Color.BUFF);
        Line line4 = new Line(0.522, 0.456, 7.975, 8.451, Color.CORAL);

        Line[] lines = { line1, line2, line3, line4 };
        //Print the length of each line
        for (Line line : lines) {
            System.out.println(line + " has length " + line.length());
        }
    }
}