//Version 1 del shader de vertices
#version 330 core

#define M_PI 3.14159265

in vec3 inPos;
uniform mat4 model;
uniform mat4 proj;
uniform mat4 view;

void main()
{
	gl_Position = proj * view * model * vec4(inPos,1);
}