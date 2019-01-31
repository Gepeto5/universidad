#pragma once

#include <GL/glut.h>
#include "vector3D.h"

class Cilindro {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
	GLUquadric *quadratic;
	double he;
	double rad;
	int sli;
	int sta;
public:
	Cilindro():pos(Vector3D()), col(1, 0, 0), vel(), he(1), rad(1), sli(2), sta(2) {};

	Cilindro(Vector3D p, Vector3D c = (1,0,0), Vector3D v = Vector3D(), GLUquadric *quad=gluNewQuadric(), double h = 1, double r = 1, int s1 = 2, int s2 = 2) :
		pos(p),
		vel(v),
		col(c),
		quadratic(quad),
		he(h),
		rad(r),
		sli(s1),
		sta(s2) {}
	~Cilindro() {}
	double getRad() { return rad; }
	double getHe() { return he; }
	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() { return col; }
	inline Vector3D getVel() { return vel; }
	inline void setRad(double r) { rad = r; }
	inline void setHe(double h) { he = h; }
	inline void setPos(Vector3D a) { pos = a; }
	inline void setCol(Vector3D a) { col = a; }
	inline void setVel(Vector3D a) { vel = a; }

	void render();
	void update(double dt);
};