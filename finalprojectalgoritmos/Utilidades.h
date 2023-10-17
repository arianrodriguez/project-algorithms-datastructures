#pragma once
#include <conio.h>
#include <iostream>
#include "FuncionesMain.h"

#include <functional>
#include <cmath>
using namespace std;
typedef ListaSimpleEnlazada<Funcion> LSEF;

namespace Utilidades {
	void generarMes(ListaSimpleEnlazada<Fecha>*& listaFechas) {
		for (int i = 0; i < 30; ++i)
			listaFechas->agregar(new Fecha(i + 1));
	}

	void asignarFechasPeliculas(ListaDobleEnlazada<Pelicula>*& listaPeliculas, ListaSimpleEnlazada<Fecha>*& listaFechas) {
		for (int i = 0; i < listaPeliculas->getCantidad(); ++i) {
			Fecha* fechaRand = listaFechas->buscar(rand() % listaFechas->getCantidad());
			Pelicula*& pelicula = listaPeliculas->buscar(i)->elemento;

			bool repetido = false;
			while (pelicula->getFechas().size() != 3) {
				for (auto fecha : pelicula->getFechas()) {
					if (fechaRand == fecha) repetido = true;
				}

				if (repetido) {
					fechaRand = listaFechas->buscar(rand() % listaFechas->getCantidad());
					repetido = false;
				}
				else pelicula->pushFecha(fechaRand);
			}

		}
	}

	void generarFunciones(ListaSimpleEnlazada<Funcion>*& listaFunciones,
		ListaDobleEnlazada<Pelicula>*& listaPeliculas, Pila<Sede>*& pilaSedes) {
		int k = 0;
		for (int i = 0; i < pilaSedes->getCant(); ++i) {
			for (int j = 0; j < 3 + rand() % 10 - 3; ++j) {
				listaFunciones->agregar(new Funcion(
					listaPeliculas->buscar(rand() % listaPeliculas->getCantidad())->elemento,
					pilaSedes->search(i),
					k
				));
				++k;
			}
		}
	}

	void ordenarHoras(LSEF*& listaFunciones, int n) {

		function<void(LSEF*, LSEF*, LSEF*&, int)> merge =
			[](LSEF* A, LSEF* B, LSEF*& lf, int n) {
			int i = 0, j = 0, k = 0;
			int mitad = n / 2;
			while (i < mitad && j < n - mitad) {
				if (A->buscar(i)->getHr() <= B->buscar(j)->getHr()) {
					lf->set(k, A->buscar(i));
					i++; k++;
				}
				else {
					lf->set(k, B->buscar(j));
					j++; k++;
				}
			}
			while (i < mitad) {
				lf->set(k, A->buscar(i));
				i++; k++;
			}
			while (j < n - mitad) {
				lf->set(k, B->buscar(j));
				j++; k++;
			}
		};

		function<void(LSEF*&, int)> mergeSort = [&](LSEF*& lf, int n) {
			if (n > 1) {
				int mid = n / 2;
				LSEF* A = new LSEF();
				LSEF* B = new LSEF();
				for (int i = 0; i < mid; ++i)
					A->agregar(lf->buscar(i));

				for (int i = mid; i < n; ++i)
					B->agregar(lf->buscar(i));


				mergeSort(A, mid);
				mergeSort(B, n - mid);
				merge(A, B, lf, n);
			}
		};

		mergeSort(listaFunciones, listaFunciones->getCantidad());
	}

	void generarButacas(Pila<Butaca>*& butacas) {
		char letra = 'A';
		int j = 0;
		for (int i = 0; i < 81; ++i) { // matriz de butacas 9x9
			if (j == 9) {
				letra++;
				j = 0;
			
			}
			butacas->add(new Butaca(letra + to_string(j+1), true, i));	
			
			++j;
		
		}
	}

	void imprimirButacas(Pila<Butaca> butacas) {
		int j = 0;
		Butaca* butaca;
		cout << "                     Pantalla\n              ";
		for (int i = 0; i < 20; i++)
		{
			cout << char(220);
		}
		cout << "\n\n";

		for (int i = 0; i < butacas.getCant(); ++i) {
			butaca = butacas.remove();
			if (butaca->getLibre()) System::Console::ForegroundColor = System::ConsoleColor::Green;
			else System::Console::ForegroundColor = System::ConsoleColor::Red;

			cout << "[" << butaca->getCodigo() << "] ";
			if (j == 8) {
				cout << endl;
				j = -1;
			}
			if (j == 1 || j == 6) {
				cout << "  ";
			}
			++j;
		}
		System::Console::ForegroundColor = System::ConsoleColor::Gray;
	}

