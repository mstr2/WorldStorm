#include <jni.h>
#include <GLES2/gl2.h>
#include "jnitools.h"

extern "C" {
	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glActiveTexture
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glActiveTexture(
		JNIEnv *, jobject, jint texture)
	{
		glActiveTexture(texture);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glAttachShader
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glAttachShader(
		JNIEnv*, jobject, jint program, jint shader)
	{
		glAttachShader(program, shader);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBindAttribLocation
	 * Signature: (IILjava/lang/String;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBindAttribLocation(
		JNIEnv* env, jobject, jint program, jint index, jstring name)
	{
		glBindAttribLocation(program, index, CString(env, name));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBindBuffer
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBindBuffer(
		JNIEnv*, jobject, jint target, jint buffer)
	{
		glBindBuffer(target, buffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBindFramebuffer
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBindFramebuffer(
		JNIEnv*, jobject, jint target, jint framebuffer)
	{
		glBindFramebuffer(target, framebuffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBindRenderbuffer
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBindRenderbuffer(
		JNIEnv*, jobject, jint target, jint renderbuffer)
	{
		glBindRenderbuffer(target, renderbuffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBindTexture
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBindTexture(
		JNIEnv*, jobject, jint target, jint texture)
	{
		glBindTexture(target, texture);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBlendColor
	 * Signature: (FFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBlendColor(
		JNIEnv*, jobject, jfloat red, jfloat green, jfloat blue, jfloat alpha)
	{
		glBlendColor(red, green, blue, alpha);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBlendEquation
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBlendEquation(
		JNIEnv*, jobject, jint mode)
	{
		glBlendEquation(mode);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBlendEquationSeparate
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBlendEquationSeparate(
		JNIEnv*, jobject, jint modeRGB, jint modeAlpha)
	{
		glBlendEquationSeparate(modeRGB, modeAlpha);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBlendFunc
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBlendFunc(
		JNIEnv*, jobject, jint sfactor, jint dfactor)
	{
		glBlendFunc(sfactor, dfactor);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBlendFuncSeparate
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBlendFuncSeparate(
		JNIEnv*, jobject, jint sfactorRGB, jint dfactorRGB, jint sfactorAlpha, jint dfactorAlpha)
	{
		glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBufferData
	 * Signature: (IILjava/nio/Buffer;I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBufferData(
		JNIEnv* env, jobject, jint target, jint size, jobject data, jint usage)
	{
		glBufferData(target, size, CBuffer(env, data), usage);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBufferSubData
	 * Signature: (IIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBufferSubData(
		JNIEnv* env, jobject, jint target, jint offset, jint size, jobject data)
	{
		glBufferSubData(target, offset, size, CBuffer(env, data));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCheckFramebufferStatus
	 * Signature: (I)I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCheckFramebufferStatus(
		JNIEnv*, jobject, jint target)
	{
		return glCheckFramebufferStatus(target);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glClear
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glClear(
		JNIEnv*, jobject, jint mask)
	{
		glClear(mask);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glClearColor
	 * Signature: (FFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glClearColor(
		JNIEnv*, jobject, jfloat red, jfloat green, jfloat blue, jfloat alpha)
	{
		glClearColor(red, green, blue, alpha);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glClearDepthf
	 * Signature: (F)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glClearDepthf(
		JNIEnv*, jobject, jfloat d)
	{
		glClearDepthf(d);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glClearStencil
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glClearStencil(
		JNIEnv*, jobject, jint s)
	{
		glClearStencil(s);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glColorMask
	 * Signature: (ZZZZ)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glColorMask(
		JNIEnv*, jobject, jboolean red, jboolean green, jboolean blue, jboolean alpha)
	{
		glColorMask(red, green, blue, alpha);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCompileShader
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCompileShader(
		JNIEnv*, jobject, jint shader)
	{
		glCompileShader(shader);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCompressedTexImage2D
	 * Signature: (IIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCompressedTexImage2D
	(JNIEnv* env, jobject, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint imageSize, jobject data)
	{
		glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, CBuffer(env, data));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCompressedTexSubImage2D
	 * Signature: (IIIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCompressedTexSubImage2D(
		JNIEnv* env, jobject, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint imageSize, jobject data)
	{
		glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, CBuffer(env, data));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCopyTexImage2D
	 * Signature: (IIIIIIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCopyTexImage2D(
		JNIEnv*, jobject, jint target, jint level, jint internalformat, jint x, jint y, jint width, jint height, jint border)
	{
		glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCopyTexSubImage2D
	 * Signature: (IIIIIIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCopyTexSubImage2D(
		JNIEnv*, jobject, jint target, jint level, jint xoffset, jint yoffset, jint x, jint y, jint width, jint height)
	{
		glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCreateProgram
	 * Signature: ()I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCreateProgram(
		JNIEnv*, jobject)
	{
		return glCreateProgram();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCreateShader
	 * Signature: (I)I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCreateShader(
		JNIEnv*, jobject, jint type)
	{
		return glCreateShader(type);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCullFace
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCullFace(
		JNIEnv*, jobject, jint mode)
	{
		glCullFace(mode);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteBuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteBuffers__I_3II(
		JNIEnv* env, jobject, jint n, jintArray buffers, jint offset)
	{
		glDeleteBuffers(n, CBufferUint(env, buffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteBuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteBuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject buffers)
	{
		glDeleteBuffers(n, CBufferUint(env, buffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteFramebuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteFramebuffers__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteFramebuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteFramebuffers__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteProgram
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteRenderbuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteRenderbuffers__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteRenderbuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteRenderbuffers__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteShader
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteShader
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteTextures
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteTextures__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteTextures
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteTextures__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDepthFunc
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDepthFunc
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDepthMask
	 * Signature: (Z)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDepthMask
	  (JNIEnv *, jobject, jboolean);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDepthRangef
	 * Signature: (FF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDepthRangef
	  (JNIEnv *, jobject, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDetachShader
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDetachShader
	  (JNIEnv *, jobject, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDisable
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDisable
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDisableVertexAttribArray
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDisableVertexAttribArray
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDrawArrays
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDrawArrays
	  (JNIEnv *, jobject, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDrawElements
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDrawElements__IIII
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDrawElements
	 * Signature: (IIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDrawElements__IIILjava_nio_Buffer_2
	  (JNIEnv *, jobject, jint, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glEnable
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glEnable
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glEnableVertexAttribArray
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glEnableVertexAttribArray
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFinish
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFinish
	  (JNIEnv *, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFlush
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFlush
	  (JNIEnv *, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFramebufferRenderbuffer
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFramebufferRenderbuffer
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFramebufferTexture2D
	 * Signature: (IIIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFramebufferTexture2D
	  (JNIEnv *, jobject, jint, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFrontFace
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFrontFace
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenBuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenBuffers__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenBuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenBuffers__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenerateMipmap
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenerateMipmap
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenFramebuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenFramebuffers__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenFramebuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenFramebuffers__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenRenderbuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenRenderbuffers__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenRenderbuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenRenderbuffers__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenTextures
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenTextures__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenTextures
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenTextures__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (III[II[II[II[BI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__III_3II_3II_3II_3BI
	  (JNIEnv *, jobject, jint, jint, jint, jintArray, jint, jintArray, jint, jintArray, jint, jbyteArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (IIILjava/nio/IntBuffer;Ljava/nio/IntBuffer;Ljava/nio/IntBuffer;B)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__IIILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_IntBuffer_2B
	  (JNIEnv *, jobject, jint, jint, jint, jobject, jobject, jobject, jbyte);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (II[II[II)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__II_3II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (III[II[II[II[BI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__III_3II_3II_3II_3BI
	  (JNIEnv *, jobject, jint, jint, jint, jintArray, jint, jintArray, jint, jintArray, jint, jbyteArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (IIILjava/nio/IntBuffer;Ljava/nio/IntBuffer;Ljava/nio/IntBuffer;B)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__IIILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2Ljava_nio_IntBuffer_2B
	  (JNIEnv *, jobject, jint, jint, jint, jobject, jobject, jobject, jbyte);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (II[II[II)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__II_3II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetAttachedShaders
	 * Signature: (II[II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetAttachedShaders__II_3II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetAttachedShaders
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetAttachedShaders__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetAttribLocation
	 * Signature: (ILjava/lang/String;)I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetAttribLocation
	  (JNIEnv *, jobject, jint, jstring);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBooleanv
	 * Signature: (I[ZI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBooleanv__I_3ZI
	  (JNIEnv *, jobject, jint, jbooleanArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBooleanv
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBooleanv__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBufferParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBufferParameteriv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBufferParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBufferParameteriv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetError
	 * Signature: ()I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetError
	  (JNIEnv *, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFloatv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFloatv__I_3FI
	  (JNIEnv *, jobject, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFloatv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFloatv__ILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFramebufferAttachmentParameteriv
	 * Signature: (III[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFramebufferAttachmentParameteriv__III_3II
	  (JNIEnv *, jobject, jint, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFramebufferAttachmentParameteriv
	 * Signature: (IIILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFramebufferAttachmentParameteriv__IIILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetIntegerv
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetIntegerv__I_3II
	  (JNIEnv *, jobject, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetIntegerv
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetIntegerv__ILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetProgramiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetProgramiv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetProgramiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetProgramiv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetProgramInfoLog
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetProgramInfoLog
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetRenderbufferParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetRenderbufferParameteriv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetRenderbufferParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetRenderbufferParameteriv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderiv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderiv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderInfoLog
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderInfoLog
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderPrecisionFormat
	 * Signature: (II[II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderPrecisionFormat__II_3II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderPrecisionFormat
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderPrecisionFormat__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderSource
	 * Signature: (II[II[BI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderSource__II_3II_3BI
	  (JNIEnv *, jobject, jint, jint, jintArray, jint, jbyteArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderSource
	 * Signature: (IILjava/nio/IntBuffer;B)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderSource__IILjava_nio_IntBuffer_2B
	  (JNIEnv *, jobject, jint, jint, jobject, jbyte);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderSource
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderSource__I
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetString
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetString
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameterfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameterfv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameterfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameterfv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameteriv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameteriv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformfv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformfv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformiv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformiv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformLocation
	 * Signature: (ILjava/lang/String;)I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformLocation
	  (JNIEnv *, jobject, jint, jstring);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribfv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribfv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribiv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribiv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glHint
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glHint
	  (JNIEnv *, jobject, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsBuffer
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsBuffer
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsEnabled
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsEnabled
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsFramebuffer
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsFramebuffer
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsProgram
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsProgram
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsRenderbuffer
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsRenderbuffer
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsShader
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsShader
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsTexture
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsTexture
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glLineWidth
	 * Signature: (F)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glLineWidth
	  (JNIEnv *, jobject, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glLinkProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glLinkProgram
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glPixelStorei
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glPixelStorei
	  (JNIEnv *, jobject, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glPolygonOffset
	 * Signature: (FF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glPolygonOffset
	  (JNIEnv *, jobject, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glReadPixels
	 * Signature: (IIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glReadPixels
	  (JNIEnv *, jobject, jint, jint, jint, jint, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glReleaseShaderCompiler
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glReleaseShaderCompiler
	  (JNIEnv *, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glRenderbufferStorage
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glRenderbufferStorage
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glSampleCoverage
	 * Signature: (FZ)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glSampleCoverage
	  (JNIEnv *, jobject, jfloat, jboolean);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glScissor
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glScissor
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glShaderBinary
	 * Signature: (I[IIILjava/nio/Buffer;I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glShaderBinary__I_3IIILjava_nio_Buffer_2I
	  (JNIEnv *, jobject, jint, jintArray, jint, jint, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glShaderBinary
	 * Signature: (ILjava/nio/IntBuffer;ILjava/nio/Buffer;I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glShaderBinary__ILjava_nio_IntBuffer_2ILjava_nio_Buffer_2I
	  (JNIEnv *, jobject, jint, jobject, jint, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glShaderSource
	 * Signature: (ILjava/lang/String;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glShaderSource
	  (JNIEnv *, jobject, jint, jstring);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilFunc
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilFunc
	  (JNIEnv *, jobject, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilFuncSeparate
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilFuncSeparate
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilMask
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilMask
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilMaskSeparate
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilMaskSeparate
	  (JNIEnv *, jobject, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilOp
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilOp
	  (JNIEnv *, jobject, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilOpSeparate
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilOpSeparate
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexImage2D
	 * Signature: (IIIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexImage2D
	  (JNIEnv *, jobject, jint, jint, jint, jint, jint, jint, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameterf
	 * Signature: (IIF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameterf
	  (JNIEnv *, jobject, jint, jint, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameterfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameterfv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameterfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameterfv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameteri
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameteri
	  (JNIEnv *, jobject, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameteriv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameteriv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexSubImage2D
	 * Signature: (IIIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexSubImage2D
	  (JNIEnv *, jobject, jint, jint, jint, jint, jint, jint, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1f
	 * Signature: (IF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1f
	  (JNIEnv *, jobject, jint, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1fv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1fv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1i
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1i
	  (JNIEnv *, jobject, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1iv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1iv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2f
	 * Signature: (IFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2f
	  (JNIEnv *, jobject, jint, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2fv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2fv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2i
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2i
	  (JNIEnv *, jobject, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2iv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2iv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3f
	 * Signature: (IFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3f
	  (JNIEnv *, jobject, jint, jfloat, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3fv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3fv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3i
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3i
	  (JNIEnv *, jobject, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3iv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3iv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4f
	 * Signature: (IFFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4f
	  (JNIEnv *, jobject, jint, jfloat, jfloat, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4fv__II_3FI
	  (JNIEnv *, jobject, jint, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4fv__IILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4i
	 * Signature: (IIIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4i
	  (JNIEnv *, jobject, jint, jint, jint, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4iv__II_3II
	  (JNIEnv *, jobject, jint, jint, jintArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4iv__IILjava_nio_IntBuffer_2
	  (JNIEnv *, jobject, jint, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix2fv
	 * Signature: (IIZ[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix2fv__IIZ_3FI
	  (JNIEnv *, jobject, jint, jint, jboolean, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix2fv
	 * Signature: (IIZLjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix2fv__IIZLjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jboolean, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix3fv
	 * Signature: (IIZ[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix3fv__IIZ_3FI
	  (JNIEnv *, jobject, jint, jint, jboolean, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix3fv
	 * Signature: (IIZLjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix3fv__IIZLjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jboolean, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix4fv
	 * Signature: (IIZ[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix4fv__IIZ_3FI
	  (JNIEnv *, jobject, jint, jint, jboolean, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix4fv
	 * Signature: (IIZLjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix4fv__IIZLjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jint, jboolean, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUseProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUseProgram
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glValidateProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glValidateProgram
	  (JNIEnv *, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib1f
	 * Signature: (IF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib1f
	  (JNIEnv *, jobject, jint, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib1fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib1fv__I_3FI
	  (JNIEnv *, jobject, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib1fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib1fv__ILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib2f
	 * Signature: (IFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib2f
	  (JNIEnv *, jobject, jint, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib2fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib2fv__I_3FI
	  (JNIEnv *, jobject, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib2fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib2fv__ILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib3f
	 * Signature: (IFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib3f
	  (JNIEnv *, jobject, jint, jfloat, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib3fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib3fv__I_3FI
	  (JNIEnv *, jobject, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib3fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib3fv__ILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib4f
	 * Signature: (IFFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib4f
	  (JNIEnv *, jobject, jint, jfloat, jfloat, jfloat, jfloat);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib4fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib4fv__I_3FI
	  (JNIEnv *, jobject, jint, jfloatArray, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib4fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib4fv__ILjava_nio_FloatBuffer_2
	  (JNIEnv *, jobject, jint, jobject);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttribPointer
	 * Signature: (IIIZII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttribPointer
	  (JNIEnv *, jobject, jint, jint, jint, jboolean, jint, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttribPointerBounds
	 * Signature: (IIIZILjava/nio/Buffer;I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttribPointerBounds
	  (JNIEnv *, jobject, jint, jint, jint, jboolean, jint, jobject, jint);

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glViewport
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glViewport
	  (JNIEnv *, jobject, jint, jint, jint, jint);

}