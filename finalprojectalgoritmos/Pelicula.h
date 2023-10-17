#pragma once
#include <string>
#include <vector>
#include "Fecha.h"
using namespace std;

class Pelicula {
private:
	string nombre, autor, sinopsis;
	int posicion;
	vector<Fecha*> fechas;

	string mostrarFechas() {
		string msg = "";
		for (auto i : fechas)
			msg += i->getInfo() + "\n";
		return msg;
	}

public:
	Pelicula(string nombre = "undefined", string autor = "undefined", string sinopsis = "undefined",
		int posicion = 0) :
		nombre(nombre), autor(autor), sinopsis(sinopsis), posicion(posicion) {}
	~Pelicula() {}

	string getNombre() { return this->nombre; }
	string getAutor() { return this->autor; }
	string getSinopsis() { return this->sinopsis; }
	void setPosicion(int posicion) { this->posicion = posicion; }
	int getPosicion() { return this->posicion; }

	string getInfo() {
		return "Indice: " + to_string(this->posicion) +
			"\nNombre: " + this->nombre +
			"\nAutor: " + this->autor +
			"\nSinopsis: " + this->sinopsis +
			"\nFechas disponibles:\n" + mostrarFechas() + "\n";
	}
	vector<Fecha*> getFechas() { return this->fechas; }
	void pushFecha(Fecha* fecha) { this->fechas.push_back(fecha); }
};