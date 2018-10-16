#include "esfera.h"

Vector3D Esfera::getPos() {
	return pos;
}
Vector3D Esfera::getCol() {
	return col;
}
Vector3D Esfera::getVel() {
	return vel;
}
void Esfera::setPos(Vector3D a) {
	pos = a;
}
void Esfera::setCol(Vector3D a) {
	col = a;
}
void Esfera::setVel(Vector3D a) {
	vel = a;
}
double Esfera::getR() {
	return r;
}


/*
void Esfera::renderEsfera() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());//también lo puedo poner como this->pos.x  o  (*this).pos.x
													 //glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidSphere(0.6);			//pinta un cubo
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}
*/

void Esfera::render() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());
	//glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidSphere(r,10,10);			//pinta una tetera
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}

void Esfera::update(double dt) {
	Vector3D gravedad(0, -0.98, 0);
	pos = pos + vel * dt;
	vel = vel + gravedad * dt;
	//colisiones
	if (pos.getX() > 2 || pos.getX() < -2) {
		double d = vel.getX()*-0.9;
		vel.setX(d);
	}
	if (pos.getZ() > 2 || pos.getZ() < -2) {
		double d = vel.getX()*-0.9;
		vel.setZ(d);
	}
	if (pos.getY() < 0) {
		double d = vel.getY()*0.9;
		vel.setY(d);
		pos.setY(0);
	}
}