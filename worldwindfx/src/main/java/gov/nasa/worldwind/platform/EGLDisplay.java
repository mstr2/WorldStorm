package gov.nasa.worldwind.platform;

public class EGLDisplay extends EGLObjectHandle {
    private EGLDisplay(long handle) {
        super(handle);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof EGLDisplay)) return false;
        EGLDisplay that = (EGLDisplay) o;
        return getNativeHandle() == that.getNativeHandle();
    }
}