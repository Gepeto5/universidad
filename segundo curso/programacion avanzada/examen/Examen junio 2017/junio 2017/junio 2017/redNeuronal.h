#ifndef RED_NEURONAL_H
#define RED_NEURONAL_H
#include "capa.h"
class RedNeuronal
{
private:
	vector<Capa> capas;
public:
	RedNeuronal() {}
	void add(Capa c) { capas.push_back(c); }
	Datos evalua() {
		Datos retval;
		for (int i = 0; i < capas.size() - 1; i++) capas[i+1].ponDatos(capas[i].evalua());
		retval = capas[capas.size() - 1].evalua();
		return retval;
	}

	~RedNeuronal() {}
};
#endif

