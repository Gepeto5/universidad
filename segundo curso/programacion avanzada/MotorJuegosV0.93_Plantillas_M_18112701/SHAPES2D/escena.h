#pragma once
#include <vector>
#include "cubo.h"
#include "esfera.h"
#include "cilindro.h"

using namespace std;

class Escena
{
	//vector<Esfera*> esferas;
	//vector<Cubo*>   cubos;
	//vector<Cilindro*>   cilindros;
	vector<Solido*> solidos;
public:
	Escena();
	~Escena();
	vector<Solido*> getSolidos() { return solidos; }
	void setSolidos(vector<Solido*> e) { solidos = e; }
	void render();
	void update(double dt);
	void add(Solido* e) {
		solidos.push_back(e);
	}
	void borrar(Solido* e) {
		auto it = find(solidos.begin(), solidos.end(), e);
		if (it == solidos.end())
			return;
		solidos.erase(it);
	}
};

