#pragma once
#include <vector> //Del espacio de nombres std
#include "cubo.h"
#include "esfera.h"
#include "cilindro.h"

using namespace std;

class Escena
{
	/*
	vector<Esfera*> esferas; //Array de punteros a esferas
	vector<Cubo*> cubos;
	vector<Cilindro*> cilindros;
	*/
	vector<Solido*> solidos; //colecci�n de punteros a solidos, donde est� el objeto entero. As� no se pierde la informaci�n, y se puede hacer polimorfismo correctamente
public:
	Escena();
	~Escena();
	void render();
	vector<Solido*>getSolidos() { return solidos; }
	/*
	vector<Esfera*> getEsferas() { return esferas; }
	vector<Cubo*> getCubos() { return cubos; }
	vector<Cilindro*> getCilindros() { return cilindros; }
	*/

	void setSolidos(vector<Solido*> e) { solidos = e; }
	/*
	void setEsferas(vector<Esfera*> v) { esferas = v; }
	void setCubos(vector<Cubo*> v) { cubos = v; }
	void setCilindros(vector<Cilindro*> v) { cilindros = v; }
	*/

	void update(double dt);

	/*
	void add(Esfera* e) { esferas.push_back(e); }
	void add(Cubo* c) { cubos.push_back(c); }
	void add(Cilindro* cc) { cilindros.push_back(cc); }
	*/
	void add(Solido* s) { solidos.push_back(s); }
};

