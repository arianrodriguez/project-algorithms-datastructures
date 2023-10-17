#pragma once
#include <iostream>
#include <list>
using namespace std;
/*
	std::list
	std::pair -> iterador: iterador.first, iterador.second
	std::make_pair()
*/
template<class T>
class HashTable {
private:
	int table_size, numElem;
	list< pair<int, T*> >* tabla;

	int funcionHash(int key) {
		return key % table_size;
	}

	int funcionHashCombinacionMatematica(const int& key) {
		int hash = key;
		hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
		hash = ((hash >> 16) ^ hash) * 0x45d9f3b;
		hash = (hash >> 16) ^ hash;
		return hash % table_size;
	}

	int funcionHashBernstein(const int& key) {
		unsigned int hash = 5381;
		const char* str = reinterpret_cast<const char*>(&key);
		for (size_t i = 0; i < sizeof(key); ++i) {
			hash = ((hash << 5) + hash) + str[i];
		}
		return hash % table_size;
	}

	int funcionHashFNV1a(const int& key) {
		const unsigned int fnv_prime = 0x01000193;
		unsigned int hash = 0x811c9dc5;
		const char* str = reinterpret_cast<const char*>(&key);
		for (size_t i = 0; i < sizeof(key); ++i) {
			hash ^= str[i];
			hash *= fnv_prime;
		}
		return hash % table_size;
	}

public:
	HashTable(int table_size = 100) : table_size(table_size) {
		// hashmap de listas enlazadas simples
		/*
			indice - contenido(listas)
			2: [(int, T*)] -> [(int,T*)]
			0: (int, T*)]
			1:
		*/
		tabla = new list<pair<int, T*>>[table_size];
		numElem++;
	}
	~HashTable() {}

	void insertar(const int& key, T* elemento) {
		int indice = funcionHash(key);
		tabla[indice].push_back(make_pair(key, elemento));
		// a la lista (tabla) de pares, hazle un pushback en el indice generado, de un nuevo par (key-int, valor-T*)
	}
	void eliminar(const int& key) {
		int indice = funcionHash(key);
		for (auto it : tabla[indice]) { // recorrerá cada lista que tiene ese indice, como son pares, devuelve un iterador
			if (it.first == key) {
				tabla[indice].remove(it);
				break;
			}
		}
	}
	T* getValue(const int& key) {
		int indice = funcionHash(key);

		for (const auto& par : tabla[indice]) {
			if (par.first == key) {
				return par.second;
			}
		}
		return nullptr;
	}
	void print() {
		for (int i = 0; i < table_size; ++i) {
			cout << i << ": ";
			for (const auto& par : tabla[i])
				cout << par.second->getDistintivo() << " ";
			cout << endl;
		}
	}
	T* buscar(const int& key) {
		int indice = funcionHash(key);

		for (const auto& par : tabla[indice]) {
			if (par.first == key) {
				return par.second;
			}
		}

		return nullptr; // nunca lo devolverá nulo porq en la llamada ya se valida que el cod este en los limites
	}
};