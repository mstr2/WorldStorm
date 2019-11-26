package gov.nasa.worldwind.platform;

public class EGL14Impl implements EGL14 {
    @Override
    public String eglGetErrorString(int error) {
        switch (error) {
            case EGL_SUCCESS:
                return "EGL_SUCCESS";
            case EGL_NOT_INITIALIZED:
                return "EGL_NOT_INITIALIZED";
            case EGL_BAD_ACCESS:
                return "EGL_BAD_ACCESS";
            case EGL_BAD_ALLOC:
                return "EGL_BAD_ALLOC";
            case EGL_BAD_ATTRIBUTE:
                return "EGL_BAD_ATTRIBUTE";
            case EGL_BAD_CONTEXT:
                return "EGL_BAD_CONTEXT";
            case EGL_BAD_CONFIG:
                return "EGL_BAD_CONFIG";
            case EGL_BAD_CURRENT_SURFACE:
                return "EGL_BAD_CURRENT_SURFACE";
            case EGL_BAD_DISPLAY:
                return "EGL_BAD_DISPLAY";
            case EGL_BAD_SURFACE:
                return "EGL_BAD_SURFACE";
            case EGL_BAD_MATCH:
                return "EGL_BAD_MATCH";
            case EGL_BAD_PARAMETER:
                return "EGL_BAD_PARAMETER";
            case EGL_BAD_NATIVE_PIXMAP:
                return "EGL_BAD_NATIVE_PIXMAP";
            case EGL_BAD_NATIVE_WINDOW:
                return "EGL_BAD_NATIVE_WINDOW";
            case EGL_CONTEXT_LOST:
                return "EGL_CONTEXT_LOST";
            default:
                return Integer.toHexString(error);
        }
    }

    @Override
    public native int eglGetError();

    @Override
    public native long eglGetDisplay(long display_id);

    @Override
    public native boolean eglInitialize(
            long dpy, int[] major, int majorOffset, int[] minor, int minorOffset);

    @Override
    public native boolean eglTerminate(long dpy);

    @Override
    public native String eglQueryString(long dpy, int name);

    @Override
    public native boolean eglGetConfigs(
            long dpy,
            long[] configs,
            int configsOffset,
            int config_size,
            int[] num_config,
            int num_configOffset);

    @Override
    public native boolean eglChooseConfig(
            long dpy,
            int[] attrib_list,
            int attrib_listOffset,
            long[] configs,
            int configsOffset,
            int config_size,
            int[] num_config,
            int num_configOffset);

    @Override
    public native boolean eglGetConfigAttrib(
            long dpy, long config, int attribute, int[] value, int offset);

    @Override
    public native long eglCreateWindowSurface(
            long dpy, long config, long win, int[] attrib_list, int offset);

    @Override
    public native long eglCreatePbufferSurface(
            long dpy, long config, int[] attrib_list, int offset);

    @Override
    public native boolean eglDestroySurface(long dpy, long surface);

    @Override
    public native boolean eglQuerySurface(
            long dpy, long surface, int attribute, int[] value, int offset);

    @Override
    public native boolean eglBindAPI(int api);

    @Override
    public native int eglQueryAPI();

    @Override
    public native boolean eglWaitClient();

    @Override
    public native boolean eglReleaseThread();

    @Override
    public native boolean eglSurfaceAttrib(long dpy, long surface, int attribute, int value);

    @Override
    public native boolean eglBindTexImage(long dpy, long surface, int buffer);

    @Override
    public native boolean eglReleaseTexImage(long dpy, long surface, int buffer);

    @Override
    public native boolean eglSwapInterval(long dpy, int interval);

    @Override
    public native long eglCreateContext(
            long dpy, long config, long share_context, int[] attrib_list, int offset);

    @Override
    public native boolean eglDestroyContext(long dpy, long ctx);

    @Override
    public native boolean eglMakeCurrent(long dpy, long draw, long read, long ctx);

    @Override
    public native long eglGetCurrentContext();

    @Override
    public native long eglGetCurrentSurface(int readdraw);

    @Override
    public native long eglGetCurrentDisplay();

    @Override
    public native boolean eglQueryContext(
            long dpy, long ctx, int attribute, int[] value, int offset);

    @Override
    public native boolean eglWaitGL();

    @Override
    public native boolean eglWaitNative(int engine);

    @Override
    public native boolean eglSwapBuffers(long dpy, long surface);

    @Override
    public native boolean eglCopyBuffers(long dpy, long surface, long target);
}
