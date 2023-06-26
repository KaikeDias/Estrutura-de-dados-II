//Grupo: Kaike Dias, Kelson Eduardo, Igor Julliano

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
    }

    void insertItem(int src, int dest) {
        adjLists[src].push_back(dest);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int dest : adjLists[i]) {
                cout << dest << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    graph.insertItem(0, 1);
    graph.insertItem(0, 3);
    graph.insertItem(0, 2);
    graph.insertItem(1, 0);
    graph.insertItem(1, 3);
    graph.insertItem(2, 0);
    graph.insertItem(2, 3);
    graph.insertItem(2, 4);
    graph.insertItem(3, 1);
    graph.insertItem(3, 0);
    graph.insertItem(3, 2);
    graph.insertItem(3, 5);
    graph.insertItem(4, 2);
    graph.insertItem(4, 5);
    graph.insertItem(5, 3);
    graph.insertItem(5, 4);

    graph.printGraph();

    return 0;
}
