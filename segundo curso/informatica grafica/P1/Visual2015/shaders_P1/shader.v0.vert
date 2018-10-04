#version 330 core

in vec3 inPos;	

#define M_PI 3.14159265

uniform mat4 model;

void main()
{
	mat4 proj = mat4(1.0);
	float far = 10;
	float near = 0.1;
	float f = 1/tan(M_PI/6.0);

	proj[0].x=f;
	proj[1].y=f;
	proj[2].z=-(far+near)/(far-near);
	proj[2].w=-1;
	proj[3].z=(-2*far*near)/(far-near);
	proj[3].w=0;

	mat4 view = mat4(1.0);
	view[3].z = -6;


	gl_Position = proj * view * model * vec4(inPos,1);
}
