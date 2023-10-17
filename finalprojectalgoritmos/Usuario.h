#pragma once
#include "CuentaBancaria.h"

class Usuario {
private:
	string nombre;
	string email;
	int codUsuario;
	CuentaBancaria* cuentaBancaria;
	int pos, edad;

public:
	Usuario(string nombre = "undefined", string email = "undefined", int pos = 0, int edad=0 , int cod=0)
		: nombre(nombre), email(email), pos(pos), edad(edad), codUsuario(cod) {
		this->cuentaBancaria = new CuentaBancaria(); // cuenta random ya rellenada con datos random
		this->edad = rand() % (75 - 5 + 1);
		this->codUsuario = cod;
	}
	~Usuario() {}
	string getInfo() {
		return
			"Cliente N " + to_string(pos) +
			"\nNombre: " + nombre +
			"\nEmail: " + email +
			"\nEdad: " + to_string(edad) +
			"\nMetodo de pago utilizado:" +
			cuentaBancaria->getInfo();
	}

	void setCB(CuentaBancaria* cB) { this->cuentaBancaria = cB; }
	void setNombre(string nombre) { this->nombre = nombre; }
	void setEmail(string email) { this->email = email; }
	void setEdad(string edad) { this->edad = stoi(edad); }
	void setPos(int pos) { this->pos = pos; }
	int getPos() { return this->pos; }
	int getEdad() { return this->edad; }
	int getCodUsuario() { return this->codUsuario; }
	void setCodigo(int codigo) { this->codUsuario = codigo; }
	string getNombre() { return this->nombre; }
	int getDistintivo() { return this->codUsuario; }
	CuentaBancaria* getCB() { return this->cuentaBancaria; }

};