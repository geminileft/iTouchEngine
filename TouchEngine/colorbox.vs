uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

attribute vec2 aCoords;
attribute vec4 aPosition;

void main() {
	mat4 identityMatrix = mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, aCoords.x,aCoords.y,0,1);
	gl_Position = (uProjectionMatrix * (uViewMatrix * (identityMatrix))) * aPosition;
	gl_PointSize = 1.0;
}
