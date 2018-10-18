#pragma once

#include <GL/glut.h>
#include "vector3D.h"
#include "Solido.h"

class Cilindro : public Solido
{
private:
	GLUquadric *quadratic;
	double he;
	double rad;
	int sli;
	int sta;
public:
	Cilindro(float rad1, float rad2);
	~Cilindro() {}
	double getRad() { return rad; }
	double getHe() { return he; }
	inline void setRad(double r) { rad = r; }
	inline void setHe(double h) { he = h; }
	void render();
};