//Version 1 del shader de vertices
#version 330 core

#define M_PI 3.14159265

in vec3 inPos;
uniform mat4 model;
uniform mat4 modelViewProj; // la calcula directamente ig lib

void main()
{
	gl_Position = modelViewProj * vec4(inPos,1);
}