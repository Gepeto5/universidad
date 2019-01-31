//Version 1 del shader de fragmentos
#version 330 core



out vec4 outColor;


void main()
{
	float temp = mod(gl_PrimitiveID,2.0);

	outColor = vec4(0,0,0,0) + vec4(1,0,0,0)*temp;//Pinta solo los impare



	/*Hay que evitar estructuras de control, ver arriba para solucion mejor
	if(mod(gl_PrimitiveID,2.0) == 0) // Si la primitiva tiene un id par lo pinta en rojo, si no en azul
	{
		outColor = vec4(1,0,0,0);
	}
	else if(mod(gl_PrimitiveID,4.0) == 1.0)
	{
		outColor = vec4(0,0,1,0);
	}
	*/
	
}
