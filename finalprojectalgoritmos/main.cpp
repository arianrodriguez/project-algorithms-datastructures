#include "Archivo.h"
#include "Utilidades.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;
using namespace System;


struct ConsoleAttributes {
	WORD attributes;
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
};

// Función para establecer el color de fondo de la consola
void setBackgroundColor(int colorCode, ConsoleAttributes& originalAttributes) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Guardar los atributos originales
	GetConsoleScreenBufferInfo(hConsole, &originalAttributes.consoleInfo);
	originalAttributes.attributes = originalAttributes.consoleInfo.wAttributes;

	// Establecer el nuevo color de fondo
	SetConsoleTextAttribute(hConsole, (originalAttributes.attributes & 0xFF) | (colorCode << 4));

}

// Función para restaurar el formato original de la consola
void restoreConsoleAttributes(const ConsoleAttributes& originalAttributes) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Restaurar los atributos originales
	SetConsoleTextAttribute(hConsole, originalAttributes.attributes);
	SetConsoleCursorPosition(hConsole, originalAttributes.consoleInfo.dwCursorPosition);
}

//vv Aca se crea el logo (Letras y lineas alrededor)
void banner() {
	Console::SetWindowSize(66, 40);
	Console::ForegroundColor = ConsoleColor::White;
	for (int i = 0; i < 66; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (j == 0 || j == 39)
			{
				if (i != 0 && i != 65)
				{
					Console::SetCursorPosition(i, j);
					cout << char(196);
				}

			}
			if (i == 0 || i == 65)
			{
				if (j != 39 && i != 1)
				{
					Console::SetCursorPosition(i, j);
					cout << char(179);
				}
				if (i == 65 && j == 39)
				{
					Console::SetCursorPosition(i, j);
					cout << char(254);
				}
				if (i == 0 && j == 0)
				{
					Console::SetCursorPosition(i, j);
					cout << char(254);
				}
				if (i == 65 && j == 0)
				{
					Console::SetCursorPosition(i, j);
					cout << char(254);
				}
				if (i == 0 && j == 39)
				{
					Console::SetCursorPosition(i, j);
					cout << char(254);
				}



			}
		}
		Console::SetCursorPosition(45, 38);
		Console::ForegroundColor = ConsoleColor::Gray;
		cout << "cineyesi-alpha V.10";
	}

	Console::ForegroundColor = ConsoleColor::Yellow;
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			//Letra 'E'

			if (i <= 1 || i >= 4 && i <= 5 || i >= 8 && i <= 10 || j <= 3) {
				Console::SetCursorPosition(44 + j, 4 + i);
				cout << char(219);
				Console::SetCursorPosition(24 + j, 15 + i);
				cout << char(219);
			}
			//Letra 'C'
			if (i <= 1 || i >= 8 && i <= 10 || j <= 3) {
				Console::SetCursorPosition(12 + j, 4 + i);
				cout << char(219);


			}
			//Letra 'I'
			if (j <= 3) {
				Console::SetCursorPosition(24 + j, 4 + i);
				cout << char(219);
				Console::SetCursorPosition(48 + j, 15 + i);
				cout << char(219);
			}

			//Letra 'N'
			if (j <= 2) {
				Console::SetCursorPosition(30 + j, 4 + i);
				cout << char(219);
				Console::SetCursorPosition(39 + j, 4 + i);
				cout << char(219);
			}
			if (i <= 2 && j <= 1) {
				Console::SetCursorPosition(33 + j, 5 + i);
				cout << char(219);
				Console::SetCursorPosition(35 + j, 6 + i);
				cout << char(219);
				Console::SetCursorPosition(37 + j, 7 + i);
				cout << char(219);
				Console::SetCursorPosition(38 + j, 9 + i);
				cout << char(219);
			}

			// "Y"

			if (i <= 3 && j <= 2) {
				Console::SetCursorPosition(12 + j, 15 + i);
				cout << char(219);
				Console::SetCursorPosition(19 + j, 15 + i);
				cout << char(219);
			}
			if (i <= 5 && j <= 3) {
				Console::SetCursorPosition(15 + j, 19 + i);
				cout << char(219);

			}
			if (i <= 1 && j <= 2) {
				Console::SetCursorPosition(13 + j, 18 + i);
				cout << char(219);
				Console::SetCursorPosition(18 + j, 18 + i);
				cout << char(219);
			}
			if (i <= 1 || i >= 4 && i <= 5 || i >= 8 && i <= 10 || j <= 3 && i <= 4) {
				Console::SetCursorPosition(36 + j, 15 + i);
				cout << char(219);
			}
			if (j <= 3 && i <= 4)
			{
				Console::SetCursorPosition(42 + j, 20 + i);
				cout << char(219);
			}




		}

	}

	Console::ForegroundColor = ConsoleColor::Red;
	for (int i = 0; i < 24; i++)
	{

		Console::SetCursorPosition(10, 2 + i);
		cout << char(176);

		Console::SetCursorPosition(55, 2 + i);
		cout << char(176);
	}
	for (int i = 0; i < 46; i++)
	{
		Console::SetCursorPosition(10 + i, 26);
		cout << char(176);
		Console::SetCursorPosition(10 + i, 2);
		cout << char(176);
	}

}
//Menu principal 
void menu(ConsoleAttributes CA, int op)
{
	Console::SetCursorPosition(13, 28);
	cout << "========================================";
	Console::SetCursorPosition(13, 29);
	cout << "                M  E  N  U              ";
	Console::SetCursorPosition(13, 30);
	cout << "========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;




	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Comprar Entradas";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Panel Administrativo";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Creditos";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Salir";

	}break;

	case 1:
	{
		setBackgroundColor(7, CA);
		Console::SetCursorPosition(23, 32);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[1]  Comprar Entradas";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Panel Administrativo";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Creditos";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Salir";
	}break;
	case 2:
	{

		Console::SetCursorPosition(23, 32);
		cout << "[1]  Comprar Entradas";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Panel Administrativo";
		Console::ForegroundColor = ConsoleColor::Yellow;
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Creditos";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Salir";
	}break;

	case 3:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Comprar Entradas";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Panel Administrativo";
		Console::SetCursorPosition(23, 34);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[3]  Creditos";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Salir";
	}break;
	case 4:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Comprar Entradas";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Panel Administrativo";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Creditos";
		Console::SetCursorPosition(23, 35);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[4]  Salir";
		Console::ForegroundColor = ConsoleColor::Yellow;
		restoreConsoleAttributes(CA);
	}break;

	default:
		break;
	}

}
//Menu cuando se pone administrador
void menuAdmin(ConsoleAttributes CA, int op)
{
	Console::SetCursorPosition(13, 28);
	cout << "==========================================";
	Console::SetCursorPosition(13, 29);
	cout << " M  E  N  U - A D M I N I S T R A T I V O";
	Console::SetCursorPosition(13, 30);
	cout << "==========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;




	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Registro De Ventas";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Usuarios Registrados";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Regresar";


	}break;

	case 1:
	{
		setBackgroundColor(7, CA);
		Console::SetCursorPosition(23, 32);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[1]  Registro De Ventas";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Usuarios Registrados";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Regresar";
	}break;
	case 2:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Registro De Ventas";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Usuarios Registrados";
		Console::ForegroundColor = ConsoleColor::Yellow;
		restoreConsoleAttributes(CA);

		Console::SetCursorPosition(23, 34);
		cout << "[3]  Regresar";
	}break;

	case 3:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Registro De Ventas";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Usuarios Registrados";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Regresar";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;

	}break;

	default:
		break;
	}

}
void menuAdmin1(ConsoleAttributes CA, int op)
{
	Console::SetCursorPosition(13, 28);
	cout << "==========================================";
	Console::SetCursorPosition(13, 29);
	cout << " M  E  N  U - A D M I N I S T R A T I V O";
	Console::SetCursorPosition(13, 30);
	cout << "==========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;

	

	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(15, 32);
		cout << "[1]  Buscar recibo por numero de codigo";
		Console::SetCursorPosition(15, 33);
		cout << "[2]  Visualizar todos los recibos";
		Console::SetCursorPosition(15, 34);
		cout << "[3]  Regresar";


	}break;

	case 1:
	{
		setBackgroundColor(7, CA);
		Console::SetCursorPosition(15, 32);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[1]  Buscar recibo por numero de codigo";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(15, 33);
		cout << "[2]  Visualizar todos los recibos";
		Console::SetCursorPosition(15, 34);
		cout << "[3]  Regresar";
	}break;
	case 2:
	{
		Console::SetCursorPosition(15, 32);
		cout << "[1]  Buscar recibo por numero de codigo";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(15, 33);
		cout << "[2]  Visualizar todos los recibos";
		Console::ForegroundColor = ConsoleColor::Yellow;
		restoreConsoleAttributes(CA);

		Console::SetCursorPosition(15, 34);
		cout << "[3]  Regresar";
	}break;

	case 3:
	{
		Console::SetCursorPosition(15, 32);
		cout << "[1]  Buscar recibo por numero de codigo";
		Console::SetCursorPosition(15, 33);
		cout << "[2]  Visualizar todos los recibos";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(15, 34);
		cout << "[3]  Regresar";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;

	}break;

	default:
		break;
	}

}
void menuAdmin2(ConsoleAttributes CA, int op)
{
	Console::SetCursorPosition(13, 28);
	cout << "==========================================";
	Console::SetCursorPosition(13, 29);
	cout << " M  E  N  U - A D M I N I S T R A T I V O";
	Console::SetCursorPosition(13, 30);
	cout << "==========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;

	

	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Mostrar EnOrden";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Mostrar PostOrden";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Mostrar PreOrden";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";


	}break;

	case 1:
	{
		setBackgroundColor(7, CA);
		Console::SetCursorPosition(23, 32);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[1]  Mostrar EnOrden";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Mostrar PostOrden";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Mostrar PreOrden";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";
	}break;
	case 2:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Mostrar EnOrden";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Mostrar PostOrden";
		Console::ForegroundColor = ConsoleColor::Yellow;
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Mostrar PreOrden";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";
	}break;

	case 3:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Mostrar EnOrden";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Mostrar PostOrden";
		Console::SetCursorPosition(23, 34);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[3]  Mostrar PreOrden";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";

	}break;
	case 4:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Mostrar EnOrden";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Mostrar PostOrden";
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Mostrar PreOrden";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
	}

	default:
		break;
	}

}
void menuAdmin3(ConsoleAttributes CA, int op)
{
	Console::SetCursorPosition(13, 28);
	cout << "==========================================";
	Console::SetCursorPosition(13, 29);
	cout << " M  E  N  U - A D M I N I S T R A T I V O";
	Console::SetCursorPosition(13, 30);
	cout << "==========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;

	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Atencion de Usuarios";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Buscar Usuario";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Visualizar usuarios";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";


	}break;

	case 1:
	{
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Atencion de Usuarios";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Buscar Usuario";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Visualizar usuarios";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";
	}break;
	case 2:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Atencion de Usuarios";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Buscar Usuario";
		Console::ForegroundColor = ConsoleColor::Yellow;
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Visualizar usuarios";
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";
	}break;

	case 3:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Atencion de Usuarios";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Buscar Usuario";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Visualizar usuarios";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";

	}break;
	case 4:
	{
		Console::SetCursorPosition(23, 32);
		cout << "[1]  Atencion de Usuarios";
		Console::SetCursorPosition(23, 33);
		cout << "[2]  Buscar Usuario";
		Console::SetCursorPosition(23, 34);
		cout << "[3]  Visualizar usuarios";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 35);
		cout << "[4]  Regresar";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
	}

	default:
		break;
	}

}
void menuAdmin4(ConsoleAttributes CA, int op)
{
	Console::SetCursorPosition(13, 3);
	cout << "==========================================";
	Console::SetCursorPosition(13, 4);
	cout << " M  E  N  U - A D M I N I S T R A T I V O";
	Console::SetCursorPosition(13, 5);
	cout << "==========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;


	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(23, 21);
		cout << "[1]  Atender Usuario";
		Console::SetCursorPosition(23, 22);
		cout << "[2]  No Atender Usuario";
		Console::SetCursorPosition(23, 23);
		cout << "[3]  Regresar";


	}break;

	case 1:
	{

		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(23, 21);
		cout << "[1]  Atender Usuario";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 22);
		cout << "[2]  No Atender Usuario";
		Console::SetCursorPosition(23, 23);
		cout << "[3]  Regresar";
	}break;
	case 2:
	{
		Console::SetCursorPosition(23, 21);
		cout << "[1]  Atender Usuario";
		Console::SetCursorPosition(23, 22);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[2]  No Atender Usuario";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(23, 23);
		cout << "[3]  Regresar";
	}break;

	case 3:
	{
		Console::SetCursorPosition(23, 21);
		cout << "[1]  Atender Usuario";
		Console::SetCursorPosition(23, 22);
		cout << "[2]  No Atender Usuario";
		Console::SetCursorPosition(23, 23);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[3]  Regresar";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;

	}break;

	default:
		break;
	}

}

