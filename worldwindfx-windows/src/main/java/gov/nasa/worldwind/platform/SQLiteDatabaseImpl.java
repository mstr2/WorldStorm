package gov.nasa.worldwind.platform;

import gov.nasa.worldwind.platform.data.Cursor;
import gov.nasa.worldwind.platform.data.SQLiteDatabase;

import java.io.IOException;

public class SQLiteDatabaseImpl implements SQLiteDatabase {

    @Override
    public Cursor rawQuery(String sql, String[] selectionArgs) {
        return null;
    }

    @Override
    public void acquireReference() {
    }

    @Override
    public boolean isOpen() {
        return false;
    }

    @Override
    public void close() throws IOException {
    }

}
