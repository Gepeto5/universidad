#pragma once
#include "cubo.h"
#include "esfera.h"
#include <vector>

using namespace std;

class Escena
{
	vector<Esfera*> esferas;
	vector<Cubo*> cubos;

public:
	Escena();
	~Escena();
	void rend();
	void update(double dt);
	void add(Esfera* e) {esferas.push_back(e);};
	void add(Cubo* c) {cubos.push_back(c);}
	vector<Esfera*> getEsferas() { return esferas; }
	vector<Cubo*> getCubos() { return cubos; }
	void setEsferas(vector<Esfera*> v) { esferas = v; }
	void setCubos(vector<Cubo*> v) { cubos = v; }
};

