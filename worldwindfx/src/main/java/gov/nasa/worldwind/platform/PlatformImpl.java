package gov.nasa.worldwind.platform;

import gov.nasa.worldwind.platform.data.SQLiteDatabase;

interface PlatformImpl {

    GL getGL();

    EGL getEGL();

    SystemInfo getSystemInfo();

    SQLiteDatabase openDatabase(String pathName, Object o, int flags);

}
