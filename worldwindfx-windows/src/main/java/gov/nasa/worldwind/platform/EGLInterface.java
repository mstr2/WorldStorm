package gov.nasa.worldwind.platform;

@SuppressWarnings("unused")
public final class EGLInterface implements EGL {

    @Override
    public native boolean eglBindAPI(int api);

    @Override
    public native boolean eglTexImage(long display, long surface, int buffer);

    @Override
    public native boolean eglChooseConfig(long display, int[] attribs, long[] configs, int[] numConfigs);

    @Override
    public native long eglGetDisplay(long display);

    @Override
    public native boolean eglInitialize(long display, int[] major, int[] minor);

    @Override
    public native long eglCreateWindowSurface(long display, long config, long windowHandle, int[] attribs);

    @Override
    public native long eglCreatePbufferSurface(long display, long config, int[] attribs);

    @Override
    public native long eglCreateContext(long display, long config, long shareContext, int[] attribs);

    @Override
    public native boolean eglMakeCurrent(long display, long draw, long read, long context);

}
