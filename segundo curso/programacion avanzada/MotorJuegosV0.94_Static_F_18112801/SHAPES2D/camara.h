#pragma once
#include <cmath>
#include <GL/glut.h>
#include "vector3d.h"
#include "solido.h"

//#define M_PI 3.14159
const double M_PI=3.14159;

inline double rot2rad(double  a) { return a / 180 * M_PI; }

class Camara {
	Vector3D pos;
	Vector3D rot;
public:
	Camara();
	Camara(double x, double y, double z) :pos(Vector3D(x, y, z)) {}
	virtual ~Camara();
	inline Vector3D getPos() const { return pos; }
	inline void setPos(Vector3D pos) { this->pos = pos; }
	inline Vector3D getRot() const { return rot; }
	inline void setRot(Vector3D rot) { this->rot = rot; }
	void render() {
		glTranslatef(-this->getPos().getX(), -this->getPos().getY(), -this->getPos().getZ());
		glRotatef(getRot().getX(), 1, 0, 0);
		glRotatef(getRot().getY(), 0, 1, 0);
		glRotatef(getRot().getZ(), 0, 0, 1);
	}
};
class CamaraFPS : public Camara {
public:
	CamaraFPS(double x = 0, double y = 1.65, double z = 0) :Camara(x, y, z) {}
	void update(double dt) {
		double ry = rot2rad(getRot().getY());
		Vector3D vel = { -sin(ry),0,cos(ry) };
		setPos(getPos() - vel * dt);
	}
	void render() {
		glRotatef(getRot().getX(), 1, 0, 0);
		glRotatef(getRot().getY(), 0, 1, 0);
		glRotatef(getRot().getZ(), 0, 0, 1);
		glTranslatef(-getPos().getX(), -getPos().getY(), -getPos().getZ());
	}
};
class CamaraTPS : public Camara {
	Solido *s;
public:
	CamaraTPS(double x = 0, double y = 1.65, double z = 0) :Camara(x, y, z) {}
	void setSolido(Solido *s) { this->s = s; }
	Solido *getSolido() { return s; }
	void update(double dt) {
		double ry = rot2rad(s->getRot().getY());
		Vector3D vel = { sin(ry),0,cos(ry) };
		cout << "vel=" << vel << endl;
		//s->setVel(vel);
		s->setPos(s->getPos() + vel * dt);
	}
	void updateLateral(double dt) {
		double ry = rot2rad(s->getRot().getY());
		Vector3D newV = { -cos(ry),0,sin(ry) };
		s->setPos(s->getPos() + newV * dt);
	}
	void render() {
		glTranslatef(-this->getPos().getX(), -this->getPos().getY(), -this->getPos().getZ());
		glRotatef(getRot().getX(), 1, 0, 0);
		glRotatef(getRot().getY(), 0, 1, 0);
		glRotatef(getRot().getZ(), 0, 0, 1);

		glRotatef(-s->getRot().getX(), 1, 0, 0);
		glRotatef(-s->getRot().getY(), 0, 1, 0);
		glRotatef(-s->getRot().getZ(), 1, 0, 1);
		glTranslatef(-s->getPos().getX(), -s->getPos().getY(), -s->getPos().getZ());
	}
};
class CamaraFly : public CamaraFPS {
public:
	CamaraFly(double x = 0, double y = 1.65, double z = 0) :CamaraFPS(x, y, z) {}
	void update(double dt) {
		double ry = rot2rad(getRot().getY());
		double rx = rot2rad(getRot().getX());
		Vector3D vel = { -sin(ry)*cos(rx),sin(rx),cos(ry)*cos(rx) };
		setPos(getPos() - vel * dt);
	}
};

