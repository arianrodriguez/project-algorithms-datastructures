#pragma once
#include <string>
#include <ctime>
using namespace std;

const string mes = "06";
const string anio = "2023";

class Fecha {
private:
	string dia;
	int pos;

public:
	Fecha(int dia) : dia(to_string(dia)), pos(dia-1) {}
	~Fecha(){}

	string getInfo() { return dia + "/" + mes + "/" + anio; }
	int getPosicion() { return this->pos; }
};