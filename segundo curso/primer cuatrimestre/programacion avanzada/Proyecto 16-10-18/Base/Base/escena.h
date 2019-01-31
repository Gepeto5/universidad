#pragma once
#include <vector> //Del espacio de nombres std
#include "cubo.h"
#include "esfera.h"
#include "cilindro.h"

using namespace std;

class Escena
{
	vector<Esfera*> esferas; //Array de punteros a esferas
	vector<Cubo*> cubos;
	vector<Cilindro*> cilindros;
public:
	Escena();
	~Escena();
	void render();
	vector<Esfera*> getEsferas() { return esferas; }
	vector<Cubo*> getCubos() { return cubos; }
	vector<Cilindro*> getCilindros() { return cilindros; }

	void setEsferas(vector<Esfera*> v) { esferas = v; }
	void setCubos(vector<Cubo*> v) { cubos = v; }
	void setCilindros(vector<Cilindro*> v) { cilindros = v; }

	void update(double dt);

	void add(Esfera* e) { esferas.push_back(e); }
	void add(Cubo* c) { cubos.push_back(c); }
	void add(Cilindro* cc) { cilindros.push_back(cc); }
};

