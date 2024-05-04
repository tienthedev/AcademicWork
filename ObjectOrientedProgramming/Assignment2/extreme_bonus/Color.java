public enum Color {

    EBONY("\033[38;2;93;103;91m(0x5D675B)\033[0m", 0x5D675B),   
    FLAX("\033[38;2;247;239;153m(0xF7EF99)\033[0m", 0xF7EF99),       
    BUFF("\033[38;2;241;187;135m(0xF1BB87)\033[0m", 0xF1BB87),    
    CORAL("\033[38;2;247;142;105m(0xF78E69)\033[0m", 0xF78E69);   

    private int rgb;
    private String colorAnsiEscapeCode;

    private Color(String colorAnsiEscapeCode, int rgb) {
        this.rgb = rgb;
        this.colorAnsiEscapeCode = colorAnsiEscapeCode;
    }

    @Override
    public String toString() {
        return this.name()+ " " + colorAnsiEscapeCode;
    }
}