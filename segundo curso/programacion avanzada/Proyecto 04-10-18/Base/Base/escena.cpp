#include "escena.h"



Escena::Escena()
{
}


Escena::~Escena()
{
}

void Escena::rend() {
	
	for (int i = 0; i < cubos.size(); i++) {
		cubos[i]->render();
	}
	
	/*
	for (int i = 0; i < esferas.size(); i++) {
		esferas[i].render();
	}*/
	
	for (Esfera* e : esferas) {
		e->render();
	}
	/*
	for (Cubo c : cubos) {
		c.render();
	}*/
	
}

void Escena::update(double dt) {
	for (int i = 0; i < cubos.size(); i++) {
		cubos[i]->update(dt);
	}
	for (Esfera* &e : esferas) {
		e->update(dt);
	}
}

