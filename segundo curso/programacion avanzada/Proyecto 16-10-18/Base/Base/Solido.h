#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"

class Solido {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
public:
	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() {return col;}
	inline Vector3D getVel() {return vel;}
	inline void setPos(Vector3D a) {pos = a;}
	inline void setCol(Vector3D a) {col = a;}
	inline void setVel(Vector3D a) {vel = a;}

	void renderTetera();
	void renderCubo();
};
//#endif