//Se selecciona con teclas up down, retorna un valor que afecta como se ve el menu y asi
int selecciondeteclado(int key, int cont, int max)
{

	switch (key)
	{

	case 72:
	{//arriba tecla
		if (cont > 1)
		{
			cont--;
		}
	}break;
	case 80:
	{//abajo tecla
		if (cont < max)
		{
			cont++;
		}

	}break;

	default:

		break;
	}
	return cont;
}

void BannerPelis()
{
	Console::SetCursorPosition(3, 3);
	cout << "==========================================";
	Console::SetCursorPosition(3, 4);
	cout << "             P E L I C U L A S";
	Console::SetCursorPosition(3, 5);
	cout << "==========================================";
	Console::ForegroundColor = ConsoleColor::Yellow;
}

void MenuPeliculas(ConsoleAttributes CA, int op, ListaSimpleEnlazada<Funcion>* ListaPelis)
{

	Console::SetCursorPosition(5, 7);
	cout << "Cantidad De Peliculas: " << ListaPelis->getCantidad();
	Console::SetCursorPosition(5, 8);
	cout << "  Horarios:   ";
	Console::SetCursorPosition(5, 9);
	cout << "  [1]..Manana ";
	Console::SetCursorPosition(5, 10);
	cout << "  [2]..Tarde  ";
	Console::SetCursorPosition(5, 11);
	cout << "  [3]..Noche  ";
	Console::SetCursorPosition(5, 12);
	cout << "  [0]..Salir  ";

	switch (op)
	{
	case 1:
	{

		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(5, 9);
		cout << "  [1]..Manana ";
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(5, 10);
		cout << "  [2]..Tarde  ";
		Console::SetCursorPosition(5, 11);
		cout << "  [3]..Noche  ";
		Console::SetCursorPosition(5, 12);
		cout << "  [0]..Salir  ";

	}break;
	case 2:
	{

		Console::SetCursorPosition(5, 9);
		cout << "  [1]..Manana ";

		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(5, 10);
		cout << "  [2]..Tarde  ";
		restoreConsoleAttributes(CA);

		Console::SetCursorPosition(5, 11);
		cout << "  [3]..Noche  ";
		Console::SetCursorPosition(5, 12);
		cout << "  [0]..Salir  ";
	}break;
	case 3:
	{
		Console::SetCursorPosition(5, 9);
		cout << "  [1]..Manana ";



		Console::SetCursorPosition(5, 10);
		cout << "  [2]..Tarde  ";

		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(5, 11);
		cout << "  [3]..Noche  ";
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(5, 12);
		cout << "  [0]..Salir  ";
	}break;
	case 4:
	{
		Console::SetCursorPosition(5, 9);
		cout << "  [1]..Manana ";



		Console::SetCursorPosition(5, 10);
		cout << "  [2]..Tarde  ";


		Console::SetCursorPosition(5, 11);
		cout << "  [3]..Noche  ";
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(5, 12);
		cout << "  [0]..Salir  ";
		restoreConsoleAttributes(CA);
	}break;

	default:
		break;
	}

}

