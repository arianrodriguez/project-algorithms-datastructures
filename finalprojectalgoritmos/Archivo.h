#pragma once
#include "Utilidades.h"
#include <vector>
#include <fstream>

class Archivo {
private:
	std::ifstream leer;

public:
	Archivo(){}
	~Archivo(){}

	void leerPeliculas(ListaDobleEnlazada<Pelicula>*& listaPeliculas) {
		leer.open("peliculas.txt", std::ios::in);
		if (leer.fail()) throw "Fallo al leer el txt de peliculas"; // genera un error y detiene el programa
		
		vector<string> infoPelicula;
		string linea;
		int pos = 0;
		while (!leer.eof()) { // mientras no sea el final del archivo
			getline(leer, linea);
			if(linea!="") infoPelicula.push_back(linea);
			else {
				/*
					se acabaron las lineas de la info de una pelicula, estas lineas se fueron guardando
					en el vector antes, ahora toka destructurarlo para crear una new Pelicula y pa la lista
				*/

				string sinopsis = "";
				for (int i = 2; i < infoPelicula.size(); ++i) 
					sinopsis += infoPelicula[i];
				
				listaPeliculas->insertar(new Pelicula(
					infoPelicula[0],
					infoPelicula[1],
					sinopsis,
					pos
				));

				infoPelicula.clear();
				pos += 1;
			}
		}

		leer.close();
	}

	void leerCombos(Pila<Combo>*& pilaCombos) {
		leer.open("combos.txt", ios::in);
		if (leer.fail()) throw "Error al leer el txt de los combos";

		vector<string> combo;
		string linea;
		int pos = 0;
		while (!leer.eof()) {
			getline(leer, linea);
			if (linea != "") combo.push_back(linea);
			else {
				string contenido = "";
				for (int i = 0; i < combo.size() - 1; ++i)
					contenido += combo[i] + "\n";
				
				pilaCombos->add(
					new Combo(contenido, combo[combo.size() - 1], pos)
				);

				combo.clear();
				pos += 1;
			}
		}

		leer.close();
	}

	void leerZonas(Pila<Sede>*& pilaSedes) {
		leer.open("zonas.txt", ios::in);
		if (leer.fail()) throw "Error al leer el txt de las zonas";

		string linea;
		int pos = 0;
		while (!leer.eof()) {
			getline(leer, linea);
			pilaSedes->add(new Sede(linea, pos));
			pos++;
		}

		leer.close();
	}

	vector<string> leerClientes() {
		leer.open("nombres.txt", ios::in);
		if (leer.fail()) throw "Error al leer nombres.txt";

		vector<string> nombres;
		vector<string> apellidos;
		vector<string> nombCompleto;
		string linea;


		while (!leer.eof()) {
			getline(leer, linea);
			if (linea != "")nombres.push_back(linea);
		}
		leer.close();

		leer.open("apellidos.txt", ios::in);
		if (leer.fail()) throw "Error al leer apellidos.txt";

		while (!leer.eof()) {
			getline(leer, linea);
			if (linea != "")apellidos.push_back(linea);
		}
		leer.close();

		
		for (const string& i : nombres) {
			nombCompleto.push_back(i + " " +
				apellidos.at(rand() % apellidos.size())
			);
		}
		return nombCompleto;
	}
};