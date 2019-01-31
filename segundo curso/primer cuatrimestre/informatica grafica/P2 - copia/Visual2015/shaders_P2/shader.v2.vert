#version 330 core

in vec3 inPos;	
in vec3 inColor;
in vec3 inNormal;

uniform mat4 modelViewProj;
uniform mat4 modelView;
uniform mat4 normal;

out vec3 color;
out vec3 normalOut;
out vec3 posOut;



void main()
{

	posOut=(modelView*vec4 (inPos,1.0)).xyz;
	normalOut= normalize((normal*vec4(inNormal,0)).xyz);
	color = inColor;	
	gl_Position =  modelViewProj * vec4 (inPos,1.0);
}
