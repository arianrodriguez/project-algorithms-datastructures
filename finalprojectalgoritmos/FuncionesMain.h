#pragma once
#include "ListaSimpleEnlazada.h"
#include "ListaDobleEnlazada.h"
#include "Pelicula.h"
#include "Fecha.h"
#include "Funcion.h"
#include "Butaca.h"
#include "Pila.h"
#include "Recibo.h"
#include "ArbolB.h"
#include "HashTable.h"
#include "Usuario.h"
#include "BusquedaBinaria.h"
#include "ColaPrioridad.h"
#include "Cola.h"
#include "AVL.h"
#include "Grafo.h"

namespace fMain {

	Funcion* peliculaInput(ListaSimpleEnlazada<Funcion>* funciones, int id) {
		do {
			for (int i = 0; i < funciones->getCantidad(); ++i) {
				if (funciones->buscar(i)->getPosicion() == id) {

					return funciones->buscar(i);
				}
			}
		} while (1);
	}

	Combo* comboInput(Pila<Combo>* combo, int id) {
		do {
			for (int i = 0; i < combo->getCant(); ++i) {
				if (combo->search(i)->getPosicion() == id) {

					return combo->search(i);
				}
			}
		} while (1);
	}

	Butaca* escoger_butaca(Pila<Butaca> butacas) {
		Butaca* butaca;
		string s;
		bool f = false;
		do {
			cout << "\nSelecciona codigo butaca: ";
			cin >> s;

			if (s.length() != 2) continue;

			if ((int(s[0]) >= 65 && int(s[0]) <= 75) &&
				(s[1] >= '1' && s[1] <= '9')) {

				Pila<Butaca> copia = butacas;

				NodoP<Butaca>* top = copia.getTop();
				while (top != NULL) {
					if (top->elem->getLibre() && top->elem->getCodigo() == s) {
						f = true;
						butaca = top->elem;
						break;
					}
					top = top->sgt;
				}
				if (!f) cout << "\nButaca ocupada";

			}
			else cout << "\nButaca inexistente";

		} while (!f);
		return butaca;
	}

	void actualizarResumenPago(Recibo* recibo) {
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		cout << "=============================================\n";
		cout << "\t\tRESUMEN PAGO\n";
		cout << "\t\t------------\n";
		cout << "Cliente: " << recibo->getUsuario()->getNombre() << "\n";
		if (recibo->getFuncion()) {
			Funcion* funcion = recibo->getFuncion();
			cout << "Entrada " << "\'" << funcion->getPelicula()->getNombre() << "\'" << "...x1" << "\t\tS/." << funcion->getPrecio();
			if (recibo->getButaca()) {
				cout << "\nButacas: " << recibo->getButaca()->getCodigo(); // butacaS
			}
		}
		if (recibo->getCombo()) {
			Combo* combo = recibo->getCombo();
			cout << "\nCombo...x1\t\t\t\tS/." << combo->getPrecio();
		}
		cout << "\nTotal...\t\t\t\tS/." << recibo->getCosto();
		cout << "\n=============================================\n\n";
		System::Console::ForegroundColor = System::ConsoleColor::Yellow;
	}

	Usuario* inputUsario() {
		string s;
		Usuario* usuario = new Usuario();
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		cout << "\n\tBienvenido a CineYesi!";
		cout << "\nCompleta tus datos para continuar con la compra";
		cout << "\n================================================";
		System::Console::ForegroundColor = System::ConsoleColor::Yellow;
		cin.ignore();
		cout << "\nNombre: "; getline(cin, s);
		usuario->setNombre(s);

		cout << "Email: "; getline(cin, s);
		usuario->setEmail(s);

		cout << "Edad: "; getline(cin, s);
		usuario->setEdad(s);
		// posicion se settea en el main, con ayuda de getCant() del arbol, debido a que se almacenan despues de generados los random

		return usuario;
	}

