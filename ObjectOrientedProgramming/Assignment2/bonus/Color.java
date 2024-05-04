public enum Color {
    EBONY(0x5D675B),       
    FLAX(0xF7EF99),
    BUFF(0xF1BB87),
    CORAL(0xF78E69);
    
    //Add a private int field named rgb representing the Red-Green-Blue integer 
    //that matches the enumerated color name
    private int rgb;
     
    //add a private constructor that accepts an int with which to initialize rgb.
    private Color(int rgb) {
        this.rgb = rgb;
    }

    //Finally, modify the toString() method to include the RGB color as part of the color representation.
    @Override
    public String toString() {
        return this.name() + "  " + String.format("(0x%06X)", rgb);
    }
}