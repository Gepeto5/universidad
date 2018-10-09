//#pragma once es la version moderna de idndef
#ifndef VECTOR3D
#define VECTOR3D

//#include <GL/glut.h>
//#include "solido.h"

class Vector3D {
private:
	double x, y, z;
public:
	 double getX();
	void setX(double d);
	double getY();
	void setY(double d);
	double getZ();
	void setZ(double d);
	Vector3D operator+(Vector3D a);
	Vector3D operator*(double a);
	double operator*(Vector3D v);//Volvemos a usar *, dependiendo del tipo de argumento entrará en una función u otra


};
#endif VECTOR3D