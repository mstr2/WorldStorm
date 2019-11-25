package gov.nasa.worldwind.platform;

abstract class EGLObjectHandle {
    private final long mHandle;

    protected EGLObjectHandle(long handle) {
        mHandle = handle;
    }

    public long getNativeHandle() {
        return mHandle;
    }

    @Override
    public int hashCode() {
        int result = 17;
        result = 31 * result + (int) (mHandle ^ (mHandle >>> 32));
        return result;
    }
}
