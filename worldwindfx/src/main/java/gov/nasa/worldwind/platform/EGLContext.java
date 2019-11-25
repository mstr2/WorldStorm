package gov.nasa.worldwind.platform;

public class EGLContext extends EGLObjectHandle {
    private EGLContext(long handle) {
        super(handle);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof EGLContext)) return false;
        EGLContext that = (EGLContext) o;
        return getNativeHandle() == that.getNativeHandle();
    }
}
