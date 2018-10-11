//Version 1 del shader de fragmentos
#version 330 core



out vec4 outColor;

in vec3 colorVertex;


void main()
{
	outColor = vec4(colorVertex,0);
}
