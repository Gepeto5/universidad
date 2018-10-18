#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"

class Solido {
	//protected: no usar si hay encapsulación
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
public:

	Solido() :
		pos(Vector3D()),
		vel(),
		col(1, 0, 0) {}
	Solido(Vector3D p, Vector3D c = Vector3D(1, 0, 0),Vector3D v = Vector3D()) :
		pos(p),
		vel(v),
		col(c) {}


	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() {return col;}
	inline Vector3D getVel() {return vel;}
	inline void setPos(Vector3D a) {pos = a;}
	inline void setCol(Vector3D a) {col = a;}
	inline void setVel(Vector3D a) {vel = a;}
	void update(double dt);
};
//#endif