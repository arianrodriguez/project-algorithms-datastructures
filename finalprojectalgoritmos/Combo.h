#pragma once
#include <string>
using namespace std;

class Combo {
private:
	string precio, contenido;
	int pos;

public:
	Combo(string contenido = "undefined", string precio = "undefined", int pos=0) :
		contenido(contenido), precio(precio), pos(pos) {}
	~Combo(){}

	string getInfo() {
		return "          Combo # " + to_string(pos+1) + "            \n" +
			contenido + "          Precio: " + precio + " soles     \n\n";
	}

	int getPosicion()
	{
		return pos;
	}
	int getPrecio() { return stoi(this->precio); }

};