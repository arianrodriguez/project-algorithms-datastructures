#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

template<class T>
class NodoAB {
public:
    T* elemento;
    NodoAB<T>* izq;
    NodoAB<T>* der;


    NodoAB(T* elemento) : elemento(elemento),
        izq(nullptr), der(nullptr) { }
};

template<class T>
class ArbolBinario {
private:
    NodoAB<T>* raiz;

    typedef function<int(T*, T*)> Comp; //Lambda
    Comp comparar; // lambda de criterio de comparación

    void(*procesar)(T*);

    void _insertar(NodoAB<T>* nodo_actual, T* elemento) {
        if (elemento->getDistintivo() < nodo_actual->elemento->getDistintivo()) {
            if (nodo_actual->izq == nullptr) {
                nodo_actual->izq = new NodoAB<T>(elemento);
                //cout << "Se crea nodo nuevo.";
            }
            else {
                _insertar(nodo_actual->izq, elemento);
            }
        }
        else {
            if (nodo_actual->der == nullptr) {
                nodo_actual->der = new NodoAB<T>(elemento);
               // cout << "Se crea nodo nuevo.";
            }
            else {
                _insertar(nodo_actual->der, elemento);
            }
        }
    }
    void _imprimir(NodoAB<T>* nodo_actual, int cont) {
        if (nodo_actual == nullptr) return;
        else {
            _imprimir(nodo_actual->der, cont + 1);

            // impresión del árbol en forma horizontal
            for (int i = 0; i < cont; ++i) cout << "   ";
            cout << "|-- " << nodo_actual->elemento->getDistintivo() << endl;

            _imprimir(nodo_actual->izq, cont + 1);
        }
    }
    NodoAB<T>* _minimo(NodoAB<T>* nodo_actual) {
        if (nodo_actual == nullptr) return nullptr;
        if (nodo_actual->izq) return _minimo(nodo_actual->izq);//si tiene hijo izq buscamos la parte mas izq posible
        else return nodo_actual; //si no tiene hijo izq, retornamos el mismo nodo
    }
    NodoAB<T>* _maximo(NodoAB<T>* nodo_actual) {
        if (nodo_actual == nullptr) return nullptr;
        if (nodo_actual->der) return _maximo(nodo_actual->der);//si tiene hijo der buscamos la parte mas der posible
        else return nodo_actual; //si no tiene hijo der, retornamos el mismo nodo
    }
    NodoAB<T>* _busquedaNodo(NodoAB<T>* nodo_actual, T* elemento) {
        if (nodo_actual == nullptr || nodo_actual->elemento == elemento) {//si el arbol está vacio o si el nodo es igual al elemento
            return nodo_actual;
        }
        else if (elemento < nodo_actual->elemento) {
            return _busquedaNodo(nodo_actual->izq, elemento);
        }
        else {
            return _busquedaNodo(nodo_actual->der, elemento);
        }
    } 
    int getSize(NodoAB<T>* node) {
        if (node == nullptr) {
            return NULL;
        }
        else {
            return getSize(node->izq) + getSize(node->der) + 1;
        }
    }
    T* _getElemento(NodoAB<T>* node, int pos) {
        if (node == nullptr) {
            // Si el nodo es nulo, no hay elementos en la posición solicitada
            // Puedes manejar este caso según tus necesidades, como lanzar una excepción
            // o devolver un valor especial para indicar que no se encontró ningún elemento
            cout << "NO HAY EN [" << pos << "]";
            


        }
        else {
            int cizq = getSize(node->izq);
            
            if (pos == cizq) {
                // La posición solicitada coincide con el nodo actual
                
                return node->elemento;
            }
            else if (pos <= cizq) {
                // La posición está en el subárbol izquierdo
                return _getElemento(node->izq, pos);
            }
            else {
                // La posición está en el subárbol derecho
                return _getElemento(node->der, pos - cizq - 1);
            }
        }
    }

    void _enOrden(NodoAB<T>* nodo) {
        if (nodo == nullptr) return;
        _enOrden(nodo->izq);
        procesar(nodo->elemento);
        _enOrden(nodo->der);
    }

    void _preOrden(NodoAB<T>* nodo) {
        if (nodo == nullptr) return;
        procesar(nodo->elemento);
        _preOrden(nodo->izq);
        _preOrden(nodo->der);
    }

    void _postOrden(NodoAB<T>* nodo) {
        if (nodo == nullptr) return;
        _postOrden(nodo->izq);
        _postOrden(nodo->der);
        procesar(nodo->elemento);
    }
    bool _vacio() {
        return raiz == nullptr;
    }
    int _cantidad(NodoAB<T>* nodo) {
        //La cantidad de nodos del árbol es:
        //	0 si es vacío
        //	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha

        if (nodo == nullptr)
            return 0;
        else
        {
            int ci, cd;
            ci = _cantidad(nodo->izq);
            cd = _cantidad(nodo->der);
            return 1 + ci + cd;
        }

    }
    
    bool _eliminar(NodoAB<T>*& nodo, T* e) {
        if (nodo == nullptr) return false;
        else {
            int r = comparar(nodo->elemento, e);
            if (r < 0) {
                return _eliminar(nodo->der, e);
            }
            else if (r > 0) {
                return _eliminar(nodo->izq, e);
            }
            else { // r==0 es porque se encontró el elemento e en el arbol
                if (nodo->der == nullptr && nodo->izq == nullptr) {//caso 1
                    nodo = nullptr;
                    delete nodo;
                    return true;
                }
                else if (nodo->izq == nullptr) { //caso 2
                    nodo = nodo->der;
                    return true;
                }
                else if (nodo->der == nullptr) { //caso 3
                    nodo = nodo->izq;
                    return true;
                }
                else { //caso 4
                    NodoAB<T>* aux = nodo->der; //Se establece buscar el menor elemento por la derecha
                    while (aux->izq != nullptr)
                    {
                        aux = aux->izq; //Se obtiene la hoja menor
                    }
                    nodo->elemento = aux->elemento; //Se actualiza el elemento en el nodo raiz y
                    return _eliminar(nodo->der, aux->elemento); //se envía a eliminar el elemento en el arbol por la derecha
                }
            }
        }
    }

public:
    ArbolBinario() : raiz(nullptr) {
        this->comparar = [](T* a, T* b)->int {return a->getDistintivo() - b->getDistintivo(); };
        this->procesar = [](T* e) {
            e->getInfo();
        };
    }

    void insertar(T* elemento) {
        (raiz == nullptr) ? raiz = new NodoAB<T>(elemento) : _insertar(raiz, elemento);
    }
    void imprimir() {
        _imprimir(raiz, 0);
    }
    T* hallarMinimo() { return _minimo(raiz)->elemento; }
    T* hallarMaximo() { return _maximo(raiz)->elemento; }
    void enOrden() {
        _enOrden(raiz);
    }
    void preOrden() {
        _preOrden(raiz);
    }
    void postOrden() {
        _postOrden(raiz);
    }
    int cantidad() {
        return _cantidad(raiz);
    }
    bool eliminar(T* e) {
        return _eliminar(raiz, e);
    }
    T* get(int pos) {
        return _getElemento(raiz, pos);
    }
};