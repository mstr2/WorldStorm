package gov.nasa.worldwind.platform;

import gov.nasa.worldwind.platform.data.SQLiteDatabase;

public class WinPlatform implements PlatformImpl {

    private final GLES20Impl gl = new GLES20Impl();
    private final EGL14 egl = new EGL14Impl();

    @Override
    public GLES20 getGL() {
        return gl;
    }

    @Override
    public EGL14 getEGL() {
        return egl;
    }

    @Override
    public SystemInfo getSystemInfo() {
        // TODO
        return null;
    }

    @Override
    public SQLiteDatabase openDatabase(String pathName, Object o, int flags) {
        // TODO
        return null;
    }
}
