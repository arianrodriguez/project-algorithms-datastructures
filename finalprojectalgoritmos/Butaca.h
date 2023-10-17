#pragma once
#include <string>
using namespace std;

class Butaca {
private:
	string codigo;
	bool libre;
	int pos;

public:
	Butaca(string codigo = "UN", bool libre = true, int pos=0) :
		codigo(codigo), libre(libre), pos(pos) {}
	~Butaca() {}

	void liberar() { this->libre = !this->libre; }
	bool getLibre() { return this->libre; }
	void setLibre(bool libre) { this->libre = libre; }
	string getCodigo() { return this->codigo; }
	int getPosicion() { return this->pos; }
};