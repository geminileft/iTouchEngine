uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

attribute vec4 aPosition;
attribute vec2 aTexture;


varying mediump vec2 v_texcoord;

void main()
{
    mat4 mvp = uProjectionMatrix * uViewMatrix;
    gl_Position = mvp * aPosition;
	v_texcoord=aTexture;
}