	Butaca* verButacasDisponibles(Funcion* funcion,
		Pila<Butaca>* butacas) {

		vector<string> bocFunc = funcion->getButacasOcupadas();
		cout << funcion->getInfo();

		// ocupar butacas
		cout << endl;
		Pila<Butaca> butacasCopy = *butacas; // copia independiente
		for (int i = 0; i < bocFunc.size(); ++i) {
			NodoP<Butaca>* top = butacasCopy.getTop();

			while (top->elem->getCodigo() != bocFunc.at(i) && top->sgt != NULL)
				top = top->sgt;

			top->elem->setLibre(false);

		}
		Utilidades::imprimirButacas(butacasCopy);
		return fMain::escoger_butaca(butacasCopy);

		// butacas original
		//Utilidades::imprimirButacas(*butacas);
	}

	void generarRecibosRandom(ListaSimpleEnlazada<Funcion>* funciones,
		Pila<Butaca>* butacas,
		Pila<Combo>* combos,
		HashTable<Recibo>*& htRecibos,
		ArbolBinario<Recibo>*& recibos,
		ArbolBinario<Usuario>* abUsuarios) {
		bool RaizIngr = false;
		float j;
		
		for (int i = abUsuarios->cantidad()/2; i < abUsuarios->cantidad(); ++i) {
			if (i == abUsuarios->cantidad() / 2 && RaizIngr == true)
			{
				i++;
				System::Console::SetCursorPosition(15 + i / 1000, 11);
				cout << char(220);
			}
			Funcion* funcion = funciones->buscar(rand() % funciones->getCantidad());
			Butaca* butaca = butacas->search(rand() % butacas->getCant());
			Combo* combo = combos->search(rand() % combos->getCant());
			Usuario* usuario = abUsuarios->get(i);
			Recibo* recibo = new Recibo(funcion, butaca, combo, usuario, usuario->getCodUsuario());
			recibos->insertar(recibo);
			htRecibos->insertar(recibo->getCodigo(), recibo);
			if (i == abUsuarios->cantidad() / 2 && RaizIngr == false){
				RaizIngr = true;
				i = -1;
			}
			j = i;
			if (i / 1000 >= j / 1000 && i / 1000 < 10)
			{
				System::Console::SetCursorPosition(15 + i / 1000, 11);
				cout << char(220);
			}
		}
	}

	void generarUsuariosRandom(ArbolBinario<Usuario>*& abUsuarios,
		vector<string> nombres) {
		bool RaizIngr = false;
		// generación 10 000 usuarios random 
		float j;
		string email = "";
		int r;
		for (int i = pow(10, 4) / 2; i < pow(10, 4); ++i) {

			r = rand() % nombres.size();

			for (const char& j : nombres.at(r)) {
				if(j!=' ') email += char(tolower(j));
			}

			Usuario* usuario = new Usuario(nombres.at(r),email + "@cineyesis.com",i,rand() % (75 - 5 + 1) + 5,i);
			
			email = "";
			if (RaizIngr == true && i != pow(10,4) / 2) {
				abUsuarios->insertar(usuario);
			}
			if (i == pow(10, 4) / 2 && RaizIngr == false) {
				abUsuarios->insertar(usuario);
				RaizIngr = true;
				i = -1;
			}	
			j = i;
			if (i / 1000 >= j / 1000 && i / 1000 < 10)
			{
				System::Console::SetCursorPosition(5 + i / 1000, 11);
				cout << char(220);
			}
		}
	}

	void generarRandomsCola(ArbolBinario<Usuario>* abUsuarios,
		Cola<Usuario>*& colaUsuarios) {

		for (int i = 0; i < 50; ++i) {
			colaUsuarios->enqueue(
				abUsuarios->get(rand()%((abUsuarios->cantidad()-10)))
			);
		}
	}

	void rellenarColaPrioridad(Cola<Usuario>* colaUsuarios, 
		ColaPrioridad<Usuario>& cpUsuarios) {
		Cola<Usuario> cola_temp = *colaUsuarios;

		for (int i = 0; i < colaUsuarios->getCant(); ++i) 
			cpUsuarios.push(cola_temp.dequeue());
	}
}
