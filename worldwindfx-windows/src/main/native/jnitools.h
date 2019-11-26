#pragma once

#include <jni.h>
#include <GLES2/gl2.h>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <array>

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
		env_(env), array_(array), offset_(offset)
	{
		if (array != nullptr)
		{
			elements_ = env->GetByteArrayElements(array, nullptr);
		}

		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	ByteBuffer(JNIEnv* env, jobject buffer) :
		env_(env)
	{
		if (buffer != nullptr)
		{
			elements_ = reinterpret_cast<jbyte*>(env->GetDirectBufferAddress(buffer));
		}

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
		return elements_ != nullptr ? reinterpret_cast<void*>(&elements_[offset_]) : nullptr;
	}

	operator void*()
	{
		return elements_ != nullptr ? reinterpret_cast<void*>(&elements_[offset_]) : nullptr;
	}

	operator const char*() const
	{
		return elements_ != nullptr ? reinterpret_cast<char*>(&elements_[offset_]) : nullptr;
	}

	operator char*()
	{
		return elements_ != nullptr ? reinterpret_cast<char*>(&elements_[offset_]) : nullptr;
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
		env_(env), array_(array), offset_(offset)
	{
		if (array != nullptr)
		{
			elements_ = env->GetIntArrayElements(array, nullptr);
		}

		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	IntBuffer(JNIEnv* env, jobject buffer) :
		env_(env)
	{
		if (buffer != nullptr)
		{
			elements_ = reinterpret_cast<jint*>(env->GetDirectBufferAddress(buffer));
		}

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
		return elements_ != nullptr ? reinterpret_cast<std::int32_t*>(&elements_[offset_]) : nullptr;
	}

	operator std::int32_t*()
	{
		return elements_ != nullptr ? reinterpret_cast<std::int32_t*>(&elements_[offset_]) : nullptr;
	}

	operator const std::uint32_t*() const
	{
		return elements_ != nullptr ? reinterpret_cast<std::uint32_t*>(&elements_[offset_]) : nullptr;
	}

	operator std::uint32_t*()
	{
		return elements_ != nullptr ? reinterpret_cast<std::uint32_t*>(&elements_[offset_]) : nullptr;
	}

private:
	JNIEnv* env_;
	jintArray array_ = nullptr;
	jint* elements_ = nullptr;
	jint offset_ = 0;
};

class LongBuffer
{
public:
	LongBuffer(JNIEnv* env, jlongArray array, jint offset) :
		env_(env), array_(array), offset_(offset)
	{
		if (array != nullptr)
		{
			elements_ = env->GetLongArrayElements(array, nullptr);
		}

		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	LongBuffer(JNIEnv* env, jobject buffer) :
		env_(env)
	{
		if (buffer != nullptr)
		{
			elements_ = reinterpret_cast<jlong*>(env->GetDirectBufferAddress(buffer));
		}

		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	LongBuffer(LongBuffer const&) = delete;

	~LongBuffer()
	{
		if (array_ != nullptr)
		{
			env_->ReleaseLongArrayElements(array_, elements_, 0);
		}
	}

	operator const std::int64_t*() const
	{
		return elements_ != nullptr ? reinterpret_cast<std::int64_t*>(&elements_[offset_]) : nullptr;
	}

	operator std::int64_t*()
	{
		return elements_ != nullptr ? reinterpret_cast<std::int64_t*>(&elements_[offset_]) : nullptr;
	}

	operator const std::uint64_t*() const
	{
		return elements_ != nullptr ? reinterpret_cast<std::uint64_t*>(&elements_[offset_]) : nullptr;
	}

	operator std::uint64_t*()
	{
		return elements_ != nullptr ? reinterpret_cast<std::uint64_t*>(&elements_[offset_]) : nullptr;
	}

private:
	JNIEnv* env_;
	jlongArray array_ = nullptr;
	jlong* elements_ = nullptr;
	jint offset_ = 0;
};

class FloatBuffer
{
public:
	FloatBuffer(JNIEnv* env, jfloatArray array, jint offset) :
		env_(env), array_(array), offset_(offset)
	{
		if (array != nullptr)
		{
			elements_ = env->GetFloatArrayElements(array, nullptr);
		}

		if (env->ExceptionCheck())
		{
			env->ExceptionDescribe();
		}
	}

	FloatBuffer(JNIEnv* env, jobject buffer) :
		env_(env)
	{
		if (buffer != nullptr)
		{
			elements_ = reinterpret_cast<jfloat*>(env->GetDirectBufferAddress(buffer));
		}

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

	operator const float*() const
	{
		return elements_ != nullptr ? reinterpret_cast<float*>(&elements_[offset_]) : nullptr;
	}

	operator float*()
	{
		return elements_ != nullptr ? reinterpret_cast<float*>(&elements_[offset_]) : nullptr;
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

	operator const unsigned char*() const
	{
		return elements_ != nullptr ? reinterpret_cast<unsigned char*>(elements_ + offset_) : nullptr;
	}

	operator unsigned char*()
	{
		return elements_ != nullptr ? reinterpret_cast<unsigned char*>(elements_ + offset_) : nullptr;
	}

private:
	JNIEnv* env_;
	jbooleanArray array_ = nullptr;
	jboolean* elements_ = nullptr;
	jint offset_ = 0;
};

template<int Size>
class IntRegion
{
public:
	IntRegion(JNIEnv* env, jintArray array, jint offset) :
		env_(env), array_(array), offset_(offset)
	{
	}

	IntRegion(IntRegion const&) = delete;

	~IntRegion()
	{
		if (array_ != nullptr)
		{
			env_->SetIntArrayRegion(array_, offset_, Size, buf_.data());
		}
	}

	operator const std::int32_t* () const
	{
		return array_ != nullptr ? reinterpret_cast<std::int32_t*>(buf_.data()) : nullptr;
	}

	operator std::int32_t* ()
	{
		return array_ != nullptr ? reinterpret_cast<std::int32_t*>(buf_.data()) : nullptr;
	}

	operator const std::uint32_t* () const
	{
		return array_ != nullptr ? reinterpret_cast<std::uint32_t*>(buf_.data()) : nullptr;
	}

	operator std::uint32_t* ()
	{
		return array_ != nullptr ? reinterpret_cast<std::uint32_t*>(buf_.data()) : nullptr;
	}

private:
	JNIEnv* env_;
	jintArray array_ = nullptr;
	jint offset_ = 0;
	std::array<jint, Size> buf_;
};

#define ValidateArraySize_I(array, offset, minSize) \
	if (array != nullptr && (env->GetArrayLength(array) - (offset) < (minSize))) { \
		env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "'" #array "': insufficient array size."); return 0; }

#define ValidateBufferSize_I(buffer, minSize) \
	if (buffer != nullptr) { \
		jlong _capacity_ = env->GetDirectBufferCapacity(buffer); \
		if (_capacity_ == -1) { \
			env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "'" #buffer "' is not a direct buffer."); return 0; } \
		if (_capacity_ < (minSize)) { \
			env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "'" #buffer "': insufficient buffer size."); return 0; } \
	}

#define ValidateArraySize_V(array, offset, minSize) \
	if (array != nullptr && (env->GetArrayLength(array) - (offset) < (minSize))) { \
		env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "'" #array "': insufficient array size."); return; }

#define ValidateBufferSize_V(buffer, minSize) \
	if (buffer != nullptr) { \
		jlong _capacity_ = env->GetDirectBufferCapacity(buffer); \
		if (_capacity_ == -1) { \
			env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "'" #buffer "' is not a direct buffer."); return; } \
		if (_capacity_ < (minSize)) { \
			env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "'" #buffer "': insufficient buffer size."); return; } \
	}