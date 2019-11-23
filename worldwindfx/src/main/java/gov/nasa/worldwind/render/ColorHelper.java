package gov.nasa.worldwind.render;

class ColorHelper {

    static int alpha(int color) {
        return color >>> 24;
    }

    static int red(int color) {
        return (color >> 16) & 0xFF;
    }

    static int green(int color) {
        return (color >> 8) & 0xFF;
    }

    static int blue(int color) {
        return color & 0xFF;
    }

    static int rgb(int red, int green, int blue) {
        return (0xFF << 24) | (red << 16) | (green << 8) | blue;
    }

    static int argb(int alpha, int red, int green, int blue) {
        return (alpha << 24) | (red << 16) | (green << 8) | blue;
    }

}
