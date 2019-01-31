using namespace std;
#include <fstream>
#include <iostream>
#include "neurona.h"
#include "capa.h"
#include "redNeuronal.h"
#include "neuronaRELU.h"
#include <string>

int main(int argc, char *argv[]) {

	const char* fileName = "neurona1";

	Neurona n1 = Neurona();
	Datos d1{ 4,5,6 };
	Pesos p1{ 2,3,4 };
	n1.setDatos(d1);
	n1.setPesos(p1);

	Neurona n2 = Neurona(n1);
	Datos d2{ 1,1,1,1 };
	Pesos p2{ 1, 2, 1, 2};
	n2.setDatos(d2);
	n2.setPesos(p2);
	//cout << n1 << endl << n2 << endl;

	Capa c1 = Capa();
	c1.addNeurona(n1);
	Capa c2 = Capa(c1);
	c2.addNeurona(n2);
	//cout << c1 << endl << c2 << endl;

	c2.evalua();
	//cout << c2 << endl;

	RedNeuronal RN = RedNeuronal();
	RN.add(c1);
	RN.add(c2);
	RN.evalua();

	NeuronaRELU n3 = NeuronaRELU(d1, p2);
	c2.addNeurona(n3);
	cout << c2 << endl;
	cout << n3.evalua() << endl;

	int i;
	//std::cin >> i;
	//std::cout << i;
	std::cin >> i;
	return 0;
}