Funcion* FuncionPeliculas(ListaSimpleEnlazada<Funcion>* ListaPelis, ConsoleAttributes originalAttributes, int opcion, int key)
{

	int hora;
	int opz;
	int NumerodeOpciones = 4;
	Funcion* fEscogida;

	do
	{
		do
		{

			BannerPelis();
			MenuPeliculas(originalAttributes, opcion, ListaPelis);
			key = _getch();
			opcion = selecciondeteclado(key, opcion, NumerodeOpciones);


		} while (key != 13);



		opz = opcion;
		int id;
		system("cls");


		for (int i = 0; i < ListaPelis->getCantidad(); i++)
		{

			hora = std::stoi(ListaPelis->buscar(i)->getHora());

			switch (opz)
			{
			case 1:
			{
				if (hora < 12)
				{
					cout << endl;
					cout << ListaPelis->buscar(i)->getInfo();



				}
			}break;
			case 2:
			{
				if (hora < 12 && hora > 5)
				{
					cout << endl;
					cout << ListaPelis->buscar(i)->getInfo();
				}
			}break;
			case 3:
			{
				if (hora > 12)
				{
					cout << endl;
					cout << ListaPelis->buscar(i)->getInfo();
				}
			}break;
			case 4:
			{
				return 0;
			}break;
			default:
				break;
			}
		}
		std::cout << "\nEscoja ID de la funcion: ";
		cin >> id;
		fEscogida = fMain::peliculaInput(ListaPelis, id);


	} while (opz != 4 && opz != 1 && opz != 2 && opz != 3);
	//

	return fEscogida;

}

