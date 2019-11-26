#include <jni.h>
#include <EGL/egl.h>
#include "jnitools.h"

extern "C" {
	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetError
	 * Signature: ()I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetError(
		JNIEnv*, jobject)
	{
		return eglGetError();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetDisplay
	 * Signature: (I)J
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetDisplay(
		JNIEnv* env, jobject, jlong display_id)
	{
		return (jlong)eglGetDisplay((EGLNativeDisplayType)display_id);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglInitialize
	 * Signature: (J[II[II)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglInitialize(
		JNIEnv* env, jobject, jlong dpy, jintArray major, jint majorOffset, jintArray minor, jint minorOffset)
	{
		ValidateArraySize_I(major, majorOffset, 1);
		ValidateArraySize_I(minor, minorOffset, 1);		
		return eglInitialize((EGLDisplay)dpy, IntRegion<1>(env, major, majorOffset), IntRegion<1>(env, minor, minorOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglTerminate
	 * Signature: (J)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglTerminate(
		JNIEnv* env, jobject, jlong dpy)
	{
		return eglTerminate((EGLDisplay)dpy);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglQueryString
	 * Signature: (JI)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglQueryString(
		JNIEnv* env, jobject, jlong dpy, jint name)
	{
		return env->NewStringUTF(eglQueryString((EGLDisplay)dpy, name));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetConfigs
	 * Signature: (J[JII[II)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetConfigs(
		JNIEnv* env, jobject, jlong dpy, jlongArray configs, jint configsOffset, jint config_size, jintArray num_config, jint num_configOffset)
	{
		ValidateArraySize_I(configs, configsOffset, config_size);
		ValidateArraySize_I(num_config, num_configOffset, 1);
		return eglGetConfigs((EGLDisplay)dpy, (EGLConfig*)(jlong*)LongBuffer(env, configs, configsOffset), config_size, IntBuffer(env, num_config, num_configOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglChooseConfig
	 * Signature: (J[II[LIII[I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglChooseConfig(
		JNIEnv* env, jobject, jlong dpy, jintArray attrib_list, jint attrib_listOffset, jlongArray configs, jint configsOffset, jint config_size, jintArray num_config, jint num_configOffset)
	{
		ValidateArraySize_I(configs, configsOffset, config_size);
		ValidateArraySize_I(num_config, num_configOffset, 1);
		return eglChooseConfig((EGLDisplay)dpy, IntBuffer(env, attrib_list, attrib_listOffset), (EGLConfig*)(jlong*)LongBuffer(env, configs, configsOffset), config_size, IntBuffer(env, num_config, num_configOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetConfigAttrib
	 * Signature: (JJI[II)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetConfigAttrib(
		JNIEnv* env, jobject, jlong dpy, jlong config, jint attribute, jintArray value, jint valueOffset)
	{
		ValidateArraySize_I(value, valueOffset, 1);
		return eglGetConfigAttrib((EGLDisplay)dpy, (EGLConfig)config, attribute, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglCreateWindowSurface
	 * Signature: (JJJ[II)Ljava/lang/Object;
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglCreateWindowSurface(
		JNIEnv* env, jobject, jlong dpy, jlong config, jlong win, jintArray attrib_list, jint attrib_listOffset)
	{
		return (jlong)eglCreateWindowSurface((EGLDisplay)dpy, (EGLConfig)config, (EGLNativeWindowType)win, IntBuffer(env, attrib_list, attrib_listOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglCreatePbufferSurface
	 * Signature: (JJ[II)L;
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglCreatePbufferSurface(
		JNIEnv* env, jobject, jlong dpy, jlong config, jintArray attrib_list, jint attrib_listOffset)
	{
		return (jlong)eglCreatePbufferSurface((EGLDisplay)dpy, (EGLConfig)config, IntBuffer(env, attrib_list, attrib_listOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglDestroySurface
	 * Signature: (JJ)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglDestroySurface(
		JNIEnv*, jobject, jlong dpy, jlong surface)
	{
		return eglDestroySurface((EGLDisplay)dpy, (EGLSurface)surface);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglQuerySurface
	 * Signature: (JJI[II)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglQuerySurface(
		JNIEnv* env, jobject, jlong dpy, jlong surface, jint attribute, jintArray value, jint valueOffset)
	{
		ValidateArraySize_I(value, valueOffset, 1);
		return eglQuerySurface((EGLDisplay)dpy, (EGLSurface)surface, attribute, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglBindAPI
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglBindAPI(
		JNIEnv*, jobject, jint api)
	{
		return eglBindAPI(api);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglQueryAPI
	 * Signature: ()I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglQueryAPI(
		JNIEnv*, jobject)
	{
		return eglQueryAPI();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglWaitClient
	 * Signature: ()Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglWaitClient(
		JNIEnv*, jobject)
	{
		return eglWaitClient();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglReleaseThread
	 * Signature: ()Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglReleaseThread(
		JNIEnv*, jobject)
	{
		return eglReleaseThread();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglSurfaceAttrib
	 * Signature: (JJII)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglSurfaceAttrib(
		JNIEnv*, jobject, jlong dpy, jlong surface, jint attribute, jint value)
	{
		return eglSurfaceAttrib((EGLDisplay)dpy, (EGLSurface)surface, attribute, value);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglBindTexImage
	 * Signature: (JJI)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglBindTexImage(
		JNIEnv*, jobject, jlong dpy, jlong surface, jint buffer)
	{
		return eglBindTexImage((EGLDisplay)dpy, (EGLSurface)surface, buffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglReleaseTexImage
	 * Signature: (JJI)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglReleaseTexImage(
		JNIEnv*, jobject, jlong dpy, jlong surface, jint buffer)
	{
		return eglReleaseTexImage((EGLDisplay)dpy, (EGLSurface)surface, buffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglSwapInterval
	 * Signature: (JI)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglSwapInterval(
		JNIEnv*, jobject, jlong dpy, jint interval)
	{
		return eglSwapInterval((EGLDisplay)dpy, interval);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglCreateContext
	 * Signature: (JJJ[II)J
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglCreateContext(
		JNIEnv* env, jobject, jlong dpy, jlong config, jlong share_context, jintArray attrib_list, jint attrib_listOffset)
	{
		return (jlong)eglCreateContext((EGLDisplay)dpy, (EGLConfig)config, (EGLContext)share_context, IntBuffer(env, attrib_list, attrib_listOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglDestroyContext
	 * Signature: (JJ)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglDestroyContext(
		JNIEnv*, jobject, jlong dpy, jlong ctx)
	{
		return eglDestroyContext((EGLDisplay)dpy, (EGLContext)ctx);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglMakeCurrent
	 * Signature: (Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglMakeCurrent(
		JNIEnv*, jobject, jlong dpy, jlong draw, jlong read, jlong ctx)
	{
		return eglMakeCurrent((EGLDisplay)dpy, (EGLSurface)draw, (EGLSurface)read, (EGLContext)ctx);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetCurrentContext
	 * Signature: ()J;
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetCurrentContext(
		JNIEnv*, jobject)
	{
		return (jlong)eglGetCurrentContext();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetCurrentSurface
	 * Signature: (I)J
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetCurrentSurface(
		JNIEnv*, jobject, jint readdraw)
	{
		return (jlong)eglGetCurrentSurface(readdraw);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglGetCurrentDisplay
	 * Signature: ()J
	 */
	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglGetCurrentDisplay(
		JNIEnv*, jobject)
	{
		return (jlong)eglGetCurrentDisplay();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglQueryContext
	 * Signature: (JJI[II)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglQueryContext(
		JNIEnv* env, jobject, jlong dpy, jlong ctx, jint attribute, jintArray value, jint valueOffset)
	{
		ValidateArraySize_I(value, valueOffset, 1);
		return eglQueryContext((EGLDisplay)dpy, (EGLContext)ctx, attribute, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglWaitGL
	 * Signature: ()Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglWaitGL(
		JNIEnv*, jobject)
	{
		return eglWaitGL();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglWaitNative
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglWaitNative(
		JNIEnv*, jobject, jint engine)
	{
		return eglWaitNative(engine);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglSwapBuffers
	 * Signature: (JJ)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglSwapBuffers(
		JNIEnv*, jobject, jlong dpy, jlong surface)
	{
		return eglSwapBuffers((EGLDisplay)dpy, (EGLSurface)surface);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_EGL14Impl
	 * Method:    eglCopyBuffers
	 * Signature: (JJI)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_EGL14Impl_eglCopyBuffers(
		JNIEnv*, jobject, jlong dpy, jlong surface, jlong target)
	{
		return eglCopyBuffers((EGLDisplay)dpy, (EGLSurface)surface, (EGLNativePixmapType)target);
	}
}
