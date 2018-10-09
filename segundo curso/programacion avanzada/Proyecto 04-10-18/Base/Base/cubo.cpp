#include "cubo.h"

Vector3D Cubo::getPos() {
	return pos;
}
Vector3D Cubo::getCol() {
	return col;
}
Vector3D Cubo::getVel() {
	return vel;
}
void Cubo::setPos(Vector3D a) {
	pos = a;
}
void Cubo::setCol(Vector3D a) {
	col = a;
}
void Cubo::setVel(Vector3D a) {
	vel = a;
}

void Cubo::renderCubo() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());//también lo puedo poner como this->pos.x  o  (*this).pos.x
													 //glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidCube(0.6);			//pinta un cubo
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}