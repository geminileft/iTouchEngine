uniform mat4 uProjectionMatrix;
uniform mat4 uViewMatrix;

attribute vec4 aPosition;
attribute vec2 aTexture;
attribute vec2 aCoords;

varying vec2 vTextureCoord;

void main() {
	mat4 identityMatrix = mat4(1.0,0.0,0.0,0.0, 0.0,1.0,0.0,0.0, 0.0,0.0,1.0,0.0, aCoords.x,aCoords.y,0.0,1.0);
	gl_Position = (uViewMatrix * (uProjectionMatrix * (identityMatrix))) * aPosition;
	vTextureCoord = aTexture;
}
