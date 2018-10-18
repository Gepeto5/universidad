#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"
#include "Solido.h"

class Cubo :public Solido
{
private:

	double s;
public:

	Cubo() : Solido(), s(0.25){}
	Cubo(Vector3D p, Vector3D c = Vector3D(1, 0, 0), Vector3D v = Vector3D(), double d=0.25) :
		Solido(p,c,v),
		s(d) {}

	~Cubo() {}
	inline double getS() { return s; }
	inline void setS(double a) { s = a; }
	void render();
};
//#endif