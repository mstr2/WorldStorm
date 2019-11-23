package gov.nasa.worldwind.platform;

import gov.nasa.worldwind.platform.data.SQLiteDatabase;

public class WinPlatform implements PlatformImpl {

    static {
        System.load("worldwindFX-windows-native");
    }

    private final GLInterface gl = new GLInterface();
    private final EGLInterface egl = new EGLInterface();

    @Override
    public GL getGL() {
        return gl;
    }

    @Override
    public EGLInterface getEGL() {
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
