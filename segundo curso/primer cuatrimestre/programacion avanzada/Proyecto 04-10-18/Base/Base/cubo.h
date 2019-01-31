#pragma once


#include <GL/glut.h>
#include "vector3d.h"


class Cubo {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
	double s;
public:
	/*
	Cubo() : pos(Vector3D(0, 0, 0)), col(Vector3D(0, 0, 0)), vel(Vector3D(0, 0, 0)), s(0) {}
	Cubo(Vector3D pos, Vector3D col, Vector3D vel, double s) : pos(pos), col(col), vel(vel), s(s) {}
	*/
	//Cubo() : pos(Vector3D(0, 0, 0)), col(Vector3D(0, 0, 0)), vel(Vector3D(0, 0, 0)), s(0) {}
	Cubo(Vector3D pos = Vector3D(0, 0, 0), Vector3D col = Vector3D(0, 0, 0), Vector3D vel = Vector3D(0, 0, 0), double s = 0) : pos(Vector3D(pos.getX(),pos.getY(),pos.getZ())), col(Vector3D(col.getX(), col.getY(), col.getZ())), vel(Vector3D(vel.getX(), vel.getY(), vel.getZ())), s() {}
	inline double getS() { return s; }
	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() { return col; }
	inline Vector3D getVel() { return vel; }
	inline void setPos(Vector3D a) { pos = a; }
	inline void setCol(Vector3D a) { col = a; }
	inline void setVel(Vector3D a) { vel = a; }
	inline void setS(double a) { s = a; }
	inline void render();
	inline void update(double dt);
};

