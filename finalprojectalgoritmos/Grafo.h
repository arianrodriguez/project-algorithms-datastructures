#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
class Grafo {
private:
    std::unordered_map<T*, std::vector<T*>> adjacencyList;

public:
    Grafo() {}

    void agregarVertice(T* vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = std::vector<T*>();
        }
    }

    void agregarArista(T* source, T* destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }

    void mostrarGrafo() {
        for (const auto& pair : adjacencyList) {
            std::cout << "Vertice " << pair.first << " esta conectado con: ";
            for (const auto& vertex : pair.second) {
                std::cout << vertex->getNombre() << " ";
            }
            std::cout << std::endl;
        }
    }
};
/*
int main() {
    Grafo<int> graph;

    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    graph.displayGraph();

    return 0;
}
*/