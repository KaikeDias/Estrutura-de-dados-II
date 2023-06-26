//Grupo: Kaike Dias, Kelson Eduardo, Igor Julliano

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int numVertices;
    vector<int>* adjLists;
    vector<int> inDegree;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new vector<int>[vertices];
        inDegree.resize(vertices, 0);
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        inDegree[dest]++;
    }

    void topologicalSort() {
        queue<int> q;

        // Inicializa a fila com os vértices que não têm arestas de entrada
        for (int i = 0; i < numVertices; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        cout << "Ordenação topológica resultante:\n";

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            // Remove o vértice atual e atualiza as contagens de grau de entrada dos vértices adjacentes
            for (int adj : adjLists[v]) {
                inDegree[adj]--;

                if (inDegree[adj] == 0) {
                    q.push(adj);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int numVertices = 9;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    // Arquitetura de Computadores -> Algoritmos
    graph.addEdge(1, 2);
    // Algoritmos -> Linguagem de Programação
    graph.addEdge(2, 3);
    // Linguagem de Programação -> Programação Orientada a Objetos
    graph.addEdge(2, 7);
    // Linguagem de Programação -> Estrutura de Dados
    graph.addEdge(3, 6);
    // Programação Orientada a Objetos -> Banco de Dados
    graph.addEdge(3, 7);
    // Programação Orientada a Objetos -> Estrutura de Dados
    graph.addEdge(4, 5);
    // Matemática Discreta -> Cálculo I
    graph.addEdge(5, 6);
    // Cálculo I -> Cálculo II
    graph.addEdge(6, 8);
    // Cálculo II -> Cálculo Numérico Computacional

    graph.topologicalSort();

    return 0;
}

/*
OUTPUT

Ordenação topológica resultante:
0 4 1 5 2 3 6 7 8
*/