void menuDeCombos(ConsoleAttributes CA, int op, Pila<Combo>* pilaCombos)
{
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(3, 12);
	cout << "==========================================";
	Console::SetCursorPosition(3, 13);
	cout << "                C O M B O S";
	Console::SetCursorPosition(3, 14);
	cout << "==========================================";


	Console::SetCursorPosition(5, 10);
	cout << "Seleccione Cual combo desea consumir: ";
	Console::ForegroundColor = ConsoleColor::Green;

	switch (op)
	{

	case 0:
	{
		Console::SetCursorPosition(0, 16);
		cout << pilaCombos->search(0)->getInfo();
		Console::SetCursorPosition(0, 22);
		cout << pilaCombos->search(1)->getInfo();
		Console::SetCursorPosition(0, 29);
		cout << pilaCombos->search(2)->getInfo();
		Console::SetCursorPosition(0, 35);
		cout << "[0]... Salir";


	}break;

	case 1:
	{
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(0, 16);
		cout << pilaCombos->search(0)->getInfo();
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(0, 22);

		cout << pilaCombos->search(1)->getInfo();
		Console::SetCursorPosition(0, 29);
		cout << pilaCombos->search(2)->getInfo();
		Console::SetCursorPosition(0, 35);
		cout << "[0]... Salir";
	}break;
	case 2:
	{

		Console::SetCursorPosition(0, 16);
		cout << pilaCombos->search(0)->getInfo();

		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(0, 22);
		cout << pilaCombos->search(1)->getInfo();
		restoreConsoleAttributes(CA);
		Console::SetCursorPosition(0, 29);

		cout << pilaCombos->search(2)->getInfo();
		Console::SetCursorPosition(0, 35);
		cout << "[0]... Salir";
	}break;

	case 3:
	{
		Console::SetCursorPosition(0, 16);
		cout << pilaCombos->search(0)->getInfo();


		Console::SetCursorPosition(0, 22);
		cout << pilaCombos->search(1)->getInfo();

		Console::SetCursorPosition(0, 29);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Black;
		cout << pilaCombos->search(2)->getInfo();
		restoreConsoleAttributes(CA);

		Console::SetCursorPosition(0, 35);

		cout << "[0]... Salir";


	}break;
	case 4:
	{
		Console::SetCursorPosition(0, 16);
		cout << pilaCombos->search(0)->getInfo();


		Console::SetCursorPosition(0, 22);
		cout << pilaCombos->search(1)->getInfo();

		Console::SetCursorPosition(0, 29);

		cout << pilaCombos->search(2)->getInfo();


		Console::SetCursorPosition(0, 35);
		setBackgroundColor(7, CA);
		Console::ForegroundColor = ConsoleColor::Red;
		cout << "[0]... Salir";
		restoreConsoleAttributes(CA);
		Console::ForegroundColor = ConsoleColor::Yellow;
	}break;

	default:
		break;
	}
}


