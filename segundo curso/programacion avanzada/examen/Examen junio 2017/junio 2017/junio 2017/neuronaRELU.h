#ifndef NEURONARELU_H
#define NEURONARELU_H
#include "neurona.h"
class NeuronaRELU : public Neurona
{
public:
	NeuronaRELU() {}
	NeuronaRELU(Datos d, Pesos p) : Neurona(d, p) {}
	double evalua() {
		double retval = 0.0;
		for (int i = 0; i < this->getDatos().size(); i++) retval += this->getDatos()[i] * this->getPesos()[i];
		return ((retval > 0) ? (retval) : (0));
	}
	~NeuronaRELU() {}
};
#endif
