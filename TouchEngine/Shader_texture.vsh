//
//  Shader.vsh
//  Tutorial6
//
//  Created by Chris Greening on 28/09/2010.
//

attribute vec4 aPosition;
attribute vec2 texcoord;
uniform mat4 uProjMatrix;
uniform mat4 uViewMatrix;

varying mediump vec2 v_texcoord;

void main()
{
    mat4 mvp = uProjMatrix * uViewMatrix;
    gl_Position = mvp * aPosition;
	v_texcoord=texcoord;
}
