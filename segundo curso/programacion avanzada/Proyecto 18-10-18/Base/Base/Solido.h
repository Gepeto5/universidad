#pragma once

//#ifndef SOLIDO_
//#define SOLIDO_

#include<GL/glut.h>
#include "vector3D.h"
#include <iostream>
using namespace std;

class Solido {
	//protected: no usar si hay encapsulación
	Vector3D pos;
	Vector3D col;
	Vector3D vel;
	Vector3D f;
	double m;
public:

	Solido() :
		pos(Vector3D()),
		vel(),
		col(1, 0, 0),
		m(1) {}
		
	Solido(Vector3D p, Vector3D c = Vector3D(1, 0, 0), Vector3D v = Vector3D(), Vector3D efe = Vector3D(), double eme = 1) :
		pos(p),
		vel(v),
		col(c),
		f(efe),
		m(eme) {}


	inline Vector3D getPos() { return pos; }
	inline Vector3D getCol() {return col;}
	inline Vector3D getVel() {return vel;}
	inline Vector3D getF() { return f; }
	inline double getM() { return m; }
	inline void setPos(Vector3D a) {pos = a;}
	inline void setCol(Vector3D a) {col = a;}
	inline void setVel(Vector3D a) {vel = a;}
	inline void setF(Vector3D a) { f = a; }
	inline void setM(double a) { m = a; }
	void update(double dt);
	virtual void render() /*= 0*/; //virtual no hace una llamada normal a render, ya que considera la posibilidad de que la clase tenga hijos. El 0 significa que no lo implemento (método abstracto) como en las interfaces de Java. Esto significa que no puedo crear objetos de esta clase

	void acumulaFueza(Vector3D fv) { f = f + fv; }

	friend ostream &operator<<(ostream &os, const Solido &c);
};

inline ostream &operator<<(ostream &os, const Solido &c) {
	os << c.pos << endl;
	os << c.vel << endl;
	os << c.col << endl;
	return os;
}

//#endif