//Version 1 del shader de vertices
#version 330 core

#define M_PI 3.14159265

in vec3 inPos;
uniform mat4 model;

void main()
{
	mat4 projection = mat4(1.0); //Inicia la matriz identidad, als matrices se definen por columnas
	float far = 10;
	float near = 0.1;
	float apertura = 1/tan(M_PI/6.0); // tangente de 60 grados en radianes

	projection[0].x = apertura;
	projection[1].y = apertura;
	projection[2].z = -(far + near)/(far - near);
	projection[2].w = -1;
	projection[3].z = -(2*far*near)/(far - near);
	projection[3].w = 0;

	mat4 view = mat4(1.0);
	view[3].z = -6.0;

	gl_Position = projection * view * model * vec4(inPos,1);
}