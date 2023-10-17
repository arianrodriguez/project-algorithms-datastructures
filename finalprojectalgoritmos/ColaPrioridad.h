#pragma once
#include "Utilidades.h"
using namespace std;

template<class T>
class ColaPrioridad {
private:
    vector<T*> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int padre = (i - 1) / 2;
            if (heap[i]->getEdad() > heap[padre]->getEdad())
                swap(heap[i], heap[padre]);
            else break;

            i = padre;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (index < n) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < n && heap[leftChild]->getEdad() > heap[largest]->getEdad())
                largest = leftChild;

            if (rightChild < n && heap[rightChild]->getEdad() > heap[largest]->getEdad())
                largest = rightChild;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    bool isEmpty() const {
        return heap.empty();
    }

    void push(T* value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T* top() const {
        return heap[0];
    }

    void pop() {
        if (isEmpty())
            return;

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }
};