Combo* FuncionComboComida(Pila<Combo>* pilaCombos, ConsoleAttributes originalAttributes, int opcion, int key)
{
	Combo* cEscogido;
	int opC, id;
	int NumerodeOpciones = 4;
	opcion = 0;
	key = 0;
	do
	{



		do
		{


			menuDeCombos(originalAttributes, opcion, pilaCombos);
			key = _getch();
			opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

		} while (key != 13);



		opC = opcion;
		id = opC - 1;
		system("cls");

		switch (opC)
		{

		case 1:
		{
			cout << "\nUsted Selecciono:\n" << pilaCombos->search(0)->getInfo();

		}break;

		case 2:
		{
			cout << "\nUsted Selecciono:\n" << pilaCombos->search(1)->getInfo();
		}break;
		case 3:
		{
			cout << "\nUsted Selecciono:\n" << pilaCombos->search(2)->getInfo();
		}break;
		case 4:
		{
			return 0;
		}break;
		default:
			break;
		}


	} while (opC != 4 && opC != 1 && opC != 2 && opC != 3);
	cEscogido = fMain::comboInput(pilaCombos, id);
	return cEscogido;

}

void imprimir_cuadro(int ancho, int alto, int x, int y) {
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);

			if (i == 0 && j == 0)cout << char(218);
			if (i == 0 && j == ancho - 1)cout << char(191);

			if (i == alto - 1 && j == 0)cout << char(192);
			if (i == alto - 1 && j == ancho - 1)cout << char(217);

			if ((j == 0 || j == ancho - 1) && i > 0 && i < alto - 1)
				cout << char(179);
			if ((i == 0 || i == alto - 1) && j > 0 && j < ancho - 1)
				cout << char(196);

		}
	}
}

