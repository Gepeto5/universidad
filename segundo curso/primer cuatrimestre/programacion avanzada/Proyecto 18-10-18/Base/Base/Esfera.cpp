#include "Esfera.h"

void Esfera::render() {
	glPushMatrix();					//Push y Pop se usan para que las transformaciones anteriores no afecten
	glTranslatef(this->getPos().getX(), this->getPos().getY(), this->getPos().getZ());//también lo puedo poner como this->pos.x  o  (*this).pos.x
	//glRotatef(t / 30, 1.0, 0.0, 0.0);
	glColor3f(this->getCol().getX(), this->getCol().getY(), this->getCol().getZ());
	glutSolidSphere(r,40,40);			//pinta una esfera
	glPopMatrix(); //Al no poner el pop aquí, se anida con las transformaciones siguientes permitiendo efectos como órbitas
}

