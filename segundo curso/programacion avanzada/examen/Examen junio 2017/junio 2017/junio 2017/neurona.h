#ifndef NEURONA_H
#define NEURONA_H
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

typedef vector<float> Datos;
typedef vector<float> Pesos;

class Neurona
{
private:
	Datos datos;
	Pesos pesos;
public:
	Neurona() {}
	Neurona(Datos d, Pesos p) : datos(d), pesos(p) {}
	Neurona(const Neurona &n) : datos(n.getDatos()), pesos(n.getPesos()) {}

	inline Datos getDatos() const { return datos; }
	inline Pesos getPesos() const { return pesos; }
	inline void setDatos(Datos d) { datos = d; }
	inline void setPesos(Pesos p) { pesos = p; }
	Neurona clone() { return Neurona(*this); }
	virtual double evalua() {
		double retval = 0.0;
		for (int i = 0; i < datos.size(); i++) retval += datos[i] * pesos[i];
		return retval;
	}

	void guardar(const char* fileName) {
		ofstream myfile(fileName);
		if (myfile.is_open()) {
			for (int i = 0; i < datos.size(); i++) myfile << datos[i] << ',';
			myfile << endl;
			for (int i = 0; i < pesos.size(); i++) myfile << pesos[i] << ',';
			myfile << endl;
		}
		else
			cout << "No se pudo abrir el archivo";
	}
	void recuperar(const char* fileName) {
		string line;
		ifstream myfile(fileName);
		if (myfile.is_open()) {
			datos.clear();
			pesos.clear();
			double value;
			string line;
			getline(myfile, line);
			istringstream ss(line);
			string str;
			while (getline(ss, str, ',')) {
				istringstream(str) >> value;
				datos.push_back(value);
			}
			getline(myfile, line);
			ss = istringstream(line);
			while (getline(ss, str, ',')) {
				istringstream(str) >> value;
				pesos.push_back(value);
			}
		}
		else
			cout << "No se pudo abrir el archivo";
	}

	friend ostream &operator<<(ostream &os, const Neurona &n);

	~Neurona() {}
};
inline ostream &operator<<(ostream &os, const Neurona &n) {
	os << "Datos: ";
	Datos n_datos = n.getDatos();
	for (int i = 0; i < n_datos.size(); i++) os << n_datos[i] << ',';
	os << endl << "Pesos: ";
	Pesos n_pesos = n.getPesos();
	for (int i = 0; i < n_pesos.size(); i++) os << n_pesos[i] << ',';
	return os;
}
#endif

