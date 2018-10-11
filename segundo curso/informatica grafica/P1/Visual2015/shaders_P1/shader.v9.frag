//Version 1 del shader de fragmentos
//PARA DEPURAR CODIFICAMOS LA POSICION, NORMAL, TEXTURA, ETC AL OUTCOLOR
#version 330 core



out vec4 outColor;

in vec3 colorVertex;


void main()
{
	outColor = vec4(colorVertex,0);
}
