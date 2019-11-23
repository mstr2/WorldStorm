package gov.nasa.worldwind.platform;

@SuppressWarnings("unused")
public interface EGL {

    long EGL_DEFAULT_DISPLAY = 0;

    // EGL version 1.0
    int EGL_ALPHA_SIZE = 0x3021;
    int EGL_BAD_ACCESS = 0x3002;
    int EGL_BAD_ALLOC = 0x3003;
    int EGL_BAD_ATTRIBUTE = 0x3004;
    int EGL_BAD_CONFIG = 0x3005;
    int EGL_BAD_CONTEXT = 0x3006;
    int EGL_BAD_CURRENT_SURFACE = 0x3007;
    int EGL_BAD_DISPLAY = 0x3008;
    int EGL_BAD_MATCH = 0x3009;
    int EGL_BAD_NATIVE_PIXMAP = 0x300A;
    int EGL_BAD_NATIVE_WINDOW = 0x300B;
    int EGL_BAD_PARAMETER = 0x300C;
    int EGL_BAD_SURFACE = 0x300D;
    int EGL_BLUE_SIZE = 0x3022;
    int EGL_BUFFER_SIZE = 0x3020;
    int EGL_CONFIG_CAVEAT = 0x3027;
    int EGL_CONFIG_ID = 0x3028;
    int EGL_CORE_NATIVE_ENGINE = 0x305B;
    int EGL_DEPTH_SIZE = 0x3025;
    int EGL_DRAW = 0x3059;
    int EGL_EXTENSIONS = 0x3055;
    int EGL_FALSE = 0;
    int EGL_GREEN_SIZE = 0x3023;
    int EGL_HEIGHT = 0x3056;
    int EGL_LARGEST_PBUFFER = 0x3058;
    int EGL_LEVEL = 0x3029;
    int EGL_MAX_PBUFFER_HEIGHT = 0x302A;
    int EGL_MAX_PBUFFER_PIXELS = 0x302B;
    int EGL_MAX_PBUFFER_WIDTH = 0x302C;
    int EGL_NATIVE_RENDERABLE = 0x302D;
    int EGL_NATIVE_VISUAL_ID = 0x302E;
    int EGL_NATIVE_VISUAL_TYPE = 0x302F;
    int EGL_NONE = 0x3038;
    int EGL_NON_CONFORMANT_CONFIG = 0x3051;
    int EGL_NOT_INITIALIZED = 0x3001;
    int EGL_NO_CONTEXT = 0;
    int EGL_NO_DISPLAY = 0;
    int EGL_NO_SURFACE = 0;
    int EGL_PBUFFER_BIT = 0x0001;
    int EGL_PIXMAP_BIT = 0x0002;
    int EGL_READ = 0x305A;
    int EGL_RED_SIZE = 0x3024;
    int EGL_SAMPLES = 0x3031;
    int EGL_SAMPLE_BUFFERS = 0x3032;
    int EGL_SLOW_CONFIG = 0x3050;
    int EGL_STENCIL_SIZE = 0x3026;
    int EGL_SUCCESS = 0x3000;
    int EGL_SURFACE_TYPE = 0x3033;
    int EGL_TRANSPARENT_BLUE_VALUE = 0x3035;
    int EGL_TRANSPARENT_GREEN_VALUE = 0x3036;
    int EGL_TRANSPARENT_RED_VALUE = 0x3037;
    int EGL_TRANSPARENT_RGB = 0x3052;
    int EGL_TRANSPARENT_TYPE = 0x3034;
    int EGL_TRUE = 1;
    int EGL_VENDOR = 0x3053;
    int EGL_VERSION = 0x3054;
    int EGL_WIDTH = 0x3057;
    int EGL_WINDOW_BIT = 0x0004;

