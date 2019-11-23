package gov.nasa.worldwind.platform.data;

import java.io.Closeable;

public interface Cursor extends Closeable {

    int getColumnIndex(String columnName);

    boolean moveToNext();

    String getString(int columnIndex);

    short getShort(int columnIndex);

    int getInt(int columnIndex);

    long getLong(int columnIndex);

    float getFloat(int columnIndex);

    double getDouble(int columnIndex);

    int getCount();

    byte[] getBlob(int columnIndex);

}