void creadores() {
	system("cls");

	Console::SetCursorPosition(66/2-10/2, 6);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "CREADORES";
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(66/2-47/2, 8);
	cout << "Nicolas Sebastian Esteban Garcia (U202217485) ";
	Console::SetCursorPosition(66/2-36/2, 9);
	cout << "Arian Rodriguez Vargas (U202212096)";
	Console::SetCursorPosition(66 / 2 - 36 / 2, 10);
	cout << "Fabia Herrera Aguirre (U202219422)";
	Console::SetCursorPosition(66/2-40/2, 11);
	cout << "Sebastian Ramirez Hoffmann (U202211894)";

	Console::SetCursorPosition(66/2-33/2, 14);
	cout << "Algoritmos y Estructura de datos";
	Console::SetCursorPosition(66 / 2 - 8 / 2, 15);
	cout << "Seccion";
	Console::SetCursorPosition(66 / 2 - 5 / 2, 16);
	cout << "SX33";
	Console::SetCursorPosition(66/2-9/2, 18);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "Profesor";
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(66/2-28/2, 19);
	cout << "John Edward Arias Orihuela ";
	
	Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(66 / 2 - 64 / 2, 22);

			cout << "                              #                               \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 23);
			cout << "                            ##                                \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 24);
			cout << "                   #       ####             #                 \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 25);
			cout << "                 ##       ######             ##               \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 26);
			cout << "               ##         ########            ##              \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 27);
			cout << "              ###         ##########          ###             \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 28);
			cout << "              ###          ##########         ####            \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 29);
			cout << "             ####            ##########       #####           \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 30);
			cout << "             #####             ######         #####           \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 31);
			cout << "             #######            #####       ######            \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 32);
			cout << "              ########          ###      ########             \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 33);
			cout << "               ############     #   ############              \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 34);
			cout << "                 #############################                \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 35);
			cout << "                   #########################                  \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 36);
			cout << "                       #################                      \n"; Console::SetCursorPosition(66 / 2 - 64 / 2, 37);
			Console::ForegroundColor = ConsoleColor::White;

			imprimir_cuadro(66, 40, 0, 0);
	

	


	
}
//Aqui estan el switch que va a usar la opcion que se eliga y se repite hasta que se seleccione Salir.
void MenuConSelecciondeOpciones(ConsoleAttributes originalAttributes, int opcion, int NumerodeOpciones, int key, 
	ListaSimpleEnlazada<Funcion>* ListaPelis, 
	Pila<Combo>* pilaCombos,
	Pila<Butaca>* butacas,
	HashTable<Recibo>*& htRecibos,
	ArbolBinario<Recibo>*& recibos,
	ArbolBinario<Usuario>*& abUsuarios,
	ColaPrioridad<Usuario>& cpUsuarios)
{
	Console::CursorVisible = false;
	Funcion* fEscogida;
	Butaca* bEscogida;
	Recibo* recibo;
	Usuario* usuario;
	Combo* cEscogido;
	CuentaBancaria* cBancaria;
	do
	{
		NumerodeOpciones = 4;
		opcion = 0;

		do
		{

			banner();
			menu(originalAttributes, opcion);
			key = _getch();
			opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

		} while (key != 13);


		system("cls");


		switch (opcion) {
		case 1:
		{
			cout << "Se escogio la opcion [1] Comprar entradas...\n\n";

			do {
				fEscogida = FuncionPeliculas(ListaPelis, originalAttributes, opcion, key);

				if (fEscogida != NULL) {
					Console::ForegroundColor = ConsoleColor::Gray;

					system("cls");
					usuario = fMain::inputUsario();
					usuario->setPos(abUsuarios->cantidad());
					usuario->setCodigo(abUsuarios->cantidad());
					recibo = new Recibo(); // hashtable
					recibo->setUsuario(usuario);
					recibo->setCodigo(usuario->getCodUsuario());
					/*
						por cada recibo instanciado sin conocer antes su funcion, butaca, combo
						sumar el costo manualmente
					*/
					recibo->setFuncion(fEscogida);
					recibo->sumarCosto(fEscogida->getPrecio());

					system("cls");
					fMain::actualizarResumenPago(recibo);

					cout << "Seleccion de butacas... \n\n";
					bEscogida = Utilidades::verButacasDisponibles(fEscogida, butacas);
					recibo->setButaca(bEscogida);
					cout << "\nButaca escogida: " << bEscogida->getCodigo();
					// ocupando la butaca (se queda actualizado si se mantiene en el programa abierto, sino tendria q guardarse en archivo y leerse las butacas ocupadas para cada funcion)
					fEscogida->pushButacaOcupada(bEscogida->getCodigo());
					system("pause>0");


					system("cls");
					fMain::actualizarResumenPago(recibo);

					cEscogido = FuncionComboComida(pilaCombos, originalAttributes, opcion, key);
					if (cEscogido != NULL) {
						recibo->setCombo(cEscogido);
						recibo->sumarCosto(cEscogido->getPrecio());
					}

					system("cls");
					fMain::actualizarResumenPago(recibo);
					
						cBancaria = fMain::inputMetodoPago(recibo);
						recibo->getUsuario()->setCB(cBancaria);
					
					

					system("pause>0");
					htRecibos->insertar(recibo->getCodigo(), recibo);
					recibos->insertar(recibo);
					abUsuarios->insertar(usuario);
					cpUsuarios.push(usuario);

					system("cls");
					recibo->getInfo();

					System::Console::ForegroundColor = System::ConsoleColor::Yellow;

					cout << "\n\n::Gracias por preferirnos!::";
					cout << "\nDisfruta de tu pelicula";
					cout << "\nSiguenos en nuestras redes sociales";
					System::Console::ForegroundColor = System::ConsoleColor::Blue;
					cout << "\n\tFacebook: cineyesis";
					System::Console::ForegroundColor = System::ConsoleColor::Red;
					cout << "\n\tInstagram: @cineyesisPE";
					System::Console::ForegroundColor = System::ConsoleColor::DarkGray;
					cout << "\n\tTiktok: @cineyesisPERU";

					system("pause>0");


					fEscogida = NULL;
				}

			} while (fEscogida != NULL);
			system("cls");
		}break;

		case 2:
		{
			//cout << "Se escogio la opcion [2] Panel administrativo...\n\n";
			opcion = 0;
			NumerodeOpciones = 3;
			do
			{


				do
				{

					banner();
					menuAdmin(originalAttributes, opcion);
					key = _getch();
					opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

				} while (key != 13);
				system("cls");

				switch (opcion)
				{
				case 1:
				{
				
					do {
						system("cls");
						opcion = 0;
						NumerodeOpciones = 3;
						do
						{

							banner();
							menuAdmin1(originalAttributes, opcion);
							key = _getch();
							opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

						} while (key != 13);
						switch (opcion)
						{
						case 1:
						{
							fMain::mostrarVentasRegistradas(recibos, htRecibos);
							system("pause>0");

							system("cls");
						}break;
						case 2:
						{
							system("cls");
							opcion = 0;
							NumerodeOpciones = 4;
							do
							{
								do
								{

									banner();
									menuAdmin2(originalAttributes, opcion);
									key = _getch();
									opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

								} while (key != 13);
								if (opcion != 4)
								{
									fMain::mostrarVentasRegistradasOrden(recibos, htRecibos, opcion);
									system("pause>0");
								}
								system("cls");
							} while (opcion != 4);
							opcion = 0;

						}break;


							default:
							break;
						}
							
						
						

					} while (opcion != 3);
					system("cls");
					opcion = 0;
						
				}break;
				case 2:
				{
					
					do
					{
						system("cls");
						opcion = 0;
						NumerodeOpciones = 4;
						do
						{

							banner();
							menuAdmin3(originalAttributes, opcion);
							key = _getch();
							opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

						} while (key != 13);

						switch (opcion)
						{
						case 1:
						{
							
							do
							{
								system("cls");
								opcion = 0;
								NumerodeOpciones = 3;
								do
								{


									fMain::controlUsuariosPrEdad(cpUsuarios, abUsuarios);
									menuAdmin4(originalAttributes, opcion);
									key = _getch();
									opcion = selecciondeteclado(key, opcion, NumerodeOpciones);

								} while (key != 13);
								if (opcion != 3)
								{


									if (opcion == 1) {
										cout << "\nAtendiendo usuario...";
										cpUsuarios.pop();
										System::Console::ForegroundColor = System::ConsoleColor::Green;
										cout << "\nUsuario atendido!";
									}
									else if (opcion == 2) {
										System::Console::ForegroundColor = System::ConsoleColor::Red;
										cout << "\nUsuario NO atendido";
									}
									getch();
									System::Console::ForegroundColor = System::ConsoleColor::Yellow;
							
								}
								system("cls");
							} while (opcion != 3);

							opcion = 0;
							
						}break;
						case 2:
						{
							system("cls");
							fMain::controlUsuariosBusqe(cpUsuarios, abUsuarios);
							getch();
							system("cls");
						
						}break;
						case 3:
						{
							system("cls");
							fMain::controlUsuariosVisAll(cpUsuarios, abUsuarios);
						}break;
						
						default:
							break;
						}

					} while (opcion != 4);
					system("cls");
					
					opcion = 0;
				
				}break;
				default:
					break;
				}


				
			} while (opcion != 3);
			
			
		}
		break;
		case 3:
		{
			// mostrar creditos yesi haz tu magia GAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

			cout << "muestra creditos";
			creadores();
		
			system("pause>0");
			system("cls");

		}break;
		default:
			break;
		}

	} while (opcion != 4);
}




