#pragma once

#include <jni.h>
#include <EGL/egl.h>

namespace {
	class egl_attrib_list {
	private:
		JNIEnv* env_;
		jintArray jattrib_intArray_;
		jint* jattrib_list_;
		EGLint* egl_attrib_list_;

	public:
		egl_attrib_list(JNIEnv* env, jintArray attrib_list) {
			jint attrib_list_size = attrib_list != nullptr ? env->GetArrayLength(attrib_list) : 0;
			jint* attribs = attrib_list != nullptr ? env->GetIntArrayElements(attrib_list, 0) : nullptr;
			EGLint* attribs2 = nullptr;
			if (attrib_list_size > 0) {
				attribs2 = new EGLint[attrib_list_size];
				for (int i = 0; i < attrib_list_size; ++i) {
					attribs2[i] = attribs[i];
				}
			}

			env_ = env;
			jattrib_intArray_ = attrib_list;
			jattrib_list_ = attribs;
			egl_attrib_list_ = attribs2;
		}

		egl_attrib_list(egl_attrib_list const&) = delete;

		~egl_attrib_list() {
			if (jattrib_list_ != nullptr) {
				env_->ReleaseIntArrayElements(jattrib_intArray_, jattrib_list_, 0);
			}

			if (egl_attrib_list_ != nullptr) {
				delete[] egl_attrib_list_;
			}
		}

		EGLint const* as_EGLint() {
			return egl_attrib_list_;
		}
	};
}

extern "C" {
	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglBindAPI(JNIEnv* env, jint api) {
		return eglBindAPI(api);
	}

	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglTexImage(JNIEnv* env, jlong display, jlong surface, jint buffer) {
		return eglBindTexImage(reinterpret_cast<EGLDisplay>(display), reinterpret_cast<EGLSurface>(surface), buffer);
	}

	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglChooseConfig(JNIEnv* env, jlong display, jintArray attrib_list, jlongArray out_configs, jintArray num_out_configs) {
		jint max_out_configs = out_configs != nullptr ? env->GetArrayLength(out_configs) : 0;
		EGLConfig* configs = num_out_configs > 0 ? new EGLConfig[max_out_configs] : nullptr;
		EGLint actual_configs;
		egl_attrib_list attribs(env, attrib_list);

		jboolean ret = eglChooseConfig(
			reinterpret_cast<EGLDisplay>(display),
			attribs.as_EGLint(),
			configs,
			max_out_configs,
			&actual_configs);

		if (min(actual_configs, max_out_configs) > 0) {
			env->SetLongArrayRegion(out_configs, 0, min(actual_configs, max_out_configs), reinterpret_cast<jlong*>(configs));
		}

		jint temp = actual_configs;
		env->SetIntArrayRegion(num_out_configs, 0, 1, &temp);
		
		return ret;
	}

	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglGetDisplay(JNIEnv* env, jlong display_id) {
		return reinterpret_cast<jlong>(eglGetDisplay(reinterpret_cast<EGLNativeDisplayType>(display_id)));
	}

	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglInitialize(JNIEnv* env, jlong display, jintArray major, jintArray minor) {
		EGLint majorVer, minorVer;
		jboolean ret = eglInitialize(reinterpret_cast<EGLDisplay>(display), &majorVer, &minorVer);
		jint temp = majorVer;
		env->SetIntArrayRegion(major, 0, 1, &temp);
		temp = minorVer;
		env->SetIntArrayRegion(minor, 0, 1, &temp);
		return ret;
	}

	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglCreateWindowSurface(JNIEnv* env, jlong display, jlong config, jlong win, jintArray attrib_list) {
		egl_attrib_list attribs(env, attrib_list);
		return reinterpret_cast<jlong>(
			eglCreateWindowSurface(
				reinterpret_cast<EGLDisplay>(display),
				reinterpret_cast<EGLConfig>(config),
				reinterpret_cast<EGLNativeWindowType>(win),
				attribs.as_EGLint()));
	}

	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglCreatePbufferSurface(JNIEnv* env, jlong display, jlong config, jintArray attrib_list) {
		egl_attrib_list attribs(env, attrib_list);
		return reinterpret_cast<jlong>(
			eglCreatePbufferSurface(
				reinterpret_cast<EGLDisplay>(display),
				reinterpret_cast<EGLConfig>(config),
				attribs.as_EGLint()));
	}

	JNIEXPORT jlong JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglCreateContext(JNIEnv* env, jlong display, jlong config, jlong share_context, jintArray attrib_list) {
		egl_attrib_list attribs(env, attrib_list);
		return reinterpret_cast<jlong>(
			eglCreateContext(
				reinterpret_cast<EGLDisplay>(display),
				reinterpret_cast<EGLConfig>(config),
				reinterpret_cast<EGLContext>(share_context),
				attribs.as_EGLint()));
	}

	JNIEXPORT jboolean JNICALL Java_gov_nasa_worldwind_javafx_EGLInterface_eglMakeCurrent(JNIEnv* env, jlong display, jlong draw, jlong read, jlong context) {
		return eglMakeCurrent(
			reinterpret_cast<EGLDisplay>(display),
			reinterpret_cast<EGLSurface>(draw),
			reinterpret_cast<EGLSurface>(read),
			reinterpret_cast<EGLContext>(context));
	}
}