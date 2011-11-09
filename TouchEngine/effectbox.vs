uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;
attribute vec2 position;
attribute vec4 vertices;
uniform float distance;

void main() {
	mat4 identityMatrix = mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, position.x,position.y,0,1);
	vec4 newVertex = vec4(vertices.x * distance, vertices.y * distance, vertices.z, vertices.w);
	gl_Position = (uProjectionMatrix * (uViewMatrix * (identityMatrix))) * newVertex;
}
