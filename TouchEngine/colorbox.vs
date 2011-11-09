uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;
attribute vec2 position;
attribute vec4 vertices;

void main() {
	mat4 identityMatrix = mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, position.x,position.y,0,1);
	gl_Position = (uProjectionMatrix * (uViewMatrix * (identityMatrix))) * vertices;
	gl_PointSize = 1.0;
}
