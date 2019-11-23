package gov.nasa.worldwind;

public class DoubleUtil {

    public static boolean areClose(double value1, double value2)
    {
        if(value1 == value2) return true;
        double eps = (Math.abs(value1) + Math.abs(value2) + 10.0) * 2.2204460492503131e-016;
        double delta = value1 - value2;
        return(-eps < delta) && (eps > delta);
    }

}
