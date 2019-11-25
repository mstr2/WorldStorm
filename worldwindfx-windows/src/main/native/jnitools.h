#pragma once

#include <jni.h>
#include <cstdint>
#include <memory>
#include <stdexcept>

class InString
{
public:
	InString(JNIEnv* env, jstring str) :
		env_(env), jstr_(str), cstr_(env->GetStringUTFChars(str, 0))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	InString(InString const&) = delete;

	~InString()
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

class OutString
{
public:
	OutString(JNIEnv* env, int capacity) : env_(env)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("Capacity must be larger than 0.");
		}

		cstr_ = new char[capacity];
		std::fill(cstr_, cstr_ + capacity, 0);
	}

	OutString(OutString const&) = delete;

	~OutString()
	{
		delete[] cstr_;
	}

	operator char*()
	{
		return cstr_;
	}

	operator jstring() const
	{
		return env_->NewStringUTF(cstr_);
	}

private:
	JNIEnv* env_;
	char* cstr_;
};

class ByteBuffer
{
public:
	ByteBuffer(JNIEnv* env, jbyteArray array, jint offset) :
		env_(env), array_(array), elements_(env->GetByteArrayElements(array, false)), offset_(offset)
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	ByteBuffer(JNIEnv* env, jobject jbuf) : env_(env), elements_((jbyte*)env->GetDirectBufferAddress(jbuf))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	ByteBuffer(ByteBuffer const&) = delete;

	~ByteBuffer()
	{
		if (array_ != nullptr)
		{
			env_->ReleaseByteArrayElements(array_, elements_, 0);
		}
	}

	operator const void*() const
	{
		return reinterpret_cast<void*>(elements_);
	}

	operator void*()
	{
		return reinterpret_cast<void*>(elements_);
	}

	operator const char*() const
	{
		return reinterpret_cast<char*>(elements_);
	}

	operator char*()
	{
		return reinterpret_cast<char*>(elements_);
	}

private:
	JNIEnv* env_;
	jbyteArray array_ = nullptr;
	jbyte* elements_ = nullptr;
	jint offset_ = 0;
};

class IntBuffer
{
public:
	IntBuffer(JNIEnv* env, jintArray array, jint offset) :
		env_(env), array_(array), elements_(env->GetIntArrayElements(array, false)), offset_(offset)
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	IntBuffer(JNIEnv* env, jobject buffer) :
		env_(env), elements_(reinterpret_cast<jint*>(env->GetDirectBufferAddress(buffer)))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	IntBuffer(IntBuffer const&) = delete;

	~IntBuffer()
	{
		if (array_ != nullptr)
		{
			env_->ReleaseIntArrayElements(array_, elements_, 0);
		}
	}

	operator const std::int32_t*() const
	{
		return reinterpret_cast<std::int32_t*>(elements_ + offset_);
	}

	operator std::int32_t*()
	{
		return reinterpret_cast<std::int32_t*>(elements_ + offset_);
	}

	operator const std::uint32_t*() const
	{
		return reinterpret_cast<std::uint32_t*>(elements_ + offset_);
	}

	operator std::uint32_t*()
	{
		return reinterpret_cast<std::uint32_t*>(elements_ + offset_);
	}

private:
	JNIEnv* env_;
	jintArray array_ = nullptr;
	jint* elements_ = nullptr;
	jint offset_ = 0;
};

class FloatBuffer
{
public:
	FloatBuffer(JNIEnv* env, jfloatArray array, jint offset) :
		env_(env), array_(array), elements_(env->GetFloatArrayElements(array, false)), offset_(offset)
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	FloatBuffer(JNIEnv* env, jobject buffer) :
		env_(env), elements_(reinterpret_cast<jfloat*>(env->GetDirectBufferAddress(buffer)))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	FloatBuffer(FloatBuffer const&) = delete;

	~FloatBuffer()
	{
		if (array_ != nullptr)
		{
			env_->ReleaseFloatArrayElements(array_, elements_, 0);
		}
	}

	operator const float* () const
	{
		return reinterpret_cast<float*>(elements_ + offset_);
	}

	operator float* ()
	{
		return reinterpret_cast<float*>(elements_ + offset_);
	}

private:
	JNIEnv* env_;
	jfloatArray array_ = nullptr;
	jfloat* elements_ = nullptr;
	jint offset_ = 0;
};


class BoolBuffer
{
	static_assert(sizeof(jboolean) == sizeof(GLboolean), "sizeof(jboolean) != sizeof(GLboolean)");

public:
	BoolBuffer(JNIEnv* env, jbooleanArray array, jint offset) :
		env_(env), array_(array), elements_(env->GetBooleanArrayElements(array, false)), offset_(offset)
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	BoolBuffer(JNIEnv* env, jobject buffer) :
		env_(env), elements_(reinterpret_cast<jboolean*>(env->GetDirectBufferAddress(buffer)))
	{
		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	BoolBuffer(BoolBuffer const&) = delete;

	~BoolBuffer()
	{
		if (array_ != nullptr)
		{
			env_->ReleaseBooleanArrayElements(array_, elements_, 0);
		}
	}

	operator const unsigned char* () const
	{
		return reinterpret_cast<unsigned char*>(elements_ + offset_);
	}

	operator unsigned char* ()
	{
		return reinterpret_cast<unsigned char*>(elements_ + offset_);
	}

private:
	JNIEnv* env_;
	jbooleanArray array_ = nullptr;
	jboolean* elements_ = nullptr;
	jint offset_ = 0;
};
