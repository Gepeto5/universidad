//Version 1 del shader de vertices
#version 330 core

#define M_PI 3.14159265

in vec3 inPos; // atributo de posicion de los vertices
in vec3 inColor; // atributo de color que llega de los vertices

uniform mat4 modelViewProj; // la calcula directamente ig lib

out vec3 colorVertex;//variable variante que usamos para pasarle al shader de fragmentos el color asociado a cada vertice

void main()
{
	colorVertex = inColor; // Le pasamos al shader de fragmentos el color que tenia cada vertice por defecto (las variables variantes deben llamarse igual en el de vertices y fragmentos) 
	gl_Position = modelViewProj * vec4(inPos,1);
}