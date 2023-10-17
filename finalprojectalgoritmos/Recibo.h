#pragma once
#include "Usuario.h"
#include "Funcion.h"
#include "Combo.h"
#include "Butaca.h"

class Recibo {
private:
	Funcion* funcion;
	Butaca* butaca;
	Combo* combo;
	Usuario* usuario;
	int codigo, costo;

public:
	Recibo() {
		funcion = nullptr;
		combo = nullptr;
		usuario = nullptr;
		butaca = nullptr;
		this->codigo = 0;
		this->costo = 0;
	}
	Recibo(Funcion* funcion, Butaca* butaca, 
		Combo* combo, Usuario* usuario, int codigo) : funcion(funcion), butaca(butaca),
		combo(combo), usuario(usuario), codigo(codigo) {
		this->costo = funcion->getPrecio() + combo->getPrecio();
	}

	~Recibo() {
		delete funcion, butaca, combo;
	}

	Funcion* getFuncion() { return this->funcion; }
	Butaca* getButaca() { return this->butaca; }
	Combo* getCombo() { return this->combo; }
	Usuario* getUsuario() { return this->usuario; }
	void setFuncion(Funcion* funcion) { this->funcion = funcion; }
	void setButaca(Butaca* butaca) { this->butaca = butaca; }
	void setCombo(Combo* combo) { this->combo = combo; }
	void setUsuario(Usuario* usuario) { this->usuario = usuario; }
	void setCodigo(int codigo) { this->codigo = codigo; }
	int getCodigo() { return this->codigo; }
	void sumarCosto(int x) { this->costo += x; }
	int getDistintivo() { return this->codigo; }
	int getCosto() { return this->costo; }
	void getInfo() {
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		cout << "=============================================\n";
		cout << "\t\tRECIBO N #" << codigo <<"\n";
		cout << "\t\t------------\n";
		cout << "Cliente N "<< usuario->getPos() << ": " << usuario->getNombre() << "\n";
		if (funcion) {
			cout << "Entrada " << "\'" << funcion->getPelicula()->getNombre() << "\'" << "...x1" << "\t\tS/." << funcion->getPrecio();
			if (butaca) {
				cout << "\nButacas: " << butaca->getCodigo(); // butacaS
			}
		}
		if (combo) {
			cout << "\nCombo...x1\t\t\t\tS/." << combo->getPrecio();
		}
		cout << "\nTotal...\t\t\t\tS/." << costo;

		if (usuario->getCB()) {
			cout << "\nMetodo de pago utilizado: ";
			cout << usuario->getCB()->getInfo();
		}

		cout << "\n=============================================\n\n";
		System::Console::ForegroundColor = System::ConsoleColor::Yellow;
	}
};