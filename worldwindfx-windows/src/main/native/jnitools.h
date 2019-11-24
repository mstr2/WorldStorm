#pragma once

#include <jni.h>

class CString
{
public:
	CString(JNIEnv* env, jstring str) :
		env_(env), jstr_(str), cstr_(env->GetStringUTFChars(str, 0))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	CString(CString const&) = delete;

	~CString()
	{
		env_->ReleaseStringUTFChars(jstr_, cstr_);
	}

	operator const char*() const
	{
		return cstr_;
	}

private:
	JNIEnv* env_;
	jstring jstr_;
	const char* cstr_;
};

class CBuffer
{
public:
	CBuffer(JNIEnv* env, jobject jbuf) : env_(env), buf_(env->GetDirectBufferAddress(jbuf))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	CBuffer(CBuffer const&) = delete;

	operator const void*() const
	{
		return buf_;
	}

private:
	JNIEnv* env_;
	const void* buf_;
};

class CBufferUint
{
public:
	CBufferUint(JNIEnv* env, jintArray intArray, jint offset) :
		env_(env), intArray_(intArray), elements_(env->GetIntArrayElements(intArray, false)), offset_(offset)
	{
	}

	CBufferUint(JNIEnv* env, jobject intBuffer) : env_(env)
	{
		
	}

	CBufferUint(CBufferUint const&) = delete;

	~CBufferUint()
	{
		env_->ReleaseIntArrayElements(intArray_, elements_, 0);
	}

	operator unsigned int*()
	{
		return reinterpret_cast<unsigned int*>(elements_ + offset_);
	}
private:
	JNIEnv* env_;
	jintArray intArray_;
	jint* elements_;
	jint offset_;
};