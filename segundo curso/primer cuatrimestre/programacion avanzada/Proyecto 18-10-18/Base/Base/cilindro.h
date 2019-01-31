#pragma once

#include <GL/glut.h>
#include "vector3D.h"
#include "Solido.h"
#include <iostream>
using namespace std;

class Cilindro : public Solido
{
private:
	GLUquadric *quadratic;
	double he;
	double rad;
	int sli;
	int sta;
public:
	Cilindro(float rad1, float rad2);
	~Cilindro() {}
	double getRad() { return rad; }
	double getHe() { return he; }
	inline void setRad(double r) { rad = r; }
	inline void setHe(double h) { he = h; }
	void render();

	friend ostream &operator<<(ostream &os, const Cilindro &c);
};

inline ostream &operator<<(ostream &os, const Cilindro &c) {
	os << static_cast<const Solido&>(c);
	os << c.he << endl;
	os << c.rad << endl;
	os << c.sli << endl;
	os << c.sta << endl;
	return os;
}