#include "escena.h"
Escena::Escena()
{
}
Escena::~Escena(){
	for (Solido *s : solidos) {
		delete s;
	}
	solidos.clear();//No necesario es llamado automaticamente por el destructor de vector
}

void Escena::render() {
	/*for (int i = 0; i < cubos.size(); i++) {
		//(*cubos[i]).render();
		cubos[i]->render();
	}
	for (Esfera* e : esferas) {
		e->render();
	}
	for (Cilindro* c : cilindros) c->render();*/
	for (Solido* s : solidos)
		s->render();
}
void Escena::update(double dt) {
	for (Solido* &s : solidos)
		s->update(dt);
}
