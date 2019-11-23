package gov.nasa.worldwind.platform.data;

import java.io.Closeable;

public interface SQLiteDatabase extends Closeable {

    int OPEN_READONLY = 0;

    Cursor rawQuery(String sql, String[] selectionArgs);

    void acquireReference();

    boolean isOpen();

}
