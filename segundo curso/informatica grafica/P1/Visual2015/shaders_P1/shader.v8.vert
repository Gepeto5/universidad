//Version 1 del shader de vertices
#version 330 core

#define M_PI 3.14159265

in vec3 inNormal;
in vec3 inPos;									// atributo de posicion de los vertices
in vec3 inColor;								// atributo de color que llega de los vertices

uniform mat4 modelViewProj;						// la calcula directamente ig lib

out vec3 colorVertex;							//variable variante que usamos para pasarle al shader de fragmentos el color asociado a cada vertice

void main()
{
	colorVertex = inNormal;						// Le pasamos al shader de fragmentos las normales, hay tres caras que no se ven porque apuntan a los ejes en negativo
	gl_Position = modelViewProj * vec4(inPos,1);
}