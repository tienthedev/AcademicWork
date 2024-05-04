
public class Line{
    // 5 Private Fields
    private double x1;
    private double y1;
    private double x2;
    private double y2;
    private Color color;

    // 1 Public Constructor
    public Line(double x1, double y1, double x2, double y2, Color color){
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.color = color;
    }

    // 2 Public Methods
    public double length(){
        return Math.sqrt(Math.pow(x1-x2,2) + Math.pow(y1-y2,2));
    }

    @Override
    public String toString() {
        return String.format("%7s (%5.3f, %5.3f) - (%5.3f, %5.3f)", color.name(), x1, y1, x2, y2);
}



    
}



