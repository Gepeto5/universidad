#pragma once
#include "solido.h"
class Rosco : public Solido {
	double r0, r1;
public:
	Rosco() :Solido(), r0(0.25), r1(0.5) {}
	Rosco(const Rosco &r) :Solido(r), r0(r.r0), r1(r.r1) {}
	Rosco* clone() {
		return new Rosco(*this);
	}
	~Rosco();
	double getR0() { return r0; }
	double getR1() { return r1; }
	void setR0(double d) { r0 = d; }
	void setR1(double d) { r1 = d; }
	void render() {
		glPushMatrix();
		glTranslatef(this->getPos().getX(), (*this).getPos().getY(), getPos().getZ());
		//glRotatef(t * 5, 0.0, 1.0, 0.0);
		glColor3f(getCol().getX(), getCol().getY(), getCol().getZ());
		glutSolidTorus(r0, r1, 10, 10);
		glPopMatrix();
	}
};

