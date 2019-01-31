#pragma once
#include "Solido.h"
#include "plano.h"

class Triangulo : public Plano {
	Vector3D p0, p1, p2;
public:
	Triangulo(Vector3D p0, Vector3D p1, Vector3D p2) :Plano(), p0(p0), p1(p1), p2(p2) {
		Vector3D v0 = p1 - p0;
		Vector3D v1 = p2 - p1;
		Vector3D vn;
		try {
			vn = v0.crossProduct(v1);
			vn.normalize();
			double d = vn * p2;
			this->setA(vn.getX());
			this->setB(vn.getY());
			this->setC(vn.getZ());
			this->setD(d);
		}
		catch(exception &e){
			double d = vn * p2;
			this->setA(vn.getX());
			this->setB(vn.getY());
			this->setC(vn.getZ());
			this->setD(d);
		}
	}
	Triangulo(const Triangulo &t) :Plano(t), p0(t.p0), p1(t.p1), p2(t.p2) {}
	Triangulo* clone() {
		return new Triangulo(*this);
	}
	virtual ~Triangulo() {}

	inline Vector3D getP0() const { return p0; }
	inline Vector3D getP1() const { return p1; }
	inline Vector3D getP2() const { return p2; }
	inline void setP0(Vector3D p0)  { this->p0 = p0; }
	inline void setP1(Vector3D p1)  { this->p1 = p1; }
	inline void setP2(Vector3D p2)  { this->p2 = p2; }

	void render() {
		Vector3D c = this->getCol();
		glColor3f(c.getX(), c.getY(), c.getX());
		Vector3D vn = this->getNormal();
		float vnx = vn.getX();
		float vny = vn.getY();
		float vnz = vn.getZ();
		glBegin(GL_TRIANGLES);
		glNormal3f(vnx, vny, vnz);
		glVertex3f(p0.getX(), p0.getY(), p0.getX());
		glNormal3f(vnx, vny, vnz);
		glVertex3f(p1.getX(), p1.getY(), p1.getX());
		glNormal3f(vnx, vny, vnz);
		glVertex3f(p2.getX(), p2.getY(), p2.getX());
		glEnd();
	}
};