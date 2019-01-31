#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"

class Esfera {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
	double r;
public:
	Esfera() :pos(Vector3D(0, 0, 0)), col(Vector3D(1, 0, 0)), vel(Vector3D(0, 0, 0)), r(0.3) {}
	Esfera(Vector3D pos, Vector3D col = (1,0,0), Vector3D vel = Vector3D(), double r = 0.3) :
		pos(pos), 
		col(col), 
		vel(vel), 
		r(r) {}
	~Esfera() {}
	inline double getR() { return r; }
	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() { return col; }
	inline Vector3D getVel() { return vel; }
	inline void setR(double a) { r = a; }
	inline void setPos(Vector3D a) { pos = a; }
	inline void setCol(Vector3D a) { col = a; }
	inline void setVel(Vector3D a) { vel = a; }

	void render();
	void update(double dt);
};
//#endif