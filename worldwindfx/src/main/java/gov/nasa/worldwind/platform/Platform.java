package gov.nasa.worldwind.platform;

import gov.nasa.worldwind.platform.data.SQLiteDatabase;

public final class Platform {

    private static final PlatformImpl platformImpl = initializePlatform();

    public static GLES20 getGL() {
        return platformImpl.getGL();
    }

    public static EGL14 getEGL() {
        return platformImpl.getEGL();
    }

    public static SystemInfo getSystemInfo() {
        return platformImpl.getSystemInfo();
    }

    public static SQLiteDatabase openDatabase(String pathName, Object o, int flags) {
        return platformImpl.openDatabase(pathName, o, flags);
    }

    private static PlatformImpl initializePlatform() {
        try {
            String os = System.getProperty("os.name").toLowerCase();
            if (os.contains("win")) {
                Class<?> platformClass = Class.forName("gov.nasa.worldwind.platform.WinPlatform");
                return (PlatformImpl) platformClass.getConstructor().newInstance();
            } else {
                throw new RuntimeException("Unsupported operating system.");
            }
        } catch (ClassNotFoundException | NoSuchMethodException ex) {
            throw new RuntimeException("No suitable platform implementation found.");
        } catch (ReflectiveOperationException ex) {
            throw new RuntimeException("Error initializing platform implementation.", ex);
        }
    }
}
