#pragma once
#pragma once
#include <vector> //Del espacio de nombres std
#include "vector3D.h"
#include "Solido.h"
#include <iterator>

using namespace std;

class Compuesto:public Solido
{
	/*
	vector<Esfera*> esferas; //Array de punteros a esferas
	vector<Cubo*> cubos;
	vector<Cilindro*> cilindros;
	*/
	vector<Solido*> solidos; //colecci�n de punteros a solidos, donde est� el objeto entero. As� no se pierde la informaci�n, y se puede hacer polimorfismo correctamente
public:
	Compuesto();
	
	Compuesto(const Compuesto &e) :solidos() {
		/*for (Solido *s : e.solidos) {
			Solido *s0 = s->clone();
			solidos.push_back();
		}*/
		for (Solido* s : e.solidos) {
			solidos.push_back(s);
		}
	}

	Compuesto *clone() {
		return new Compuesto(*this);
	}

	virtual ~Compuesto() {
		for (Solido *s : solidos) {
			delete s;
		}
		solidos.clear();
	}

	vector<Solido*>getSolidos() { return solidos; }

	void setSolidos(vector<Solido*> e) { solidos = e; }


void render() {
	glPushMatrix();
	glTranslated(getPos().getX(), getPos().getY(), getPos().getZ());
	for (Solido *s : solidos)
		s->render();
	glPopMatrix();
}

void update(double dt) {
	for (vector<Solido *>::iterator i = solidos.begin(); i < solidos.end(); i++){
		Solido *s = *i;
		s->update(dt);
	}
}

vector<Solido*> getCubos() { return solidos; }
void add(Solido *s) { solidos.push_back(s); }

};
