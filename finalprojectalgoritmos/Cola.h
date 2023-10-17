#pragma once
#include <iostream>
using namespace std;
template<class T>
class NodoC {
public:
	T* elem;
	NodoC<T>* sgt;
};

template<class T>
class Cola {
private:
	NodoC<T>* inicio;
	NodoC<T>* fin;
	int cant;

public:
	Cola() :inicio(NULL), fin(NULL), cant(0) {}
	~Cola() {}

	Cola<T>& operator=(const Cola<T>& other) {
		if (this != &other) {
			// Limpiar la cola actual
			NodoC<T>* temp = inicio;
			while (temp != NULL) {
				NodoC<T>* siguiente = temp->sgt;
				delete temp->elem;
				delete temp;
				temp = siguiente;
			}

			// Copiar elementos de la cola 'other'
			NodoC<T>* tempOther = other.inicio;
			while (tempOther != NULL) {
				T* elemCopy = new T(*tempOther->elem);
				enqueue(elemCopy);
				tempOther = tempOther->sgt;
			}

			cant = other.cant;
		}

		return *this;
	}

	bool isEmpty() { return inicio == NULL; }
	void enqueue(T* elem) {
		NodoC<T>* nodo = new NodoC<T>;
		nodo->elem = elem;
		if (isEmpty()) {
			inicio = nodo;
			fin = inicio;
		}
		else {
			fin->sgt = nodo;
			fin = nodo;
		}
		nodo = NULL;
		cant++;
	}
	T* dequeue() {
		T* elem = inicio->elem;
		if (inicio == fin) {
			inicio = NULL;
			fin = NULL;
		}
		else {
			inicio = inicio->sgt;
		}
		return elem;
	}
	void print() {
		if (isEmpty()) return;
		NodoC<T>* temp = inicio;
		while (temp != fin->sgt) {
			std::cout << temp->elem->getInfo();
			temp = temp->sgt;
		}
	}
	int getCant() { return this->cant; }
};
