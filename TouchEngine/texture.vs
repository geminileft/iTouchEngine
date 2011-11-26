uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

attribute vec4 aVertices;
attribute vec2 aTextureCoords;
attribute vec2 aPosition;

varying vec2 vTextureCoord;

void main() {
	mat4 identityMatrix = mat4(1.0,0.0,0.0,0.0, 0.0,1.0,0.0,0.0, 0.0,0.0,1.0,0.0, aPosition.x,aPosition.y,0.0,1.0);
	gl_Position = (uProjectionMatrix * (uViewMatrix * (identityMatrix))) * aVertices;
	vTextureCoord = aTextureCoords;
}
