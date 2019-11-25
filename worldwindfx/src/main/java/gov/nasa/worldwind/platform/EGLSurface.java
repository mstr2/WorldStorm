package gov.nasa.worldwind.platform;

public class EGLSurface extends EGLObjectHandle {
    private EGLSurface(long handle) {
        super(handle);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof EGLSurface)) return false;
        EGLSurface that = (EGLSurface) o;
        return getNativeHandle() == that.getNativeHandle();
    }
}