int main() {
	srand(time(NULL));
	Console::CursorVisible = false;

	

	Archivo* controlArchivo = new Archivo();
	ListaDobleEnlazada<Pelicula>* listaPeliculas = new ListaDobleEnlazada<Pelicula>();
	controlArchivo->leerPeliculas(listaPeliculas);
	Console::SetCursorPosition(5, 10);
	cout << " L  O  A  D  I  N  G";

	ListaSimpleEnlazada<Fecha>* listaFechas = new ListaSimpleEnlazada<Fecha>();
	Utilidades::generarMes(listaFechas);
	Utilidades::asignarFechasPeliculas(listaPeliculas, listaFechas);

	//listaPeliculas->imprimir();


	Pila<Combo>* pilaCombos = new Pila<Combo>();
	controlArchivo->leerCombos(pilaCombos);
	//pilaCombos->print();


	Pila<Sede>* pilaSedes = new Pila<Sede>();
	controlArchivo->leerZonas(pilaSedes);
	//pilaSedes->print();

	ListaSimpleEnlazada<Funcion>* listaFunciones = new ListaSimpleEnlazada<Funcion>();
	Utilidades::generarFunciones(listaFunciones, listaPeliculas, pilaSedes);


	

	/*
		una sola instancia de butacas,
		cada "Funcion" ha generado aleatoriamente sus butacas ocupadas
	*/
	Pila<Butaca>* butacas = new Pila<Butaca>();
	Utilidades::generarButacas(butacas);

	// generación usuarios random
	ArbolBinario<Usuario>* abUsuarios = new ArbolBinario<Usuario>();
	Utilidades::generarUsuariosRandom(abUsuarios, controlArchivo->leerClientes());


	Cola<Usuario>* colaUsuarios = new Cola<Usuario>(); // asignando a usuarios random a la cola "esperando su atencion" < pow(10,4) evitemos petar ps yesi
	Utilidades::generarRandomsCola(abUsuarios, colaUsuarios);

	/*
		HASH TABLE
		key: codigo del recibo
		value: precio total del recibo

		[indice]: [precio recibo]
		0: S/. 89
		1: S/. 23
		
		entre 20 y 60 recibos generados de manera aleatoria
	*/
	HashTable<Recibo>* htRecibos = new HashTable<Recibo>();
	ArbolBinario<Recibo>* recibos = new ArbolBinario<Recibo>();

	Utilidades::generarRecibosRandom(listaFunciones, butacas, pilaCombos, htRecibos, recibos, abUsuarios);

	ColaPrioridad<Usuario> cpUsuarios;
	Utilidades::rellenarColaPrioridad(colaUsuarios, cpUsuarios);

	AVLTree<Usuario> avlUsuarios;
	//fMain::ingresarAVLUsuarios(recibos, htRecibos, avlUsuarios);
	Grafo<Usuario>* grafoUsuarios = new Grafo<Usuario>();
	//fMain::insertarAGrafo(cpUsuarios, abUsuarios, grafoUsuarios);
	system("cls");

	


	int opcion = 0;
	int key = 0;
	ConsoleAttributes originalAttributes{};

	int NumerodeOpciones = 4;

	MenuConSelecciondeOpciones(originalAttributes, opcion, NumerodeOpciones, key, 
		listaFunciones, pilaCombos, butacas, htRecibos, recibos, abUsuarios, cpUsuarios);

	cout << "Saliendo....";
	_sleep(50);

	system("pause");
	return 0;
}