#include "Solido.h"
void Solido::renderTetera() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());
	//glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidTeapot(0.6);			//pinta una tetera
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}
void Solido::renderCubo() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(pos.getX(), pos.getY(), pos.getZ());//también lo puedo poner como this->pos.x  o  (*this).pos.x
	//glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(col.getX(), col.getY(), col.getZ());
	glutSolidCube(0.6);			//pinta un cubo
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}