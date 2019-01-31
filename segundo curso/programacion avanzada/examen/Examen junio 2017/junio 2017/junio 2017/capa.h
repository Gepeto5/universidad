#ifndef CAPA_H
#define CAPA_H
using namespace std;
#include "neurona.h"
#include <vector>
class Capa
{
private:
	vector<Neurona> neuronas;
public:
	Capa() {}
	Capa(const Capa &c) : neuronas(c.getNeuronas()) {}
	inline vector<Neurona> getNeuronas() const { return neuronas; }
	inline void setNeuronas(vector<Neurona> n) { neuronas = n; }
	inline void addNeurona(Neurona n) { neuronas.push_back(n); }
	Datos evalua() {
		Datos retval;
		for (Neurona n : neuronas) {
			retval.push_back(n.evalua());
		}
		return retval;
	}
	void ponDatos(Datos d) {
		for (Neurona n : neuronas) {
			n.setDatos(d);
		}
	}
	friend ostream &operator<<(ostream &os, const Capa &c) {
		for (Neurona n : c.neuronas) os << n << endl;
		return os;
	}
	~Capa(){}
};
#endif

