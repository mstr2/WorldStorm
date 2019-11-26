package gov.nasa.worldwind.platform;

import gov.nasa.worldwind.platform.data.SQLiteDatabase;

interface PlatformImpl {

    GLES20 getGL();

    EGL14 getEGL();

    SystemInfo getSystemInfo();

    SQLiteDatabase openDatabase(String pathName, Object o, int flags);

}
