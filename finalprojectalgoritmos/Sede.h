#pragma once
#include <string>
using namespace std;

class Sede {
private:
	string zona;
	int pos;

public:
	Sede(string zona="undefined", int pos = 0) : zona(zona), pos(pos) {}
	~Sede(){}

	string getInfo() { return 
		"Posicion: " + to_string(this->pos) +
		"\nZona: " + this->zona + "\n\n";
	}
	int getPosicion() { return this->pos; }
	string getZona() { return this->zona; }
};