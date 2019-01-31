//Version 1 del shader de fragmentos
#version 330 core



out vec4 outColor;

in vec3 colorVertex;
in vec2 textureCoord;

uniform sampler2D colorTex;

void main()
{
	vec4 colorTextura = texture(colorTex, textureCoord);
	outColor = colorTextura;
}
