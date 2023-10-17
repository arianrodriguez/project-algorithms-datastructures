#pragma once
#include "Utilidades.h"
#define NOT_FOUND -1

template<class T>
class BusquedaBinaria {
public:
	BusquedaBinaria(){}

	static int bbArbol(ArbolBinario<T>* ab, int x) {
		int low = 0;
		int high = ab->cantidad() - 1;
		int mid;
		while (low < high) {
			mid = (low + high) / 2;
			if (ab->get(mid)->getDistintivo() < x) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
		}
		return (low == high) && ab->get(low)->getDistintivo() == x ? low : NOT_FOUND;
	}
};
