#pragma once
#include <GL/glut.h>
#include "solido.h"

class Pared : public Solido {
	Vector3D dim;
	bool vertical;
public:
	//x=longitud, y=altura, z=profundidad
	Pared(double x = 4, double y = 3, double z = 0.1) :dim(Vector3D(x, y, z)), vertical(false) {}
	Pared(const Pared &p) :Solido(p), dim(p.dim), vertical(p.vertical) {}
	Pared* clone() {
		return new Pared(*this);
	}
	virtual ~Pared();
	void setVertical(bool b) { vertical = b; }
	bool getVertical() { return vertical; }
	void render() {
		glPushMatrix();
		glTranslatef(this->getPos().getX(), this->getPos().getY(), this->getPos().getZ());
		glTranslatef(0, dim.getY() / 2.0, 0);
		glRotatef(vertical ? 90 : 0, 0, 1, 0);
		glColor3f(this->getCol().getX(), this->getCol().getY(), this->getCol().getZ());
		glScalef(dim.getX(), dim.getY(), dim.getZ());
		glutSolidCube(1);
		glPopMatrix();
	}
	friend ostream &operator<<(ostream &os, const Pared &c);
};
inline ostream &operator<<(ostream &os, const Pared &c) {
	os << static_cast<const Solido&>(c);
	os << c.dim << endl;
	return os;
}

