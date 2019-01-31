#version 330 core
#pragma OPENCL SELECT_ROUNDING_MODE rtp

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



//luz direccional difusa y especular
vec3 LD_dir = vec3(-1,0,0);
vec3 LD_I_dif = vec3(1,1,1);
vec3 LD_I_spe = vec3(1,1,1);

//luz focal difusa y especular
vec3 LF_pos = vec3 (0,0,0);
vec3 LF_dir = vec3 (0,0,-1);
vec3 LF_I_dif = vec3(1,1,1);
vec3 LF_I_spe = vec3(1,1,1);
float LF_angle = 5.0* 3.1415926535*0.0055555; //15 grados

//posicion que la luz ilumina
vec3 pos; 

//propiedades del objeto
vec3 Ka; //propiedad ambiental del objeto
vec3 Kd; //propiedad difusa del objeto
vec3 Ke; //propiedad emisiva del objeto
vec3 Ks=vec3(1.0); //propiedad especular del objeto
float nExp=10;

vec3 attenuateIntensity (vec3 I, vec3 lightPos){
	float attenuateFactor = 0.3;
	I = clamp(I/pow(distance(pos, lightPos)*attenuateFactor, 2),0,1);
	//
	return I;
}

vec3 focalIntensity(vec3 I, vec3 lightDir, vec3 L, float beta, float attenuate){	
	//I = pow((dot(lightDir, (-L)) - cos(beta)) / (1 - cos(beta)), attenuate) * I * foo(clamp(lightDir * (-L) - cos(beta), 0, 1)); //por redondeo a la alza
	I = pow((dot(lightDir, (-L)) - cos(beta)) / (1 - cos(beta)), attenuate) * I;
	if(dot(lightDir, (-L)) < cos(beta)) I = vec3(0,0,0) ; //por comparación
	return I;

		//I = clamp(I/pow(distance(pos, LightPos)*attenuateFactor, 2),0,1);
}


vec3 shade(){
	vec3 c=vec3(0);

	//ambiental

	c=clamp(Ia*Ka,0,1);  //clamp para no quemar la escena


	//focal
		
	vec3 LF_L = normalize(LF_pos - pos);
	LF_I_dif = focalIntensity(LF_I_dif, LF_dir, LF_L, LF_angle, 0.1);
	c+=clamp(LF_I_dif*Kd*dot(LF_L,normalVertex),0,1);
	
	LF_I_spe = focalIntensity(LF_I_spe, LF_dir, LF_L, LF_angle, 0.1);
	vec3 LF_R=normalize(reflect(-LF_L,normalVertex)); 
	vec3 LF_V=normalize(-pos);
	float LF_factor=clamp(dot(LF_R,LF_V),0.001,1);
	c+=clamp(LF_I_spe*Ks*pow(LF_factor,nExp),0,1);

	//direccional

	c+=clamp(LD_I_dif*Kd*dot(-LD_dir,normalVertex),0,1);
	
	vec3 LD_R=normalize(reflect(LD_dir,normalVertex)); 
	vec3 LD_V=normalize(-pos);
	float LD_factor=clamp(dot(LD_R,LD_V),0.001,1);
	c+=clamp(LD_I_spe*Ks*pow(LD_factor,nExp),0,1);
	
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
