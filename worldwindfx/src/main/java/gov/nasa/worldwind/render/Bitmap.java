package gov.nasa.worldwind.render;

public class Bitmap {

    public enum Format {
        ARGB_8888,
        ARGB_4444,
        RGB_565
    }

    private final int width;
    private final int height;
    private final Format format;
    private byte[] data;

    public Bitmap(int width, int height, Format format, byte[] data)
    {
        this.width = width;
        this.height = height;
        this.format = format;
        this.data = data;
    }

    public static Bitmap createBitmap(int width, int height, Format format) {
        return new Bitmap(width, height, format, null);
    }

    public boolean isRecycled() {
        return false;
    }

    public int getInternalFormat() {
        return 0;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public Format getFormat() {
        return format;
    }

    public int getByteCount() {
        return data != null ? data.length : 0;
    }

    public void setPixels(int[] pixels, int offset, int stride, int x, int y, int width, int height) {
        if (format == Format.ARGB_8888) {
            for (int i = offset; i < offset + stride * height; ++i) {

            }
        }
    }

}
