//#pragma once
#ifndef VECTOR3D__
#define VECTOR3D__
#include <iostream>
#include <cassert>

using namespace std;

template <class S> class Vector3Dx;

typedef Vector3Dx<double> Vector3D;

typedef Vector3Dx<float>  Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int>    Vector3Di;

template <class S>
class Vector3Dx {
	S x, y, z;
public:
	Vector3Dx() :Vector3Dx(0, 0, 0) {}
	//Vector3Dx(S x, S y, S z) :x(x), y(y), z(z) {}
	Vector3Dx(const S &x, const S &y, const S &z) :x(x), y(y), z(z) {}
	Vector3Dx(const Vector3Dx<S> &v) :x(v.x), y(v.y), z(v.z) {}
	Vector3Dx<S> *clone() { return new Vector3Dx<S>(*this); }
	Vector3Dx<S> operator+(const Vector3Dx<S> &b) {
		Vector3Dx<S> ret;
		ret.x = x + b.x;
		ret.y = y + b.y;
		ret.z = z + b.z;
		return ret;
	}
	Vector3Dx<S> operator-(const Vector3Dx<S> &b) {
		Vector3Dx<S> ret;
		ret.x = x - b.x;
		ret.y = y - b.y;
		ret.z = z - b.z;
		return ret;
	}
	Vector3Dx<S> operator*(const S &d) {
		Vector3Dx<S> ret;
		ret.x = x * d;
		ret.y = y * d;
		ret.z = z * d;
		return ret;
	}
	Vector3Dx<S> operator/(S d) {
		Vector3Dx<S> ret;
		ret.x = x / d;
		ret.y = y / d;
		ret.z = z / d;
		return ret;
	}
	inline S &getX() { return x; }
	inline S &getY() { return y; }
	inline S &getZ() { return z; }
	inline void setX(const double &px) { x = px; }
	inline void setY(const double &py) { y = py; }
	inline void setZ(const double &pz) { z = pz; }
	inline S operator * (const Vector3Dx<S> &v2) {
		Vector3Dx &v1 = *this;
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}
	inline Vector3Dx<S> crossProduct(const Vector3Dx<S> &v2) {
		Vector3Dx<S> &v1 = *this;
		return Vector3Dx<S>(v1.y*v2.z - v1.z*v2.y,
			v1.z*v2.x - v1.x*v2.z,
			v1.x*v2.y - v1.y*v2.x);
	}
	inline S lengthSquared() {
		return x * x + y * y + z * z;
	}

	inline S length() {
		return sqrt(lengthSquared());
	}
	inline bool equalsZero(double a) {
		//float almost never is 0.0
		//This value shoud be a const
		return fabs(a)<0.00001;
	}
	inline void normalize() {
		S magnitude = length();
		//assert(!equalsZero(magnitude));
		if (equalsZero(magnitude))
			throw runtime_error("Normal muy pequeña");

		magnitude = 1.0f / magnitude;

		x *= magnitude;
		y *= magnitude;
		z *= magnitude;
	}
	friend ostream &operator<<(ostream &os, const Vector3Dx<S> &v);
};
/*
template <class T>
inline ostream &operator<<(ostream &os, const Vector3D<T> &v) {
os << v.x << "," << v.y << "," << v.z;
return os;
}
*/
//template ostream &operator<< (ostream &os, const Vector3Dx<double> &v);


inline ostream &operator<<(ostream &os, const Vector3Dd &v) {
	os << v.x << "," << v.y << "," << v.z;
	return os;
}
inline ostream &operator<<(ostream &os, const Vector3Df &v) {
	os << v.x << "," << v.y << "," << v.z;
	return os;
}
inline ostream &operator<<(ostream &os, const Vector3Di &v) {
	os << v.x << "," << v.y << "," << v.z;
	return os;
}

#endif // !VECTOR3D__
/*
//Devolver constante de un objeto mutable v
class Vector3D {
	const double &getX() { return x; }
	double &getY() { return y; }
	.......
};
//Objeto mutable ya que no se declara con const
Vector3D v(1, 2, 3);

const double &d = v.getX();
d = 4;///ERROR d es constante
double &c = v.getY();
c = 7;


//Devolver valores a objetos const v
class Vector3D {
	double getX() { return x; }
	double getY() const { return y; }
	.......
};
//Objeto const v
const Vector3D v(1, 2, 3);
double d = v.getX();//No se pude hacer v es constante
double c = v.getY();//se puede hacer ya que getY() est permitido en const
*/