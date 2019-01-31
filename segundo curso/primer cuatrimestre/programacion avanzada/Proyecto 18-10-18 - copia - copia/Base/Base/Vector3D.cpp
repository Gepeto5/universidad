//Aquí se escribe el interior de los métodos, el header debe incluir las funciones solo a modo de interfaz
#include "vector3D.h"

/*
Vector3D Vector3D::operator+(Vector3D a) {	//Hay que indicar antes del nombre del método que está dentro del namespace de
											//Vector3D, si no no sabe lo que es x o y o z
	Vector3D r;
	r.x = a.x + x;
	r.y = a.y + y;
	r.z = a.z + z;
	return r;
}
*/

Vector3D Vector3D::operator+(Vector3D a) { //Esta manera es más eficiente
	Vector3D r(a.x + x, a.y + y, a.z + z);
	return r;
}
Vector3D Vector3D::operator-(Vector3D a) {	
	Vector3D r;
	r.x = a.x - x;
	r.y = a.y - y;
	r.z = a.z - z;
	return r;
}
Vector3D Vector3D::operator*(double a) {
	Vector3D r;
	r.x = a * x;
	r.y = a * y;
	r.z = a * z;
	return r;
}

Vector3D Vector3D::operator/(double a) {
	Vector3D r;
	r.x = x / a;
	r.y = y / a;
	r.z = z / a;
	return r;
}

double Vector3D::operator*(Vector3D v) {//Volvemos a usar *, dependiendo del tipo de argumento entrará en una función u otra
	double r;
	r = x * v.x + y * v.y + z * v.z;
	return r;
}