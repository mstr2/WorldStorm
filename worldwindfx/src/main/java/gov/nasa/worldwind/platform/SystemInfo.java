package gov.nasa.worldwind.platform;

public class SystemInfo {

    private final long totalMemory;

    SystemInfo(long totalMemory) {
        this.totalMemory = totalMemory;
    }

    public long getTotalMemory() {
        return totalMemory;
    }

}
