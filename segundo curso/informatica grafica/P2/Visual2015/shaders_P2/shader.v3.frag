#version 330 core

out vec4 outColor;

uniform sampler2D colorTex;
uniform sampler2D emiTex;
uniform sampler2D specularTex;

in vec2 TexCoord;	
in vec3 normalOut;
in vec3 posOut;
in vec3 color;


//variables locales I
vec3 normalVertex;

//propiedades de la luz
vec3 Ia=vec3(0.2,0.2,0.2); //intensidad ambiental
vec3 Id= vec3(1,1,1); //intensidad difusa
vec3 LPos=vec3(3,0,0); //posicion de la luz
vec3 pos; //posicion que la luz ilumina
vec3 Is=vec3(1,1,1); //intensidad especular de la luz

//propiedades del objeto
vec3 Ka; //propiedad ambiental del objeto
vec3 Kd; //propiedad difusa del objeto
vec3 Ke; //propiedad emisiva del objeto
vec3 Ks=vec3(1.0); //propiedad especular del objeto
float nExp=10;

vec3 shade(){

vec3 c=vec3(0);

//ambiental
c=clamp(Ia*Ka,0,1);  //clamp para no quemar la escena

//difusa
vec3 L=normalize(LPos-pos);
c+=clamp(Id*Kd*dot(L,normalVertex),0,1);

//especular
vec3 R=normalize(reflect(-L,normalVertex));
vec3 V=normalize(-pos);
float factor=clamp(dot(R,V),0.001,1);
c+=clamp(Is*Ks*pow(factor,nExp),0,1);

c+=Ke;
return c; //c es el color

}

void main()
{
	normalVertex= normalize(normalOut);
	pos=posOut;
	Ka=texture(colorTex, TexCoord).xyz;
	Kd=texture(colorTex, TexCoord).xyz;
	Ks=texture(specularTex, TexCoord).xyz;
	Ke=texture(emiTex, TexCoord).xyz;

	outColor = vec4(shade(), 1.0);   
}
