#pragma once
#include <iostream>
template<class T>
class NodoLS {
public:
	T* elemento;
	NodoLS* sgt;
};

template<class T>
class ListaSimpleEnlazada {
private:
	NodoLS<T>* primer_nodo;
	int cant;

public:
	ListaSimpleEnlazada() : primer_nodo(NULL), cant(0) {}
	~ListaSimpleEnlazada() {}

	void agregar(T* elemento) {
		NodoLS<T>* nuevo_nodo = new NodoLS<T>;
		nuevo_nodo->elemento = elemento;
		nuevo_nodo->sgt = NULL;

		if (primer_nodo == NULL)
			primer_nodo = nuevo_nodo;
		else {
			NodoLS<T>* nodo_aux = primer_nodo;
			while (nodo_aux->sgt != NULL)
				nodo_aux = nodo_aux->sgt;
			nodo_aux->sgt = nuevo_nodo;
		}
		cant++;
	}
	void eliminar(int pos) {
		if (primer_nodo == NULL)
			return;
		if (primer_nodo->elemento->getPosicion() == pos) { // eliminar a través de la posición del objeto
			NodoLS<T>* nodo_temp = primer_nodo;
			primer_nodo = primer_nodo->sgt;
			delete nodo_temp;
			return;
		}

		NodoLS<T>* nodo_temp = primer_nodo;
		while (nodo_temp->sgt != NULL && nodo_temp->sgt->elemento->getPosicion() != pos)
			nodo_temp = nodo_temp->sgt;
		if (nodo_temp->sgt != NULL) {
			NodoLS<T>* nodo_aux = nodo_temp->sgt;
			nodo_temp->sgt = nodo_aux->sgt;
			delete nodo_aux;
		}
	}
	void imprimir() {
		NodoLS<T>* nodo_aux = primer_nodo;
		while (nodo_aux != NULL) {
			cout << nodo_aux->elemento->getInfo() << "\n";
			nodo_aux = nodo_aux->sgt;
		}
	}
	T* buscar(int posicion) {
		NodoLS<T>* nodo_aux = primer_nodo;
		while (nodo_aux != NULL)
		{
			while (nodo_aux->elemento->getPosicion() == posicion) {
				return nodo_aux->elemento;
			}
			nodo_aux = nodo_aux->sgt;
		}


		return NULL;
	}
	void set(int posicion, T* elemento) {
		NodoLS<T>* nodo_aux = primer_nodo;
		while (nodo_aux->elemento->getPosicion() != posicion && nodo_aux->sgt != NULL) {
			nodo_aux = nodo_aux->sgt;
		}
		int pos = nodo_aux->elemento->getPosicion();
		nodo_aux->elemento = elemento;
		nodo_aux->elemento->setPosicion(pos);

	}
	NodoLS<T>* getPrimerNodo() const {
		return primer_nodo;
	}


	int getCantidad() { return this->cant; }
};