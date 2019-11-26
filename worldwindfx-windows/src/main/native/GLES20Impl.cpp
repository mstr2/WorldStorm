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
		glBindAttribLocation(program, index, InString(env, name));
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
		glBufferData(target, size, ByteBuffer(env, data), usage);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glBufferSubData
	 * Signature: (IIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glBufferSubData(
		JNIEnv* env, jobject, jint target, jint offset, jint size, jobject data)
	{
		glBufferSubData(target, offset, size, ByteBuffer(env, data));
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
		glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, ByteBuffer(env, data));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glCompressedTexSubImage2D
	 * Signature: (IIIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glCompressedTexSubImage2D(
		JNIEnv* env, jobject, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint imageSize, jobject data)
	{
		glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, ByteBuffer(env, data));
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
		ValidateArraySize_V(buffers, offset, n);
		glDeleteBuffers(n, IntBuffer(env, buffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteBuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteBuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject buffers)
	{
		ValidateBufferSize_V(buffers, n);
		glDeleteBuffers(n, IntBuffer(env, buffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteFramebuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteFramebuffers__I_3II(
		JNIEnv* env, jobject, jint n, jintArray framebuffers, jint offset)
	{
		ValidateArraySize_V(framebuffers, offset, n);
		glDeleteFramebuffers(n, IntBuffer(env, framebuffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteFramebuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteFramebuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject framebuffers)
	{
		ValidateBufferSize_V(framebuffers, n);
		glDeleteFramebuffers(n, IntBuffer(env, framebuffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteProgram(
		JNIEnv*, jobject, jint program)
	{
		glDeleteProgram(program);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteRenderbuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteRenderbuffers__I_3II(
		JNIEnv* env, jobject, jint n, jintArray renderbuffers, jint offset)
	{
		ValidateArraySize_V(renderbuffers, offset, n);
		glDeleteRenderbuffers(n, IntBuffer(env, renderbuffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteRenderbuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteRenderbuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject renderbuffers)
	{
		ValidateBufferSize_V(renderbuffers, n);
		glDeleteRenderbuffers(n, IntBuffer(env, renderbuffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteShader
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteShader(
		JNIEnv*, jobject, jint shader)
	{
		glDeleteShader(shader);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteTextures
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteTextures__I_3II(
		JNIEnv* env, jobject, jint n, jintArray textures, jint offset)
	{
		ValidateArraySize_V(textures, offset, n);
		glDeleteTextures(n, IntBuffer(env, textures, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDeleteTextures
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDeleteTextures__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject textures)
	{
		ValidateBufferSize_V(textures, n);
		glDeleteTextures(n, IntBuffer(env, textures));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDepthFunc
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDepthFunc(
		JNIEnv*, jobject, jint func)
	{
		glDepthFunc(func);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDepthMask
	 * Signature: (Z)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDepthMask(
		JNIEnv*, jobject, jboolean flag)
	{
		glDepthMask(flag);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDepthRangef
	 * Signature: (FF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDepthRangef(
		JNIEnv*, jobject, jfloat n, jfloat f)
	{
		glDepthRangef(n, f);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDetachShader
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDetachShader(
		JNIEnv*, jobject, jint program, jint shader)
	{
		glDetachShader(program, shader);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDisable
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDisable(
		JNIEnv*, jobject, jint cap)
	{
		glDisable(cap);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDisableVertexAttribArray
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDisableVertexAttribArray(
		JNIEnv*, jobject, jint index)
	{
		glDisableVertexAttribArray(index);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDrawArrays
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDrawArrays(
		JNIEnv*, jobject, jint mode, jint first, jint count)
	{
		glDrawArrays(mode, first, count);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDrawElements
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDrawElements__IIII(
		JNIEnv*, jobject, jint mode, jint count, jint type, jint offset)
	{
		glDrawElements(mode, count, type, (void*)(long long)(offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glDrawElements
	 * Signature: (IIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glDrawElements__IIILjava_nio_Buffer_2(
		JNIEnv* env, jobject, jint mode, jint count, jint type, jobject indices)
	{
		ValidateBufferSize_V(indices, count);
		glDrawElements(mode, count, type, ByteBuffer(env, indices));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glEnable
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glEnable(
		JNIEnv*, jobject, jint cap)
	{
		glEnable(cap);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glEnableVertexAttribArray
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glEnableVertexAttribArray(
		JNIEnv*, jobject, jint index)
	{
		glEnableVertexAttribArray(index);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFinish
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFinish(
		JNIEnv *, jobject)
	{
		glFinish();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFlush
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFlush(
		JNIEnv*, jobject)
	{
		glFlush();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFramebufferRenderbuffer
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFramebufferRenderbuffer(
		JNIEnv*, jobject, jint target, jint attachment, jint renderbuffertarget, jint renderbuffer)
	{
		glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFramebufferTexture2D
	 * Signature: (IIIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFramebufferTexture2D(
		JNIEnv*, jobject, jint target, jint attachment, jint textarget, jint texture, jint level)
	{
		glFramebufferTexture2D(target, attachment, textarget, texture, level);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glFrontFace
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glFrontFace(
		JNIEnv*, jobject, jint mode)
	{
		glFrontFace(mode);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenBuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenBuffers__I_3II(
		JNIEnv* env, jobject, jint n, jintArray buffers, jint offset)
	{
		ValidateArraySize_V(buffers, offset, n);
		glGenBuffers(n, IntBuffer(env, buffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenBuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenBuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject buffers)
	{
		ValidateBufferSize_V(buffers, n);
		glGenBuffers(n, IntBuffer(env, buffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenerateMipmap
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenerateMipmap(
		JNIEnv*, jobject, jint target)
	{
		glGenerateMipmap(target);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenFramebuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenFramebuffers__I_3II(
		JNIEnv* env, jobject, jint n, jintArray framebuffers, jint offset)
	{
		ValidateArraySize_V(framebuffers, offset, n);
		glGenFramebuffers(n, IntBuffer(env, framebuffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenFramebuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenFramebuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject framebuffers)
	{
		ValidateBufferSize_V(framebuffers, n);
		glGenFramebuffers(n, IntBuffer(env, framebuffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenRenderbuffers
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenRenderbuffers__I_3II(
		JNIEnv* env, jobject, jint n, jintArray renderbuffers, jint offset)
	{
		ValidateArraySize_V(renderbuffers, offset, n);
		glGenRenderbuffers(n, IntBuffer(env, renderbuffers, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenRenderbuffers
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenRenderbuffers__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject renderbuffers)
	{
		ValidateBufferSize_V(renderbuffers, n);
		glGenRenderbuffers(n, IntBuffer(env, renderbuffers));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenTextures
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenTextures__I_3II(
		JNIEnv* env, jobject, jint n, jintArray textures, jint offset)
	{
		ValidateArraySize_V(textures, offset, n);
		glGenTextures(n, IntBuffer(env, textures, offset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGenTextures
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGenTextures__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint n, jobject textures)
	{
		ValidateBufferSize_V(textures, n);
		glGenTextures(n, IntBuffer(env, textures));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (III[II[II[II[BI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__III_3II_3II_3II_3BI(
		JNIEnv* env, jobject, jint program, jint index, jint bufSize, jintArray length, jint lengthOffset, jintArray size, jint sizeOffset, jintArray type, jint typeOffset, jbyteArray name, jint nameOffset)
	{
		ValidateArraySize_V(length, lengthOffset, 1);
		ValidateArraySize_V(size, sizeOffset, 1);
		ValidateArraySize_V(type, typeOffset, 1);
		glGetActiveAttrib(program, index, bufSize, IntRegion<1>(env, length, lengthOffset), IntRegion<1>(env, size, sizeOffset), IntRegion<1>(env, type, typeOffset), ByteBuffer(env, name, nameOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (II[II[II)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__II_3II_3II(
		JNIEnv* env, jobject, jint program, jint index, jintArray size, jint sizeOffset, jintArray type, jint typeOffset)
	{
		ValidateArraySize_I(size, sizeOffset, 1);
		ValidateArraySize_I(type, typeOffset, 1);
		int maxAttrLength;
		glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxAttrLength);
		OutString name(env, maxAttrLength);
		glGetActiveAttrib(program, index, maxAttrLength, nullptr, IntRegion<1>(env, size, sizeOffset), IntRegion<1>(env, type, typeOffset), name);
		return name;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveAttrib
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveAttrib__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint program, jint index, jobject size, jobject type)
	{
		ValidateBufferSize_I(size, 1);
		ValidateBufferSize_I(type, 1);
		int maxAttrLength;
		glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxAttrLength);
		OutString name(env, maxAttrLength);
		glGetActiveAttrib(program, index, maxAttrLength, nullptr, IntBuffer(env, size), IntBuffer(env, type), name);
		return name;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (III[II[II[II[BI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__III_3II_3II_3II_3BI(
		JNIEnv* env, jobject, jint program, jint index, jint bufSize, jintArray length, jint lengthOffset, jintArray size, jint sizeOffset, jintArray type, jint typeOffset, jbyteArray name, jint nameOffset)
	{
		ValidateArraySize_V(length, lengthOffset, 1);
		ValidateArraySize_V(size, sizeOffset, 1);
		ValidateArraySize_V(type, typeOffset, 1);
		glGetActiveUniform(program, index, bufSize, IntRegion<1>(env, length, lengthOffset), IntRegion<1>(env, size, sizeOffset), IntRegion<1>(env, type, typeOffset), ByteBuffer(env, name, nameOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (II[II[II)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__II_3II_3II(
		JNIEnv* env, jobject, jint program, jint index, jintArray size, jint sizeOffset, jintArray type, jint typeOffset)
	{
		ValidateArraySize_I(size, sizeOffset, 1);
		ValidateArraySize_I(type, typeOffset, 1);
		int maxUniformLength;
		glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformLength);
		OutString name(env, maxUniformLength);
		glGetActiveUniform(program, index, maxUniformLength, nullptr, IntRegion<1>(env, size, sizeOffset), IntRegion<1>(env, type, typeOffset), name);
		return name;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetActiveUniform
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetActiveUniform__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint program, jint index, jobject size, jobject type)
	{
		ValidateBufferSize_I(size, 1);
		ValidateBufferSize_I(type, 1);
		int maxUniformLength;
		glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformLength);
		OutString name(env, maxUniformLength);
		glGetActiveUniform(program, index, maxUniformLength, nullptr, IntBuffer(env, size), IntBuffer(env, type), name);
		return name;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetAttachedShaders
	 * Signature: (II[II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetAttachedShaders__II_3II_3II(
		JNIEnv* env, jobject, jint program, jint maxCount, jintArray count, jint countOffset, jintArray shaders, jint shadersOffset)
	{
		ValidateArraySize_V(count, countOffset, 1);
		ValidateArraySize_V(shaders, shadersOffset, maxCount);
		glGetAttachedShaders(program, maxCount, IntRegion<1>(env, count, countOffset), IntBuffer(env, shaders, shadersOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetAttachedShaders
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetAttachedShaders__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint program, jint maxCount, jobject count, jobject shaders)
	{
		ValidateBufferSize_V(count, 1);
		ValidateBufferSize_V(shaders, maxCount);
		glGetAttachedShaders(program, maxCount, IntBuffer(env, count), IntBuffer(env, shaders));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetAttribLocation
	 * Signature: (ILjava/lang/String;)I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetAttribLocation(
		JNIEnv* env, jobject, jint program, jstring name)
	{
		return glGetAttribLocation(program, InString(env, name));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBooleanv
	 * Signature: (I[ZI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBooleanv__I_3ZI(
		JNIEnv* env, jobject, jint pname, jbooleanArray data, jint dataOffset)
	{
		ValidateArraySize_V(data, dataOffset, 1);
		glGetBooleanv(pname, BoolBuffer(env, data, dataOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBooleanv
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBooleanv__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint pname, jobject buffer)
	{
		ValidateBufferSize_V(buffer, 1);
		glGetBooleanv(pname, BoolBuffer(env, buffer));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBufferParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBufferParameteriv__II_3II(
		JNIEnv* env, jobject, jint target, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetBufferParameteriv(target, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetBufferParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetBufferParameteriv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint target, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetBufferParameteriv(target, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetError
	 * Signature: ()I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetError(
		JNIEnv*, jobject)
	{
		return glGetError();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFloatv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFloatv__I_3FI(
		JNIEnv* env, jobject, jint pname, jfloatArray data, jint dataOffset)
	{
		ValidateArraySize_V(data, dataOffset, 1);
		return glGetFloatv(pname, FloatBuffer(env, data, dataOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFloatv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFloatv__ILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint pname, jobject data)
	{
		ValidateBufferSize_V(data, 1);
		glGetFloatv(pname, FloatBuffer(env, data));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFramebufferAttachmentParameteriv
	 * Signature: (III[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFramebufferAttachmentParameteriv__III_3II(
		JNIEnv* env, jobject, jint target, jint attachment, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetFramebufferAttachmentParameteriv(target, attachment, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetFramebufferAttachmentParameteriv
	 * Signature: (IIILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetFramebufferAttachmentParameteriv__IIILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint target, jint attachment, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetFramebufferAttachmentParameteriv(target, attachment, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetIntegerv
	 * Signature: (I[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetIntegerv__I_3II(
		JNIEnv* env, jobject, jint pname, jintArray data, jint dataOffset)
	{
		ValidateArraySize_V(data, dataOffset, 1);
		glGetIntegerv(pname, IntBuffer(env, data, dataOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetIntegerv
	 * Signature: (ILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetIntegerv__ILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint pname, jobject data)
	{
		ValidateBufferSize_V(data, 1);
		glGetIntegerv(pname, IntBuffer(env, data));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetProgramiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetProgramiv__II_3II(
		JNIEnv* env, jobject, jint program, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetProgramiv(program, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetProgramiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetProgramiv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint program, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetProgramiv(program, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetProgramInfoLog
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetProgramInfoLog(
		JNIEnv* env, jobject, jint program)
	{
		OutString infoLog(env, 16384);
		glGetProgramInfoLog(program, 16384, nullptr, infoLog);
		return infoLog;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetRenderbufferParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetRenderbufferParameteriv__II_3II(
		JNIEnv* env, jobject, jint target, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetRenderbufferParameteriv(target, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetRenderbufferParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetRenderbufferParameteriv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint target, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetRenderbufferParameteriv(target, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderiv__II_3II(
		JNIEnv* env, jobject, jint shader, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetShaderiv(shader, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderiv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint shader, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetShaderiv(shader, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderInfoLog
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderInfoLog(
		JNIEnv* env, jobject, jint shader)
	{
		OutString infoLog(env, 16384);
		glGetShaderInfoLog(shader, 16384, nullptr, infoLog);
		return infoLog;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderPrecisionFormat
	 * Signature: (II[II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderPrecisionFormat__II_3II_3II(
		JNIEnv* env, jobject, jint shadertype, jint precisiontype, jintArray range, jint rangeOffset, jintArray precision, jint precisionOffset)
	{
		ValidateArraySize_V(range, rangeOffset, 2);
		ValidateArraySize_V(precision, precisionOffset, 1);
		glGetShaderPrecisionFormat(shadertype, precisiontype, IntBuffer(env, range, rangeOffset), IntRegion<1>(env, precision, precisionOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderPrecisionFormat
	 * Signature: (IILjava/nio/IntBuffer;Ljava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderPrecisionFormat__IILjava_nio_IntBuffer_2Ljava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint shadertype, jint precisiontype, jobject range, jobject precision)
	{
		ValidateBufferSize_V(range, 2);
		ValidateBufferSize_V(precision, 1);
		glGetShaderPrecisionFormat(shadertype, precisiontype, IntBuffer(env, range), IntBuffer(env, precision));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderSource
	 * Signature: (II[II[BI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderSource__II_3II_3BI(
		JNIEnv* env, jobject, jint shader, jint bufSize, jintArray length, jint lengthOffset, jbyteArray source, jint sourceOffset)
	{
		ValidateArraySize_V(length, lengthOffset, 1);
		ValidateArraySize_V(source, sourceOffset, bufSize);
		glGetShaderSource(shader, bufSize, IntBuffer(env, length, lengthOffset), ByteBuffer(env, source, sourceOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetShaderSource
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetShaderSource__I(
		JNIEnv* env, jobject, jint shader)
	{
		int maxLength;
		glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &maxLength);
		OutString source(env, maxLength);
		glGetShaderSource(shader, maxLength, nullptr, source);
		return source;
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetString
	 * Signature: (I)Ljava/lang/String;
	 */
	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetString(
		JNIEnv* env, jobject, jint name)
	{
		return env->NewStringUTF((const char*)glGetString(name));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameterfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameterfv__II_3FI(
		JNIEnv* env, jobject, jint target, jint pname, jfloatArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetTexParameterfv(target, pname, FloatBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameterfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameterfv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint target, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetTexParameterfv(target, pname, FloatBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameteriv__II_3II(
		JNIEnv* env, jobject, jint target, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetTexParameteriv(target, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetTexParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetTexParameteriv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint target, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetTexParameteriv(target, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformfv__II_3FI(
		JNIEnv* env, jobject, jint program, jint location, jfloatArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetUniformfv(program, location, FloatBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformfv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint program, jint location, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetUniformfv(program, location, FloatBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformiv__II_3II(
		JNIEnv* env, jobject, jint program, jint location, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetUniformiv(program, location, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformiv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint program, jint location, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetUniformiv(program, location, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetUniformLocation
	 * Signature: (ILjava/lang/String;)I
	 */
	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetUniformLocation(
		JNIEnv* env, jobject, jint program, jstring name)
	{
		return glGetUniformLocation(program, InString(env, name));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribfv__II_3FI(
		JNIEnv* env, jobject, jint index, jint pname, jfloatArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetVertexAttribfv(index, pname, FloatBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribfv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint index, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetVertexAttribfv(index, pname, FloatBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribiv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribiv__II_3II(
		JNIEnv* env, jobject, jint index, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glGetVertexAttribiv(index, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glGetVertexAttribiv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glGetVertexAttribiv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint index, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glGetVertexAttribiv(index, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glHint
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glHint(
		JNIEnv*, jobject, jint target, jint mode)
	{
		glHint(target, mode);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsBuffer
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsBuffer(
		JNIEnv*, jobject, jint buffer)
	{
		return glIsBuffer(buffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsEnabled
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsEnabled(
		JNIEnv*, jobject, jint cap)
	{
		return glIsEnabled(cap);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsFramebuffer
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsFramebuffer(
		JNIEnv *, jobject, jint framebuffer)
	{
		return glIsFramebuffer(framebuffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsProgram
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsProgram(
		JNIEnv*, jobject, jint program)
	{
		return glIsProgram(program);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsRenderbuffer
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsRenderbuffer(
		JNIEnv*, jobject, jint renderbuffer)
	{
		return glIsRenderbuffer(renderbuffer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsShader
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsShader(
		JNIEnv*, jobject, jint shader)
	{
		return glIsShader(shader);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glIsTexture
	 * Signature: (I)Z
	 */
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glIsTexture(
		JNIEnv*, jobject, jint texture)
	{
		return glIsTexture(texture);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glLineWidth
	 * Signature: (F)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glLineWidth(
		JNIEnv*, jobject, jfloat width)
	{
		glLineWidth(width);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glLinkProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glLinkProgram(
		JNIEnv*, jobject, jint program)
	{
		glLinkProgram(program);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glPixelStorei
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glPixelStorei(
		JNIEnv*, jobject, jint pname, jint param)
	{
		glPixelStorei(pname, param);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glPolygonOffset
	 * Signature: (FF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glPolygonOffset(
		JNIEnv*, jobject, jfloat factor, jfloat units)
	{
		glPolygonOffset(factor, units);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glReadPixels
	 * Signature: (IIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glReadPixels(
		JNIEnv* env, jobject, jint x, jint y, jint width, jint height, jint format, jint type, jobject pixels)
	{
		glReadPixels(x, y, width, height, format, type, ByteBuffer(env, pixels));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glReleaseShaderCompiler
	 * Signature: ()V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glReleaseShaderCompiler(
		JNIEnv*, jobject)
	{
		glReleaseShaderCompiler();
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glRenderbufferStorage
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glRenderbufferStorage(
		JNIEnv*, jobject, jint target, jint internalformat, jint width, jint height)
	{
		glRenderbufferStorage(target, internalformat, width, height);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glSampleCoverage
	 * Signature: (FZ)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glSampleCoverage(
		JNIEnv*, jobject, jfloat value, jboolean invert)
	{
		glSampleCoverage(value, invert);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glScissor
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glScissor(
		JNIEnv*, jobject, jint x, jint y, jint width, jint height)
	{
		glScissor(x, y, width, height);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glShaderBinary
	 * Signature: (I[IIILjava/nio/Buffer;I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glShaderBinary__I_3IIILjava_nio_Buffer_2I(
		JNIEnv* env, jobject, jint count, jintArray shaders, jint shadersOffset, jint binaryformat, jobject binary, jint length)
	{
		ValidateArraySize_V(shaders, shadersOffset, count);
		ValidateBufferSize_V(binary, length);
		glShaderBinary(count, IntBuffer(env, shaders, shadersOffset), binaryformat, ByteBuffer(env, binary), length);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glShaderBinary
	 * Signature: (ILjava/nio/IntBuffer;ILjava/nio/Buffer;I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glShaderBinary__ILjava_nio_IntBuffer_2ILjava_nio_Buffer_2I(
		JNIEnv* env, jobject, jint count, jobject shaders, jint binaryformat, jobject binary, jint length)
	{
		ValidateBufferSize_V(shaders, count);
		ValidateBufferSize_V(binary, length);
		glShaderBinary(count, IntBuffer(env, shaders), binaryformat, ByteBuffer(env, binary), length);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glShaderSource
	 * Signature: (ILjava/lang/String;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glShaderSource(
		JNIEnv* env, jobject, jint shader, jstring source)
	{
		InString src(env, source);
		int length = env->GetStringLength(source);
		const char* csrc = src;
		glShaderSource(shader, 1, &csrc, &length);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilFunc
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilFunc(
		JNIEnv*, jobject, jint func, jint ref, jint mask)
	{
		glStencilFunc(func, ref, mask);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilFuncSeparate
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilFuncSeparate(
		JNIEnv*, jobject, jint face, jint func, jint ref, jint mask)
	{
		glStencilFuncSeparate(face, func, ref, mask);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilMask
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilMask(
		JNIEnv*, jobject, jint mask)
	{
		glStencilMask(mask);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilMaskSeparate
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilMaskSeparate(
		JNIEnv*, jobject, jint face, jint mask)
	{
		glStencilMaskSeparate(face, mask);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilOp
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilOp(
		JNIEnv*, jobject, jint fail, jint zfail, jint zpass)
	{
		glStencilOp(fail, zfail, zpass);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glStencilOpSeparate
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glStencilOpSeparate(
		JNIEnv*, jobject, jint face, jint sfail, jint dpfail, jint dppass)
	{
		glStencilOpSeparate(face, sfail, dpfail, dppass);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexImage2D
	 * Signature: (IIIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexImage2D(
		JNIEnv* env, jobject, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint format, jint type, jobject pixels)
	{
		glTexImage2D(target, level, internalformat, width, height, border, format, type, ByteBuffer(env, pixels));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameterf
	 * Signature: (IIF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameterf(
		JNIEnv*, jobject, jint target, jint pname, jfloat param)
	{
		glTexParameterf(target, pname, param);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameterfv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameterfv__II_3FI(
		JNIEnv* env, jobject, jint target, jint pname, jfloatArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glTexParameterfv(target, pname, FloatBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameterfv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameterfv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint target, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glTexParameterfv(target, pname, FloatBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameteri
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameteri(
		JNIEnv*, jobject, jint target, jint pname, jint param)
	{
		glTexParameteri(target, pname, param);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameteriv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameteriv__II_3II(
		JNIEnv* env, jobject, jint target, jint pname, jintArray params, jint paramsOffset)
	{
		ValidateArraySize_V(params, paramsOffset, 1);
		glTexParameteriv(target, pname, IntBuffer(env, params, paramsOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexParameteriv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexParameteriv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint target, jint pname, jobject params)
	{
		ValidateBufferSize_V(params, 1);
		glTexParameteriv(target, pname, IntBuffer(env, params));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glTexSubImage2D
	 * Signature: (IIIIIIIILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glTexSubImage2D(
		JNIEnv* env, jobject, jint target, jint level, jint xoffset, jint yoffset, jint width, jint height, jint format, jint type, jobject pixels)
	{
		glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, ByteBuffer(env, pixels));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1f
	 * Signature: (IF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1f(
		JNIEnv*, jobject, jint location, jfloat v0)
	{
		glUniform1f(location, v0);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1fv__II_3FI(
		JNIEnv* env, jobject, jint location, jint count, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count);
		glUniform1fv(location, count, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1fv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count);
		glUniform1fv(location, count, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1i
	 * Signature: (II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1i(
		JNIEnv*, jobject, jint location, jint v0)
	{
		glUniform1i(location, v0);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1iv__II_3II(
		JNIEnv* env, jobject, jint location, jint count, jintArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count);
		glUniform1iv(location, count, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform1iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform1iv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count);
		glUniform1iv(location, count, IntBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2f
	 * Signature: (IFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2f(
		JNIEnv*, jobject, jint location, jfloat v0, jfloat v1)
	{
		glUniform2f(location, v0, v1);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2fv__II_3FI(
		JNIEnv* env, jobject, jint location, jint count, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 2);
		glUniform2fv(location, count, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2fv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count * 2);
		glUniform2fv(location, count, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2i
	 * Signature: (III)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2i(
		JNIEnv*, jobject, jint location, jint v0, jint v1)
	{
		glUniform2i(location, v0, v1);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2iv__II_3II(
		JNIEnv* env, jobject, jint location, jint count, jintArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 2);
		glUniform2iv(location, count, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform2iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform2iv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count * 2);
		glUniform2iv(location, count, IntBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3f
	 * Signature: (IFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3f(
		JNIEnv*, jobject, jint location, jfloat v0, jfloat v1, jfloat v2)
	{
		glUniform3f(location, v0, v1, v2);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3fv__II_3FI(
		JNIEnv* env, jobject, jint location, jint count, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 3);
		glUniform2fv(location, count, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3fv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count * 3);
		glUniform2fv(location, count, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3i
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3i(
		JNIEnv* env, jobject, jint location, jint v0, jint v1, jint v2)
	{
		glUniform3i(location, v0, v1, v2);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3iv__II_3II(
		JNIEnv* env, jobject, jint location, jint count, jintArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 3);
		glUniform3iv(location, count, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform3iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform3iv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count * 3);
		glUniform3iv(location, count, IntBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4f
	 * Signature: (IFFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4f(
		JNIEnv*, jobject, jint location, jfloat v0, jfloat v1, jfloat v2, jfloat v3)
	{
		glUniform4f(location, v0, v1, v2, v3);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4fv
	 * Signature: (II[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4fv__II_3FI(
		JNIEnv* env, jobject, jint location, jint count, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 4);
		glUniform4fv(location, count, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4fv
	 * Signature: (IILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4fv__IILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count * 4);
		glUniform4fv(location, count, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4i
	 * Signature: (IIIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4i(
		JNIEnv*, jobject, jint location, jint v0, jint v1, jint v2, jint v3)
	{
		glUniform4i(location, v0, v1, v2, v3);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4iv
	 * Signature: (II[II)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4iv__II_3II(
		JNIEnv* env, jobject, jint location, jint count, jintArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 4);
		glUniform4iv(location, count, IntBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniform4iv
	 * Signature: (IILjava/nio/IntBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniform4iv__IILjava_nio_IntBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jobject value)
	{
		ValidateBufferSize_V(value, count * 4);
		glUniform4iv(location, count, IntBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix2fv
	 * Signature: (IIZ[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix2fv__IIZ_3FI(
		JNIEnv* env, jobject, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 4);
		glUniformMatrix2fv(location, count, transpose, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix2fv
	 * Signature: (IIZLjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix2fv__IIZLjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jboolean transpose, jobject value)
	{
		ValidateBufferSize_V(value, count * 4);
		glUniformMatrix2fv(location, count, transpose, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix3fv
	 * Signature: (IIZ[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix3fv__IIZ_3FI(
		JNIEnv* env, jobject, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 9);
		glUniformMatrix3fv(location, count, transpose, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix3fv
	 * Signature: (IIZLjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix3fv__IIZLjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jboolean transpose, jobject value)
	{
		ValidateBufferSize_V(value, count * 9);
		glUniformMatrix3fv(location, count, transpose, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix4fv
	 * Signature: (IIZ[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix4fv__IIZ_3FI(
		JNIEnv* env, jobject, jint location, jint count, jboolean transpose, jfloatArray value, jint valueOffset)
	{
		ValidateArraySize_V(value, valueOffset, count * 16);
		glUniformMatrix4fv(location, count, transpose, FloatBuffer(env, value, valueOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUniformMatrix4fv
	 * Signature: (IIZLjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUniformMatrix4fv__IIZLjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint location, jint count, jboolean transpose, jobject value)
	{
		ValidateBufferSize_V(value, count * 16);
		glUniformMatrix4fv(location, count, transpose, FloatBuffer(env, value));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glUseProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glUseProgram(
		JNIEnv*, jobject, jint program)
	{
		glUseProgram(program);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glValidateProgram
	 * Signature: (I)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glValidateProgram(
		JNIEnv*, jobject, jint program)
	{
		glValidateProgram(program);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib1f
	 * Signature: (IF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib1f(
		JNIEnv*, jobject, jint index, jfloat x)
	{
		glVertexAttrib1f(index, x);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib1fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib1fv__I_3FI(
		JNIEnv* env, jobject, jint index, jfloatArray v, jint vOffset)
	{
		ValidateArraySize_V(v, vOffset, 1);
		glVertexAttrib1fv(index, FloatBuffer(env, v, vOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib1fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib1fv__ILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint index, jobject v)
	{
		ValidateBufferSize_V(v, 1);
		glVertexAttrib1fv(index, FloatBuffer(env, v));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib2f
	 * Signature: (IFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib2f(
		JNIEnv* env, jobject, jint index, jfloat x, jfloat y)
	{
		glVertexAttrib2f(index, x, y);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib2fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib2fv__I_3FI(
		JNIEnv* env, jobject, jint index, jfloatArray v, jint vOffset)
	{
		ValidateArraySize_V(v, vOffset, 2);
		glVertexAttrib2fv(index, FloatBuffer(env, v, vOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib2fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib2fv__ILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint index, jobject v)
	{
		ValidateBufferSize_V(v, 2);
		glVertexAttrib2fv(index, FloatBuffer(env, v));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib3f
	 * Signature: (IFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib3f(
		JNIEnv*, jobject, jint index, jfloat x, jfloat y, jfloat z)
	{
		glVertexAttrib3f(index, x, y, z);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib3fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib3fv__I_3FI(
		JNIEnv* env, jobject, jint index, jfloatArray v, jint vOffset)
	{
		ValidateArraySize_V(v, vOffset, 3);
		glVertexAttrib3fv(index, FloatBuffer(env, v, vOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib3fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib3fv__ILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint index, jobject v)
	{
		ValidateBufferSize_V(v, 3);
		glVertexAttrib3fv(index, FloatBuffer(env, v));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib4f
	 * Signature: (IFFFF)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib4f(
		JNIEnv*, jobject, jint index, jfloat x, jfloat y, jfloat z, jfloat w)
	{
		glVertexAttrib4f(index, x, y, z, w);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib4fv
	 * Signature: (I[FI)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib4fv__I_3FI(
		JNIEnv* env, jobject, jint index, jfloatArray v, jint vOffset)
	{
		ValidateArraySize_V(v, vOffset, 4);
		glVertexAttrib4fv(index, FloatBuffer(env, v, vOffset));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttrib4fv
	 * Signature: (ILjava/nio/FloatBuffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttrib4fv__ILjava_nio_FloatBuffer_2(
		JNIEnv* env, jobject, jint index, jobject v)
	{
		ValidateBufferSize_V(v, 4);
		glVertexAttrib4fv(index, FloatBuffer(env, v));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttribPointer
	 * Signature: (IIIZII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttribPointer__IIIZII(
		JNIEnv* env, jobject, jint index, jint size, jint type, jboolean normalized, jint stride, jint pointer)
	{
		glVertexAttribPointer(index, size, type, normalized, stride, (void*)(long long)pointer);
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glVertexAttribPointer
	 * Signature: (IIIZILjava/nio/Buffer;)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glVertexAttribPointer__IIIZILjava_nio_Buffer_2(
		JNIEnv* env, jobject, jint index, jint size, jint type, jboolean normalized, jint stride, jobject buffer)
	{
		glVertexAttribPointer(index, size, type, normalized, stride, ByteBuffer(env, buffer));
	}

	/*
	 * Class:     gov_nasa_worldwind_platform_GLES20Impl
	 * Method:    glViewport
	 * Signature: (IIII)V
	 */
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_platform_GLES20Impl_glViewport(
		JNIEnv*, jobject, jint x, jint y, jint width, jint height)
	{
		glViewport(x, y, width, height);
	}

}