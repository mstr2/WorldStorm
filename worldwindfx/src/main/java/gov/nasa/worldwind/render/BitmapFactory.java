package gov.nasa.worldwind.render;

import com.sun.javafx.tk.ImageLoader;
import com.sun.javafx.tk.PlatformImage;
import com.sun.javafx.tk.Toolkit;
import javafx.scene.image.WritablePixelFormat;

import java.io.InputStream;
import java.nio.ByteBuffer;
import java.util.ResourceBundle;

public class BitmapFactory {

    public static class Options {
        public Options() {
            inPremultiplied = true;
        }

        public Bitmap inBitmap;

        public Bitmap.Format inPreferredFormat = Bitmap.Format.ARGB_8888;

        public boolean inPremultiplied;

        public boolean inScaled;

        public int outWidth;

        public int outHeight;

        public Bitmap.Format outConfig;
    }

    public static Bitmap decodeFile(String pathName) {
        return decodeFile(pathName, null);
    }

    @SuppressWarnings("SwitchStatementWithTooFewBranches")
    public static Bitmap decodeFile(String pathName, Options opts) {
        Bitmap.Format format;
        WritablePixelFormat<ByteBuffer> pixelFormat;

        if (opts != null) {
            switch (opts.inPreferredFormat) {
                case ARGB_8888:
                    format = Bitmap.Format.ARGB_8888;
                    pixelFormat = opts.inPremultiplied ?
                            WritablePixelFormat.getByteBgraPreInstance() : WritablePixelFormat.getByteBgraInstance();
                    break;

                default:
                    throw new UnsupportedOperationException("Unsupported bitmap format.");
            }
        } else {
            format = Bitmap.Format.ARGB_8888;
            pixelFormat = WritablePixelFormat.getByteBgraPreInstance();
        }

        ImageLoader loader = Toolkit.getToolkit().loadImage(pathName, 0, 0, true, false);
        PlatformImage image = loader.getFrame(0);
        int w = (int) (loader.getWidth() / image.getPixelScale());
        int h = (int) (loader.getHeight() / image.getPixelScale());
        byte[] pixels = new byte[w * h * 4];
        image.getPixels(0, 0, w, h, pixelFormat, pixels, 0, w * 4);

        return new Bitmap(w, h, format, pixels);
    }

    public static Bitmap decodeResource(ResourceBundle res, String id) {
        // TODO
        return null;
    }

    public static Bitmap decodeResource(ResourceBundle res, String id, Options opts) {
        // TODO
        return null;
    }

    public static Bitmap decodeStream(InputStream is) {
        // TODO
        return null;
    }

    public static Bitmap decodeStream(InputStream is, Rect outPadding, Options opts) {
        // TODO
        return null;
    }

    public static Bitmap decodeByteArray(
            byte[] data, int offset, int length) {
        // TODO
        return null;
    }

    public static Bitmap decodeByteArray(
            byte[] data, int offset, int length, BitmapFactory.Options opts) {
        // TODO
        return null;
    }

}
