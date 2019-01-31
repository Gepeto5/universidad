//Version 1 del shader de vertices
#version 330 core

#define M_PI 3.14159265

in vec3 inPos;
uniform mat4 model;
uniform mat4 modelViewProj; // la calcula directamente ig lib

out vec3 colorVertex;

void main()
{
	if(mod(gl_VertexID,4.0) == 0.0) // Cambiamos el dato de color del vertice segun el numero de su id
	{
		colorVertex = vec3(1,0,0);
	}
	else if(mod(gl_VertexID,4.0) == 1.0)
	{
		colorVertex = vec3(0,1,0);
	}
	else if(mod(gl_VertexID,4.0) == 2.0)
	{
		colorVertex = vec3(0,0,1);
	}
	else
	{
		colorVertex = vec3(1,1,1);
	}
	gl_Position = modelViewProj * vec4(inPos,1);
}