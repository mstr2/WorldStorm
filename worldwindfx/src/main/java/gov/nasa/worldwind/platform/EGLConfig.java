package gov.nasa.worldwind.platform;

public class EGLConfig extends EGLObjectHandle {
    private EGLConfig(long handle) {
        super(handle);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof EGLConfig)) return false;
        EGLConfig that = (EGLConfig) o;
        return getNativeHandle() == that.getNativeHandle();
    }
}
