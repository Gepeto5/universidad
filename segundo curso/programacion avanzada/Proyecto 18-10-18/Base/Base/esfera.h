#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"
#include "Solido.h"

class Esfera :public Solido {
private:

	double r;
public:
	Esfera() : Solido(), r(0.25) {}
	Esfera(Vector3D p, Vector3D c = Vector3D(1, 0, 0), Vector3D v = Vector3D(), double d = 0.25) :
		Solido(p, c, v),
		r(d) {}

	~Esfera() {}
	inline double getR() { return r; }
	inline void setR(double a) { r = a; }
	void render();
};
//#endif