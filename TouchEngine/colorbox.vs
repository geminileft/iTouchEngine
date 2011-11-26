uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

attribute vec2 aPosition;
attribute vec4 aVertices;

void main() {
	mat4 identityMatrix = mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, aPosition.x,aPosition.y,0,1);
	gl_Position = (uProjectionMatrix * (uViewMatrix * (identityMatrix))) * aVertices;
	gl_PointSize = 1.0;
}
