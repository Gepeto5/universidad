#pragma once


#include <GL/glut.h>
#include "vector3d.h"


class Cubo {
private:
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
public:
	Vector3D getPos();
	Vector3D getCol();
	Vector3D getVel();
	void setPos(Vector3D a);
	void setCol(Vector3D a);
	void setVel(Vector3D a);
	void renderCubo();

};

