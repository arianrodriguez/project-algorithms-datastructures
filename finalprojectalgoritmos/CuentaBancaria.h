#pragma once
#include <iostream>
#include <string>
using namespace std;
const int CANT_TARJETAS_DISP = 6;
const string TARJETAS_DISPONIBLES[] = { "Visa", "Mastercard", "Paypal", "American Express", "Diners Club", "PagoEfectivo"};

class CuentaBancaria {
private:
	string numeroCuenta; // 16 digitos
	string fechaVencimiento; // MM/DD
	string CVV;
	string tarjeta;
	int cantDinero;
public:
	CuentaBancaria(string numeroCuenta, string fechaVencimiento, string CVV)
		: numeroCuenta(numeroCuenta), fechaVencimiento(fechaVencimiento), CVV(CVV) {

		this->cantDinero = rand() % 151;
		this->tarjeta = TARJETAS_DISPONIBLES[rand() % CANT_TARJETAS_DISP];
	}
	CuentaBancaria() {
		this->numeroCuenta = to_string(rand() % (9999 - 1000 + 1)) + " " +
			to_string(rand() % (9999 - 1000 + 1)) + " " +
			to_string(rand() % (9999 - 1000 + 1)) + " " +
			to_string(rand() % (9999 - 1000 + 1));

		this->cantDinero = rand() % 151;
		this->tarjeta = TARJETAS_DISPONIBLES[rand() % CANT_TARJETAS_DISP];
		this->fechaVencimiento = to_string(rand() % (12 - 1) + 1) + "/" + to_string(rand() % (2027 - 2024) + 2024);
		this->CVV = to_string(rand() % (999 - 111) + 111);
	}
	~CuentaBancaria() {}

	string getInfo() {
		return "\n\tTipo pago/tarjeta: " + tarjeta +
			"\n\tNumero de cuenta: " + numeroCuenta +
			"\n\tFecha de vencimiento: " + fechaVencimiento +
			"\n\tCVV: " + CVV +
			"\n\tSaldo disponible: " + to_string(cantDinero) + "\n\n";
	}
	string getNumeroCuenta() { return numeroCuenta; }
	string getfechaVencimiento() { return fechaVencimiento; }
	string getCVV() { return CVV; }
	int getCantDinero() { return this->cantDinero; }
	void generarNuevosDatos() {
		this->numeroCuenta = to_string(rand() % (9999 - 1000 + 1)) + " " +
			to_string(rand() % (9999 - 1000 + 1)) + " " +
			to_string(rand() % (9999 - 1000 + 1)) + " " +
			to_string(rand() % (9999 - 1000 + 1));
		this->cantDinero = rand() % 151;
		this->tarjeta = TARJETAS_DISPONIBLES[rand() % CANT_TARJETAS_DISP];
		this->fechaVencimiento = to_string(rand() % (12 - 1) + 1) + "/" + to_string(rand() % (2027 - 2024) + 2024);
		this->CVV = to_string(rand() % (999 - 111) + 111);
	}
	void setNumeroCuenta(string numeroCuenta) { this->numeroCuenta = numeroCuenta; }
	void setFechaVencimiento(string fechaVencimiento) { this->fechaVencimiento = fechaVencimiento; }
	void setCVV(string CVV) { this->CVV = CVV; }
	void nuevoSaldo() { this->cantDinero = rand() % 151; }
	void restarDinero(int x) { this->cantDinero -= x; }
};