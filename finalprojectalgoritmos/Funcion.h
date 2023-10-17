#pragma once
#include "Sede.h"
#include "Pelicula.h"
#include <iostream>
#include <string>

class Funcion {
private:
	Pelicula* pelicula;
	Sede* zona;
	string hora;
	int hr, min, pos, precio;

	vector<string> butacasOcupadas;

public:
	Funcion(Pelicula* pelicula = nullptr, Sede* zona = nullptr, int pos = 0) : pelicula(pelicula),
		zona(zona), pos(pos) {
		min = rand() % 60;
		hr = 10 + rand() % (24 - 10);

		this->hora = to_string(hr) + ":";
		hora += (min < 10) ? "0" + to_string(min) : to_string(min);

		string a = "";
		for (int i = 0; i < rand() % (80 - 30 + 1) + 30; ++i) {// entre 30 y 81 butacas ocupadas 
			a += char(rand() % (74 - 65 + 1) + 65);
			a += to_string(1 + rand() % 9);
			butacasOcupadas.push_back(a);
			a = "";
		}

		this->precio = rand() % (50 - 30 + 1) + 30;
	}
	~Funcion() {}

	int getHr() { return this->hr; }
	int getMin() { return this->min; }
	int getPosicion() { return this->pos; }
	int getPrecio() { return this->precio; }
	void setPosicion(int pos) { this->pos = pos; }
	vector<string> getButacasOcupadas() { return this->butacasOcupadas; }
	void pushButacaOcupada(string codigo) { this->butacasOcupadas.push_back(codigo); }
	string getInfo() {
		return
			"Pelicula: " + pelicula->getNombre() + "\n" +
			"Sede: " + zona->getZona() + "\n" +
			"Hora: " + hora + "\n" +
			"ID: " + to_string(pos) + "\n\n";
	}

	Sede* getZona()
	{
		
		return zona;
	}

	string getHora() {

		std::string str = hora;

		char oldChar = ':';
		char newChar = '.';

		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == oldChar) {
				str[i] = newChar;
			}
		}
		return str;
	}

	Pelicula* getPelicula() { return this->pelicula; }

};