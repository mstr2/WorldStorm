#pragma once

#include <jni.h>
#include <GLES2/gl2.h>

extern "C" {
	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glActiveTexture(JNIEnv* env, jint texture) {
		glActiveTexture(texture);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glAttachShader(JNIEnv* env, jint program, jint shader) {
		glAttachShader(program, shader);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glBindAttribLocation(JNIEnv* env, jint program, jint index, jstring name) {
		const char *str = env->GetStringUTFChars(name, 0);
		glBindAttribLocation(program, index, str);
		env->ReleaseStringUTFChars(name, str);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glBindBuffer(JNIEnv* env, jint target, jint buffer) {
		glBindBuffer(target, buffer);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glBindFramebuffer(JNIEnv* env, jint target, jint framebuffer) {
		glBindFramebuffer(target, framebuffer);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glBindTexture(JNIEnv* env, jint target, jint texture) {
		glBindTexture(target, texture);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glBufferData(JNIEnv* env, jint target, jint size, /* Buffer */ jobject data, jint usage) {
		glBufferData(target, size, env->GetDirectBufferAddress(data), usage);
	}

	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glCheckFramebufferStatus(JNIEnv* env, jint target) {
		return glCheckFramebufferStatus(target);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glClear(JNIEnv* env, jint mask) {
		glClear(mask);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glCompileShader(JNIEnv* env, jint shader) {
		glCompileShader(shader);
	}

	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glCreateProgram(JNIEnv* env) {
		return glCreateProgram();
	}

	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glCreateShader(JNIEnv* env, jint type) {
		return glCreateShader(type);
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glDeleteBuffers(JNIEnv* env, jint n, jintArray buffers, jint buffers_offset) {
		/*jint* b = env->GetIntArrayElements(buffers, false);
		glDeleteBuffers(n, b + buffers_offset);
		env->ReleaseIntArrayElements(buffers, b, 0);*/
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glDeleteFramebuffers(JNIEnv* env, jint n, jintArray framebuffers, jint framebuffers_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glDeleteProgram(JNIEnv* env, jint program) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glDeleteShader(JNIEnv* env, jint shader) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glDeleteTextures(JNIEnv* env, jint n, jintArray textures, jint textures_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glFramebufferTexture2D(JNIEnv* env, jint target, jint attachment, jint textarget, jint texture, jint level) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGenBuffers(JNIEnv* env, jint n, jintArray buffers, jint buffers_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGenerateMipmap(JNIEnv* env, jint target) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGenFramebuffers(JNIEnv* env, jint n, jintArray framebuffers, jint framebuffers_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGenTextures(JNIEnv* env, jint n, jintArray textures, jint textures_offset) {
	}

	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGetProgramInfoLog(JNIEnv* env, jint program) {
		return nullptr;
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGetProgramiv(JNIEnv* env, jint program, jint pname, jintArray params, jint params_offset) {
	}

	JNIEXPORT jstring JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGetShaderInfoLog(JNIEnv* env, jint shader) {
		return nullptr;
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGetShaderiv(JNIEnv* env, jint shader, int pname, jintArray params, jint params_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniformiv(JNIEnv* env, jint program, jint location, jintArray params, jint params_offset) {
	}

	JNIEXPORT jint JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glGetUniformLocation(JNIEnv* env, jint program, jstring name) {
		return 0;
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glLinkProgram(JNIEnv* env, jint program) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glReadPixels(JNIEnv* env, jint x, jint y, jint width, jint height, jint format, jint type, /* Buffer */ jobject pixels) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glShaderSource(JNIEnv* env, jint shader, jstring source) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glTexImage2D(JNIEnv* env, jint target, jint level, jint internalformat, jint width, jint height, jint border, jint format, jint type, /* Buffer */ jobject pixels) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glTexParameteri(JNIEnv* env, jint target, jint pname, jint param) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform1f(JNIEnv* env, jint location, jfloat x) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform2f(JNIEnv* env, jint location, jfloat x, jfloat y) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform3f(JNIEnv* env, jint location, jfloat x, jfloat y, jfloat z) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform4f(JNIEnv* env, jint location, jfloat x, jfloat y, jfloat z, jfloat w) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform1fv(JNIEnv* env, jint location, jint count, jfloatArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform2fv(JNIEnv* env, jint location, jint count, jfloatArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform3fv(JNIEnv* env, jint location, jint count, jfloatArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform4fv(JNIEnv* env, jint location, jint count, jfloatArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform1i(JNIEnv* env, jint location, jint x) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform2i(JNIEnv* env, jint location, jint x, jint y) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform3i(JNIEnv* env, jint location, jint x, jint y, jint z) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform4i(JNIEnv* env, jint location, jint x, jint y, jint z, jint w) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform1iv(JNIEnv* env, jint location, jint count, jintArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform2iv(JNIEnv* env, jint location, jint count, jintArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform3iv(JNIEnv* env, jint location, jint count, jintArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniform4iv(JNIEnv* env, jint location, jint count, jintArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniformMatrix3fv(JNIEnv* env, jint location, jint count, jboolean transpose, jfloatArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUniformMatrix4fv(JNIEnv* env, jint location, jint count, jboolean transpose, jfloatArray v, jint v_offset) {
	}

	JNIEXPORT void JNICALL Java_gov_nasa_worldwind_javafx_GLInterface_glUseProgram(JNIEnv* env, jint program) {
	}
}