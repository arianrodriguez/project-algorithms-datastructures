#pragma once
#include <iostream>

template<class T>
class NodoP {
public:
    T* elem;
    NodoP<T>* sgt;
};

template<class T>
class Pila {
private:
    NodoP<T>* top;
    int cant;

public:
    Pila() :top(NULL), cant(0) {}
    ~Pila() {
        while (top != nullptr) {
            NodoP<T>* nodo = top;
            top = top->sgt;
            delete nodo;
        }
    }

    // Constructor de copia
    Pila(const Pila& other) : top(nullptr), cant(0) {
        NodoP<T>* otroTop = other.top;
        Pila<T> pilaTemp;  // Pila temporal para preservar el orden de los elementos

        // Copiar los elementos de la pila original a la pila temporal
        while (otroTop != nullptr) {
            pilaTemp.add(new T(*(otroTop->elem)));
            otroTop = otroTop->sgt;
        }

        // Extraer los elementos de la pila temporal y agregarlos a la nueva pila
        while (pilaTemp.top != nullptr) {
            add(pilaTemp.remove());
        }
    }

    // Operador de asignación (operator=)
    Pila& operator=(const Pila& other) {
        if (this != &other) {
            // Liberar la memoria ocupada por la pila actual
            while (top != nullptr) {
                NodoP<T>* nodo = top;
                top = top->sgt;
                delete nodo;
            }

            NodoP<T>* otroTop = other.top;
            Pila<T> pilaTemp;  // Pila temporal para preservar el orden de los elementos

            // Copiar los elementos de la pila original a la pila temporal
            while (otroTop != nullptr) {
                pilaTemp.add(new T(*(otroTop->elem)));
                otroTop = otroTop->sgt;
            }

            // Extraer los elementos de la pila temporal y agregarlos a la nueva pila
            while (pilaTemp.top != nullptr) {
                add(pilaTemp.remove());
            }
        }

        return *this;
    }

    void add(T* elem) {
        NodoP<T>* nodo = new NodoP<T>;
        nodo->elem = elem;
        nodo->sgt = top;
        top = nodo;
        this->cant++;
    }
    T* remove() {
        NodoP<T>* nodo = top;
        T* elem = nodo->elem;
        top = nodo->sgt;
        delete nodo;
        return elem;
    }
    T* search(int pos) {
        int temp = cant;
        NodoP<T>* actual = top;
        while (temp > 0) {
            T* elem = actual->elem;
            if (elem->getPosicion() == pos)
            {
                return elem;
            }

            actual = actual->sgt;
            temp--;
        }
        return nullptr;
    }
    void print() {
        NodoP<T>* top_temp = top;
        while (top_temp != NULL) {
            std::cout << top_temp->elem->getInfo() << "\n";
            top_temp = top_temp->sgt;
        }
    }
    int getCant() { return this->cant; }
    NodoP<T>* getTop() { return top; }
};