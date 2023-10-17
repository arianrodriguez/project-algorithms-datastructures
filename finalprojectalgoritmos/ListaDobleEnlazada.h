#pragma once
#include <iostream>

/*
	esta clase contiene la lista de películas almacenadas,
	luego de haberlas leido desde el archivo .txt
*/

template<class T>
class NodoLD {
public:
	T* elemento;
	NodoLD* siguiente;
	NodoLD* anterior;
};

template<class T>
class ListaDobleEnlazada {
private:
    NodoLD<T>* primero;
    NodoLD<T>* ultimo;
    int cant;

public:
    ListaDobleEnlazada() {
        primero = NULL;
        ultimo = NULL;
        cant = 0;
    }
    void insertar(T* elemento) {
        NodoLD<T>* nuevoNodo = new NodoLD<T>;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = NULL;
        nuevoNodo->anterior = ultimo;
        if (ultimo != NULL) {
            ultimo->siguiente = nuevoNodo;
        }
        else {
            primero = nuevoNodo;
        }
        ultimo = nuevoNodo;
        cant++;
    }

    void eliminar(T* elemento) {
        NodoLD<T>* actual = primero;
        while (actual != NULL) {
            if (actual->elemento == elemento) {
                if (actual == primero) {
                    primero = actual->siguiente;
                    if (primero != NULL) {
                        primero->anterior = NULL;
                    }
                }
                else if (actual == ultimo) {
                    ultimo = actual->anterior;
                    if (ultimo != NULL) {
                        ultimo->siguiente = NULL;
                    }
                }
                else {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                }
                delete actual;
                return;
            }
            actual = actual->siguiente;
        }
    }

    NodoLD<T>* buscar(int pos) {
        NodoLD<T>* actual = primero;
        while (actual != NULL) {
            if (actual->elemento->getPosicion() == pos) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return NULL;
    }

    void imprimir() {
        // se muestra el getInfo() de la pelicula
        NodoLD<T>* actual = primero;
        while (actual != NULL) {
                                 // aquí realizar cambio si se requiere mostrar otra cosa
            std::cout << actual->elemento->getInfo() << "\n";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    int getCantidad() { return this->cant; }
};