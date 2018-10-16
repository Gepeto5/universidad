#pragma once


#include <GL/glut.h>
#include "vector3d.h"


class Esfera {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
	double r;
public:
	Esfera(Vector3D pos = Vector3D(0, 0, 0), Vector3D col = Vector3D(0, 0, 0), Vector3D vel = Vector3D(0, 0, 0), double s = 0) : pos(Vector3D(pos.getX(), pos.getY(), pos.getZ())), col(Vector3D(col.getX(), col.getY(), col.getZ())), vel(Vector3D(vel.getX(), vel.getY(), vel.getZ())), r() {}
	double getR();
	inline void setR(double r) { r = r; }
	Vector3D getPos();
	Vector3D getCol();
	Vector3D getVel();
	void setPos(Vector3D a);
	void setCol(Vector3D a);
	void setVel(Vector3D a);
	void render();
	void update(double dt);
};
