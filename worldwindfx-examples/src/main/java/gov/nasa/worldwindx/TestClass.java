package gov.nasa.worldwindx;

import gov.nasa.worldwind.platform.EGL;
import gov.nasa.worldwind.platform.EGL14;
import gov.nasa.worldwind.platform.GLES20;
import gov.nasa.worldwind.platform.Platform;

public class TestClass {

    public static void main(String[] args) {
        GLES20 gl = Platform.getGL();
        EGL14 egl = Platform.getEGL();

        long display = egl.eglGetDisplay(EGL.EGL_DEFAULT_DISPLAY);
        if (display == EGL.EGL_NO_DISPLAY) {
            throw new RuntimeException("EGL_NO_DISPLAY");
        }

        int[] version = new int[2];
        if (!egl.eglInitialize(display, version, 0, version, 1)) {
            throw new RuntimeException(egl.eglGetErrorString(egl.eglGetError()));
        }

        long[] configs = new long[1];
        int[] numConfigs = new int[1];
        int[] configAttribs = new int[] {
                EGL.EGL_SURFACE_TYPE, EGL.EGL_WINDOW_BIT,
                EGL.EGL_RENDERABLE_TYPE, EGL.EGL_OPENGL_ES2_BIT,
                EGL.EGL_SAMPLES, 1,
                EGL.EGL_SAMPLE_BUFFERS, 4,
                EGL.EGL_BUFFER_SIZE, 32,
                EGL.EGL_DEPTH_SIZE, 24,
                EGL.EGL_STENCIL_SIZE, 8,
                EGL.EGL_NONE
        };

        if (!egl.eglChooseConfig(display, configAttribs, 0, configs, 0, configs.length, numConfigs, 0)) {
            throw new RuntimeException(egl.eglGetErrorString(egl.eglGetError()));
        }

        //long windowHandle = WindowHelper.getPeer(getScene().getWindow()).getRawHandle();
        //long surface = egl.eglCreateWindowSurface(display, configs[0], windowHandle, null);

        int[] surfaceAttribs = new int[] {
                EGL.EGL_WIDTH, 1920,
                EGL.EGL_HEIGHT, 1080,
                EGL.EGL_NONE,
        };

        egl.eglCreatePbufferSurface(display, configs[0], surfaceAttribs, 0);
        int[] contextAttribs = new int[] {
                EGL.EGL_CONTEXT_CLIENT_VERSION, 2,
                EGL.EGL_NONE
        };

        long context = egl.eglCreateContext(display, configs[0], EGL.EGL_NO_CONTEXT, contextAttribs, 0);

        egl.eglBindAPI(EGL.EGL_OPENGL_ES_API);
        //egl.eglMakeCurrent(display, surface, surface, context);
    }

}
