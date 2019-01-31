#pragma once
#include <vector>
#include <GL/glut.h>
#include "solido.h"
class Compuesto :	public Solido
{
	vector<Solido*> solidos;
public:
	Compuesto() {}
	//Constructor copia profundo
	Compuesto(const Compuesto &e) :Solido(e),solidos() {
		for (Solido* s : e.solidos) {
			solidos.push_back(s->clone());
		}
	}
	/* Constructor copia plano
	Compuesto(const Compuesto &e) :solidos() {
		for (Solido* s : e.solidos) {
			solidos.push_back(s);
		}
	}*/
	Compuesto *clone() {
		return new Compuesto(*this);
	}
	virtual ~Compuesto() {
		for (Solido* s : solidos) {
			delete s;
		}
		solidos.clear();//No necesario es llamado automaticamente por el destructor de vector
	}
	void render() {
		glPushMatrix();
		glTranslated(getPos().getX(), getPos().getY(), getPos().getZ());
		for (Solido *s : solidos)
			s->render();
		glPopMatrix();
	}
	void update(double dt) {
		/*for (Solido *s : solidos)
		s->update(dt);
		*/
		//Uso de iteradores
		for (vector<Solido *>::iterator i = solidos.begin(); i < solidos.end(); i++) {
			Solido* &s = *i;
			s->update(dt);
		}
	}
	vector<Solido*> getSolidos() { return solidos; }
	void add(Solido *s) { solidos.push_back(s); }
};












