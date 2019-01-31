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

const int numL = 2;
int cero = 0;

//propiedades de la luz ambiental
vec3 Ia= vec3(0.2,0.2,0.2);

//propiedades de la luz difusa
const vec3 Id [numL] = vec3[numL](vec3(1.0,1.0,1.0), vec3(1.0,1.0,1.0));

//propiedades de la luz especular
const vec3 Is [numL] = vec3[numL](vec3(1,1,1), vec3 (1,1,1));

//posicion de la luz
const vec3 LPos [numL] = vec3[numL](vec3 (2,0,0), vec3 (-3,0,0)); 

//posicion que la luz ilumina
vec3 pos; 

//propiedades del objeto
vec3 Ka; //propiedad ambiental del objeto
vec3 Kd; //propiedad difusa del objeto
vec3 Ke; //propiedad emisiva del objeto
vec3 Ks=vec3(1.0); //propiedad especular del objeto
float nExp=10;

vec3 attenuateIntensity (vec3 I, vec3 LightPos){
	float attenuateFactor = 0.3;
	I = clamp(I/pow(distance(pos, LightPos)*attenuateFactor, 2),0,1);
	//
	return I;
}

vec3 shade(){
	vec3 c=vec3(0);

	//ambiental

	//c=clamp(Ia*Ka,0,1);  //clamp para no quemar la escena

	//Id[cero] = attenuateIntensity(Id[cero], LPos[cero]);
	//Is[cero] = attenuateIntensity(Is[cero], LPos[cero]);

	for(int i=0;i<numL;i++){
	//difusa

	Id[i] = attenuateIntensity(Id[i], LPos[i]);	
	vec3 L=normalize(LPos[i]-pos); //L es el vector de incidencia, del cual necesitamos su componente negativa (para especular)
	c+=clamp(Id[i]*Kd*dot(L,normalVertex),0,1);
	

	//especular

	Is[i] = attenuateIntensity(Is[i], LPos[i]);
	vec3 R=normalize(reflect(-L,normalVertex)); //R es el vector de reflexión
	vec3 V=normalize(-pos); //V es el vector de posición del observador
	float factor=clamp(dot(R,V),0.001,1);
	c+=clamp(Is[i]*Ks*pow(factor,nExp),0,1);
	}
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
	//Ke=texture(emiTex, TexCoord).xyz;

	outColor = vec4(shade(), 1.0);   
}
