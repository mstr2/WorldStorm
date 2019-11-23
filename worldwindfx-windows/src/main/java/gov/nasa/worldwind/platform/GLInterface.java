package gov.nasa.worldwind.platform;

import java.nio.Buffer;

public final class GLInterface implements GL {

    @Override
    public native void glActiveTexture(int texture);

    @Override
    public native void glAttachShader(int program, int shader);

    @Override
    public native void glBindAttribLocation(int program, int index, String name);

    @Override
    public native void glBindBuffer(int target, int buffer);

    @Override
    public native void glBindFramebuffer(int target, int framebuffer);

    @Override
    public native void glBindTexture(int target, int texture);

    @Override
    public native void glBufferData(int target, int size, Buffer data, int usage);

    @Override
    public native int glCheckFramebufferStatus(int target);

    @Override
    public native void glClear(int mask);

    @Override
    public native void glColorMask(boolean red, boolean green, boolean blue, boolean alpha);

    @Override
    public native void glCompileShader(int shader);

    @Override
    public native int glCreateProgram();

    @Override
    public native int glCreateShader(int type);

    @Override
    public native void glDeleteBuffers(int n, int[] buffers, int buffers_offset);

    @Override
    public native void glDeleteFramebuffers(int n, int[] framebuffers, int framebuffers_offset);

    @Override
    public native void glDeleteProgram(int program);

    @Override
    public native void glDeleteShader(int shader);

    @Override
    public native void glDeleteTextures(int n, int[] textures, int textures_offset);

    @Override
    public native void glDepthMask(boolean flag);

    @Override
    public native void glDisable(int cap);

    @Override
    public native void glDisableVertexAttribArray(int index);

    @Override
    public native void glDrawArrays(int mode, int first, int count);

    @Override
    public native void glDrawElements(int mode, int count, int type, Buffer indices);

    @Override
    public native void glDrawElements(int mode, int count, int type, int indices);

    @Override
    public native void glEnable(int cap);

    @Override
    public native void glEnableVertexAttribArray(int index);

    @Override
    public native void glFramebufferTexture2D(int target, int attachment, int textarget, int texture, int level);

    @Override
    public native void glGenBuffers(int n, int[] buffers, int buffers_offset);

    @Override
    public native void glGenerateMipmap(int target);

    @Override
    public native void glGenFramebuffers(int n, int[] framebuffers, int framebuffers_offset);

    @Override
    public native void glGenTextures(int n, int[] textures, int textures_offset);

    @Override
    public native String glGetProgramInfoLog(int program);

    @Override
    public native void glGetProgramiv(int program, int pname, int[] params, int params_offset);

    @Override
    public native String glGetShaderInfoLog(int shader);

    @Override
    public native void glGetShaderiv(int shader, int pname, int[] params, int params_offset);

    @Override
    public native void glGetUniformiv(int program, int location, int[] params, int params_offset);

    @Override
    public native int glGetUniformLocation(int program, String name);

    @Override
    public native void glLineWidth(float width);

    @Override
    public native void glLinkProgram(int program);

    @Override
    public native void glPolygonOffset(float factor, float units);

    @Override
    public native void glReadPixels(int x, int y, int width, int height, int format, int type, Buffer pixels);

    @Override
    public native void glShaderSource(int shader, String source);

    @Override
    public native void glTexImage2D(int target,
            int level,
            int internalformat,
            int width,
            int height,
            int border,
            int format,
            int type,
            Buffer pixels);

    @Override
    public native void glTexParameteri(int target, int pname, int param);

    @Override
    public native void glUniform1f(int location, float x);

    @Override
    public native void glUniform2f(int location, float x, float y);

    @Override
    public native void glUniform3f(int location, float x, float y, float z);

    @Override
    public native void glUniform4f(int location, float x, float y, float z, float w);

    @Override
    public native void glUniform1fv(int location, int count, float[] v, int v_offset);

    @Override
    public native void glUniform2fv(int location, int count, float[] v, int v_offset);

    @Override
    public native void glUniform3fv(int location, int count, float[] v, int v_offset);

    @Override
    public native void glUniform4fv(int location, int count, float[] v, int v_offset);

    @Override
    public native void glUniform1i(int location, int x);

    @Override
    public native void glUniform2i(int location, int x, int y);

    @Override
    public native void glUniform3i(int location, int x, int y, int z);

    @Override
    public native void glUniform4i(int location, int x, int y, int z, int w);

    @Override
    public native void glUniform1iv(int location, int count, int[] v, int v_offset);

    @Override
    public native void glUniform2iv(int location, int count, int[] v, int v_offset);

    @Override
    public native void glUniform3iv(int location, int count, int[] v, int v_offset);

    @Override
    public native void glUniform4iv(int location, int count, int[] v, int v_offset);

    @Override
    public native void glUniformMatrix3fv(int location, int count, boolean transpose, float[] value, int value_offset);

    @Override
    public native void glUniformMatrix4fv(int location, int count, boolean transpose, float[] value, int value_offset);

    @Override
    public native void glUseProgram(int program);

    @Override
    public native void glVertexAttribPointer(int index, int size, int type, boolean normalized, int stride, Buffer pointer);

    @Override
    public native void glVertexAttribPointer(int index, int size, int type, boolean normalized, int stride, int pointer);

    @Override
    public native void glViewport(int x, int y, int width, int height);

}