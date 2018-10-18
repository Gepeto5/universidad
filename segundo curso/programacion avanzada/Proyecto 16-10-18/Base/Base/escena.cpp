#include "escena.h"



Escena::Escena()
{
}


Escena::~Escena()
{
}
void Escena::render() {
	for (int i = 0; i < cubos.size(); i++) {
		//cubos[i].render();
		cubos[i]->render();
	}
	for (Esfera* e : esferas) {	//bucle for each de esferas
		e->render();
	}
	for (Cilindro* c : cilindros) {
		c->render();
	}
}
void Escena::update(double dt) {
	for (int i = 0; i < cubos.size(); i++) {
		cubos[i]->update(dt);
	}
	for (Esfera* &e : esferas) {	//bucle for each de esferas, &accede al elemento original de esfera, no usa una copia
		e->update(dt);
	}
	for (Cilindro* &c : cilindros) {
		c->update(dt);
	}
}