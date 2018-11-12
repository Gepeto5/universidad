#pragma once

#include<GL/glut.h>
#include "vector3D.h"
#include "Solido.h"
#include <iostream>
using namespace std;

class Toro :public Solido {
private:

	double radE;
	double radI;
	int sides;
	int rings;
public:
	Toro() : Solido(), radE(0.25), radI(0.5), sides(50), rings(50) {}
	Toro(Vector3D p, Vector3D c = Vector3D(1, 0, 0), Vector3D v = Vector3D(), double rI = 0.30, int s = 2, int r = 2, double rE = 0.25) :
		Solido(p, c, v),
		radI(rI),
		sides(s),
		rings(r),
		radE(rE) {}

	~Toro() {}
	inline double getRadE() { return radE; }
	inline void setRadE(double a) { radE = a; }
	inline double getRadI() { return radI; }
	inline void setRadI(double a) { radI = a; }
	inline int getSides() { return sides; }
	inline void setSides(int a) { sides = a; }
	inline int getRings() { return rings; }
	inline void setRings(int a) { rings = a; }
	void render();

	friend ostream &operator<<(ostream &os, const Toro &c);
};

inline ostream &operator<<(ostream &os, const Toro &c) {
	os << static_cast<const Solido&>(c);
	os << c.radE << endl;
	os << c.radI << endl;
	os << c.sides << endl;
	os << c.rings << endl;
	return os;
}
