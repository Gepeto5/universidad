#version 330 core

out vec4 outColor;
in vec3 colorvertex;
in vec2 texcoord;
uniform sampler2D colorTex;

void main()
{

vec4 colortextura= texture(colorTex,texcoord);
outColor= vec4(colorvertex,0); 


}
