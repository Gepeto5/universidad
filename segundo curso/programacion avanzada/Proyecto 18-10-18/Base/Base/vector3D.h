//#pragma once //es equivalente a usar ifndef y tal, internamente hacen lo mismo (que el código se ejecute solo una vez)

#ifndef VECTOR3D_
#define VECTOR3D_
#include <iostream>
using namespace std;

class Vector3D {
private:
	double x, y, z;
public:
	//inline hace que el método sea tan rápido como acceder al campo directamente, no es aconsejable para métodos que
	//son muy grandes ya que lo que hace es sustituir el código (duplicarlo) allá donde se llame en lugar de hacer una llamada.
	//Si en el examen se preguntan los métodos de acceso, se obtendrá más nota si ponemos inline y lo explicamos


	//Vector3D() :x(0), y(0), z(0) {}	//Constructor por defecto de forma super eficiente, pero ya no es necesario ya que al darle parámetros al de abajo, ya no es necesario


	/*Vector3D(double x, double y, double z) {	//Constructor, (no lleva void ni nada por el estilo, no es un método)
		this->x = x;//Hay que hacerlo con la flecha porque el atributo y el parámetro se llaman igual (si se llamasen distinto no sería necesario)
		this->y = y;
		this->z = z;
	}*/	//Constructor no eficiente


	Vector3D(double x=0, double y=0, double z=0) :x(x), y(y), z(z) {}	//Se les da a los parámetros unos valores de inicialización por defecto, al hacer esto puedo juntar varios constructores en uno
																		//En este caso tenemos cuatro constructores en uno
	inline double getX() {return x;}
	inline void setX(double d) {x = d;}
	inline double getY() {return y;}
	inline void setY(double d) {y = d;}
	inline double getZ() {return z;}
	inline void setZ(double d) {z = d;}
	friend ostream &operator<<(ostream &os, const Vector3D &v); // con esto no hace falta poner get en el ostream

	Vector3D operator+(Vector3D a);
	Vector3D operator-(Vector3D a);
	Vector3D operator/(double a);
	Vector3D operator*(double a);//producto escalar
	double operator*(Vector3D v);//producto por escalar
};

inline ostream &operator<<(ostream &os, const Vector3D &v) {
	os << v.x << "," << v.y << "," << v.z;
	return os;
}

#endif