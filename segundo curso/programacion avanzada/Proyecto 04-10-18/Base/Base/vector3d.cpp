#include "vector3d.h"

double Vector3D::getX() {
	return x;
}
void Vector3D::setX(double d) {
	x = d;
}
double Vector3D::getY() {
	return y;
}
void Vector3D::setY(double d) {
	y = d;
}
double Vector3D::getZ() {
	return z;
}
void Vector3D::setZ(double d) {
	z = d;
}
Vector3D Vector3D::operator+(Vector3D a) {
	Vector3D r;
	r.x = a.x + x;
	r.y = a.y + y;
	r.z = a.z + z;
	return r;
}
Vector3D Vector3D::operator*(double a) {
	Vector3D r;
	r.x = a * x;
	r.y = a * y;
	r.z = a * z;
	return r;
}
double Vector3D::operator*(Vector3D v) {//Volvemos a usar *, dependiendo del tipo de argumento entrará en una función u otra
	double r;
	r = x * v.x + y * v.y + z * v.z;
	return r;
}