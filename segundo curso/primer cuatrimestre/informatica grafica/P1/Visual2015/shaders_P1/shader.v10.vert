#version 330 core

in vec3 inPos;	
in vec3 inColor;
in vec2 inTexCoord;
in vec3 inNormal;


uniform mat4 modelView;
uniform mat4 modelViewProj;


out vec3 colorvertex;
out vec2 texcoord;

void main()
{
	vec4 tempnormal= transpose(inverse(modelView)) * vec4(inNormal,0);
	texcoord=inTexCoord;
	colorvertex= tempnormal.xyz;
	

	gl_Position = modelViewProj * vec4(inPos, 1);
}
