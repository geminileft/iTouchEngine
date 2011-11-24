uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

attribute vec4 aPosition;
attribute vec2 aTexture;
attribute vec2 aCoords;

varying vec2 vTextureCoord;

void main()
{
    vec2 newCoords = aCoords;
    mat4 mvp = uProjectionMatrix * uViewMatrix;
    gl_Position = mvp * aPosition;
	vTextureCoord=aTexture;
}
