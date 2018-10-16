#include "cubo.h"
void Cubo::render() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());//también lo puedo poner como this->pos.x  o  (*this).pos.x
	//glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidCube(s);			//pinta un cubo
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}
void Cubo::update(double dt) {
	Vector3D gravedad(0, -0.98, 0);
	//pos = pos+vel * dt;
	pos = pos + vel * dt;
	vel = vel + gravedad * dt;
	if (pos.getX() > 2 || pos.getX() < -2) {
		double d = vel.getX()*-0.9;
		vel.setX(d);
	}
	if (pos.getZ() > 2 || pos.getZ() < -2) {
		double d = vel.getZ()*-0.9;
		vel.setZ(d);
	}
	if (pos.getY() < 0) {
		double d = vel.getY()*-0.9;
		vel.setY(d);
		pos.setY(0);
	}
	
}