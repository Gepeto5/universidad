#include "solido.h"

Vector3D Solido::getPos() {
	return pos;
}
Vector3D Solido::getCol() {
	return col;
}
Vector3D Solido::getVel() {
	return vel;
}
void Solido::setPos(Vector3D a) {
	pos = a;
}
void Solido::setCol(Vector3D a) {
	col = a;
}
void Solido::setVel(Vector3D a) {
	vel = a;
}
void Solido::renderTetera() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());
	//glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidTeapot(0.6);			//pinta una tetera
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}