	CuentaBancaria* inputMetodoPago(Recibo* recibo) {
		CuentaBancaria* cb = new CuentaBancaria();
		string s;
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		cout << "\n\t\tMetodo de pago";
		cout << "\nCompleta tus datos de pago para continuar con la compra";
		cout << "\n=======================================================\n";
		cin.ignore();
		do {
			System::Console::ForegroundColor = System::ConsoleColor::Yellow;
			cb->nuevoSaldo();
			cout << "Ingresa tu numero de tarjeta: "; getline(cin, s);
			cb->setNumeroCuenta(s);
			cout << "Fecha de vencimiento: "; getline(cin, s);
			cb->setFechaVencimiento(s);
			cout << "CVV: "; getline(cin, s);
			cb->setCVV(s);
			if (cb->getCantDinero() < recibo->getCosto()) {
				System::Console::ForegroundColor = System::ConsoleColor::Red;
				cout << "\n::TARJETA RECHAZADA::";
				cout << "\nSaldo insuficiente: S/." << cb->getCantDinero() << "\n\n";
			}
		} while (cb->getCantDinero() < recibo->getCosto());
		
		System::Console::ForegroundColor = System::ConsoleColor::Green;
		cb->restarDinero(recibo->getCosto());
		cout << "\n::TARJETA ACEPTADA::";
		cout << "\nSaldo restante: S/." << cb->getCantDinero();
		return cb;
	}
	void mostrarVentasRegistradas(ArbolBinario<Recibo>* abRecibos,
		HashTable<Recibo>* htRecibos) {
		int x;

		
			system("cls");
			do {
				cout << "Ingrese numero de codigo del recibo: ";
				cin >> x;
			} while (x<0 || x>abRecibos->cantidad() - 2);

			System::Console::ForegroundColor = System::ConsoleColor::Cyan;
			htRecibos->buscar(x)->getInfo(); // busqueda por el hash table

			//int ind = BusquedaBinaria<Recibo>::bbArbol(abRecibos, x); // busqueda por binarysearch (se usa en la busqueda del usuario)


			//abRecibos->get(ind)->getInfo();
	}

	void mostrarVentasRegistradasOrden(ArbolBinario<Recibo>* abRecibos,
		HashTable<Recibo>* htRecibos,int opc) {
		System::Console::ForegroundColor = System::ConsoleColor::Yellow;
		

			if (opc == 1) abRecibos->enOrden();
			if (opc == 2) abRecibos->postOrden();
			if (opc == 3) abRecibos->preOrden();
	}







	void controlUsuariosPrEdad(ColaPrioridad<Usuario>& cpUsuarios,
		ArbolBinario<Usuario>* abUsuarios) {


		System::Console::SetCursorPosition(4,7);
		cout << "Priorizando las edades (mayor a menor)";
		System::Console::SetCursorPosition(4, 8);
		cout <<"debes atender primero a : ";
		System::Console::SetCursorPosition(4, 9);
		cout << "==========================================";
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		
		System::Console::SetCursorPosition(4, 10); 
		cout << cpUsuarios.top()->getInfo() << endl;
		
	
	
		
	}

	void controlUsuariosBusqe(ColaPrioridad<Usuario>& cpUsuarios,
		ArbolBinario<Usuario>* abUsuarios) {
		int opc;
		do {
			cout << "Ingrese numero de codigo del usuario: ";
			cin >> opc;
		} while (opc<0 || opc>abUsuarios->cantidad() - 1);

		opc = BusquedaBinaria<Usuario>::bbArbol(abUsuarios, opc);

		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
		cout << abUsuarios->get(opc)->getInfo();

	}
	void controlUsuariosVisAll(ColaPrioridad<Usuario>& cpUsuarios,
		ArbolBinario<Usuario>* abUsuarios) {
		system("cls");
		System::Console::ForegroundColor = System::ConsoleColor::Yellow;
	
		
		
		
			system("cls");
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			cout << "Obteniendo a todos los usarios registrados de la base de datos...";
			_sleep(500);

			System::Console::ForegroundColor = System::ConsoleColor::Cyan;
			for (int i = 0; i < abUsuarios->cantidad(); ++i) {
				cout << abUsuarios->get(i)->getInfo();
			}
		
		system("pause>0");
		system("cls");
	}

	void ingresarAVLUsuarios(ArbolBinario<Recibo>* abRecibos,
		HashTable<Recibo>* recibos,
		AVLTree<Usuario>& avlUsuarios) {
		for (int i = 0; i < abRecibos->cantidad(); ++i) {
			avlUsuarios.insert(recibos->getValue(i)->getUsuario());
		}
	}

	void insertarAGrafo(ColaPrioridad<Usuario> cp,
		ArbolBinario<Usuario>* usuarios,
		Grafo<Usuario>*& grafoUsuarios) {

		ColaPrioridad<Usuario> cp_copy = cp;
		for (int i = 0; i < pow(10, 1); ++i) {
			grafoUsuarios->agregarVertice(cp_copy.top());
			cp_copy.pop();
		}

		for (int i = 0; i < pow(10, 1); ++i) {
			grafoUsuarios->agregarArista(usuarios->get(i), usuarios->get(i + 10));
		}

		grafoUsuarios->mostrarGrafo();
	}
}