    // EGL version 1.1
    int EGL_BACK_BUFFER = 0x3084;
    int EGL_BIND_TO_TEXTURE_RGB = 0x3039;
    int EGL_BIND_TO_TEXTURE_RGBA = 0x303A;
    int EGL_CONTEXT_LOST = 0x300E;
    int EGL_MIN_SWAP_INTERVAL = 0x303B;
    int EGL_MAX_SWAP_INTERVAL = 0x303C;
    int EGL_MIPMAP_TEXTURE = 0x3082;
    int EGL_MIPMAP_LEVEL = 0x3083;
    int EGL_NO_TEXTURE = 0x305C;
    int EGL_TEXTURE_2D = 0x305F;
    int EGL_TEXTURE_FORMAT = 0x3080;
    int EGL_TEXTURE_RGB = 0x305D;
    int EGL_TEXTURE_RGBA = 0x305E;
    int EGL_TEXTURE_TARGET = 0x3081;

    // EGL version 1.2
    int EGL_ALPHA_FORMAT = 0x3088;
    int EGL_ALPHA_FORMAT_NONPRE = 0x308B;
    int EGL_ALPHA_FORMAT_PRE = 0x308C;
    int EGL_ALPHA_MASK_SIZE = 0x303E;
    int EGL_BUFFER_PRESERVED = 0x3094;
    int EGL_BUFFER_DESTROYED = 0x3095;
    int EGL_CLIENT_APIS = 0x308D;
    int EGL_COLORSPACE = 0x3087;
    int EGL_COLORSPACE_sRGB = 0x3089;
    int EGL_COLORSPACE_LINEAR = 0x308A;
    int EGL_COLOR_BUFFER_TYPE = 0x303F;
    int EGL_CONTEXT_CLIENT_TYPE = 0x3097;
    int EGL_DISPLAY_SCALING = 10000;
    int EGL_HORIZONTAL_RESOLUTION = 0x3090;
    int EGL_LUMINANCE_BUFFER = 0x308F;
    int EGL_LUMINANCE_SIZE = 0x303D;
    int EGL_OPENGL_ES_BIT = 0x0001;
    int EGL_OPENVG_BIT = 0x0002;
    int EGL_OPENGL_ES_API = 0x30A0;
    int EGL_OPENVG_API = 0x30A1;
    int EGL_OPENVG_IMAGE = 0x3096;
    int EGL_PIXEL_ASPECT_RATIO = 0x3092;
    int EGL_RENDERABLE_TYPE = 0x3040;
    int EGL_RENDER_BUFFER = 0x3086;
    int EGL_RGB_BUFFER = 0x308E;
    int EGL_SINGLE_BUFFER = 0x3085;
    int EGL_SWAP_BEHAVIOR = 0x3093;
    int EGL_UNKNOWN = -1;
    int EGL_VERTICAL_RESOLUTION = 0x3091;

    // EGL version 1.3
    int EGL_CONFORMANT = 0x3042;
    int EGL_CONTEXT_CLIENT_VERSION = 0x3098;
    int EGL_MATCH_NATIVE_PIXMAP = 0x3041;
    int EGL_OPENGL_ES2_BIT = 0x0004;
    int EGL_VG_ALPHA_FORMAT = 0x3088;
    int EGL_VG_ALPHA_FORMAT_NONPRE = 0x308B;
    int EGL_VG_ALPHA_FORMAT_PRE = 0x308C;
    int EGL_VG_ALPHA_FORMAT_PRE_BIT = 0x0040;
    int EGL_VG_COLORSPACE = 0x3087;
    int EGL_VG_COLORSPACE_sRGB = 0x3089;
    int EGL_VG_COLORSPACE_LINEAR = 0x308A;
    int EGL_VG_COLORSPACE_LINEAR_BIT = 0x0020;

    boolean eglBindAPI(int api);

    boolean eglTexImage(long display, long surface, int buffer);

    boolean eglChooseConfig(long display, int[] attribs, long[] configs, int[] numConfigs);

    long eglGetDisplay(long display);

    boolean eglInitialize(long display, int[] major, int[] minor);

    long eglCreateWindowSurface(long display, long config, long windowHandle, int[] attribs);

    long eglCreatePbufferSurface(long display, long config, int[] attribs);

    long eglCreateContext(long display, long config, long shareContext, int[] attribs);

    boolean eglMakeCurrent(long display, long draw, long read, long context);

}
