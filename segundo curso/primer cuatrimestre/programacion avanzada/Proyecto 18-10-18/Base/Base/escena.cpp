#include "escena.h"



Escena::Escena()
{
}


Escena::~Escena()
{
}
void Escena::render() {
	for(Solido* s: solidos) {
		s->render();
	}

	/*
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
	*/
}
void Escena::update(double dt) {
	/*
	for (int i = 0; i < cubos.size(); i++) {
		cubos[i]->update(dt);
	}
	for (Esfera* &e : esferas) {	//bucle for each de esferas, &accede al elemento original de esfera, no usa una copia
		e->update(dt);
	}
	for (Cilindro* &c : cilindros) {
		c->update(dt);
	}
	for (std::vector<Cubo*>::iterator it = cubos.begin(); it != cubos.end(); ++it) {
	//[it]->update[it];
//std::cout << '\n,';
	Cubo* c = *it;
	c->update(dt);
	//(*it) ->update(dt);    
	//c es un puntero a Cubo, e it es un puntero que apunta a otro puntero que apunta a Cubo. Por tanto, lo que puedo hacer es un doble puntero (la linea comentada), que apunte al puntero que apunta a Cubo.
	//la flecha -> se utiliza como un . (por ejemplo cubo.update), pero para punteros. Entonces, si tengo un puntero que apunta a cubo, y le digo puntero->update, estás diciendo que le haga update a donde apunta ese puntero (en este caso Cubo). 
	*/
	for (Solido* c : solidos) {
		c->update(dt);
	}

}

