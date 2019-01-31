#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"

class Cubo {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
	double s;
public:
	Cubo():pos(Vector3D()), col(1,0,0), vel(), s(0.25) {}	//Por defecto

	//Cubo(Vector3D pos, Vector3D col, Vector3D vel, double s) :pos(pos), col(col), vel(vel), s(s) {}
	Cubo(Vector3D p, Vector3D c = (1,0,0), Vector3D v = Vector3D(), double d = 0.25) ://En este constructor se ha usado varias formas de inicializar las variables
		//pos(Vector3D(p.getX(), p.getY(), p.getZ())),
		//vel(p.getX(), p.getY(), p.getZ()),
		pos(p),
		vel(v),
		col(c),	//Esta es la mejor y menos costosa
		s(d) {}
	~Cubo() {}
	inline double getS() { return s; }
	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() { return col; }
	inline Vector3D getVel() { return vel; }
	inline void setS(double a) { s = a; }
	inline void setPos(Vector3D a) { pos = a; }
	inline void setCol(Vector3D a) { col = a; }
	inline void setVel(Vector3D a) { vel = a; }

	void render();
	void update(double dt);
};
//#endif