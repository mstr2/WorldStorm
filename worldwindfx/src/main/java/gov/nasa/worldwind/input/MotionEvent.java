package gov.nasa.worldwind.input;

public class MotionEvent extends InputEvent {

    public static final int ACTION_DOWN = 0;

    public static final int ACTION_UP = 1;

    public static final int ACTION_MOVE = 2;

    public static final int ACTION_CANCEL = 3;

    public static final int ACTION_POINTER_DOWN = 5;

    public static final int ACTION_POINTER_UP = 6;

    private final int[] id;
    private final int[] x;
    private final int[] y;

    public MotionEvent(int[] id, int[] x, int[] y) {
        if (id.length != x.length || id.length != y.length) {
            throw new IllegalArgumentException("Arrays must be of same size.");
        }

        this.id = id;
        this.x = x;
        this.y = y;
    }

    public MotionEvent(MotionEvent other) {
        this.id = other.id.clone();
        this.x = other.x.clone();
        this.y = other.y.clone();
    }

    public int getActionMasked() {
        // TODO
        return 0;
    }

    public int getActionIndex() {
        // TODO
        return 0;
    }

    public int getX(int pointerIndex) {
        return x[pointerIndex];
    }

    public int getY(int pointerIndex) {
        return y[pointerIndex];
    }

    public int getPointerCount() {
        return id.length;
    }

    public int getPointerId(int pointerIndex) {
        return id[pointerIndex];
    }

    public int findPointerIndex(int pointerId) {
        for (int i = 0; i < id.length; ++i) {
            if (id[i] == pointerId) {
                return i;
            }
        }

        return -1;
    }

    public void recycle() {

    }

}
