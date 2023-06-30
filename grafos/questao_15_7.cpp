//Grupo: Kaike Dias, Kelson Eduardo, Igor Julliano

#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int numVertices;
    vector<int>* adjLists;
    vector<string> disciplineNames;
    vector<int> inDegree;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new vector<int>[vertices];
        inDegree.resize(vertices, 0);
        disciplineNames.resize(vertices);
    }

    void addEdge(int src, int dest, string disciplineName) {
        adjLists[src].push_back(dest);
        inDegree[dest]++;
        disciplineNames[src] = disciplineName;
    }

    void topologicalSort() {
        queue<int> q;
        vector<int> semester(numVertices, 0); // Armazena o número do semestre de cada disciplina

        // Inicializa a fila com os vértices que não têm arestas de entrada
        for (int i = 0; i < numVertices; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                semester[i] = 1; // Define o primeiro semestre para as disciplinas sem pré-requisitos
            }
        }

        cout << "Disciplinas que podem ser feitas em um mesmo semestre:\n";

        int currentSemester = 1;
        while (!q.empty()) {
            int size = q.size();
            cout << currentSemester << ": ";

            vector<string> semesterDisciplines;

            for (int i = 0; i < size; i++) {
                int v = q.front();
                q.pop();

                semesterDisciplines.push_back(disciplineNames[v]);

                // Atualiza o número do semestre para as disciplinas adjacentes
                for (int adj : adjLists[v]) {
                    inDegree[adj]--;

                    if (inDegree[adj] == 0) {
                        q.push(adj);
                        semester[adj] = currentSemester + 1; // Define o próximo semestre para as disciplinas sem pré-requisitos restantes
                    }
                }
            }

            // Ordena as disciplinas em ordem alfabética
            sort(semesterDisciplines.begin(), semesterDisciplines.end());

            for (string discipline : semesterDisciplines) {
                cout << discipline << ", ";
            }

            cout << endl;
            currentSemester++;
        }
    }
};

int main() {
    int numVertices = 8;
    Graph graph(numVertices);

    graph.addEdge(0, 1, "Arquitetura de Computadores");
    graph.addEdge(1, 3, "Algoritmos");
    graph.addEdge(1, 2, "Linguagem de Programação");
    graph.addEdge(3, 4, "Programação Orientada a Objetos");
    graph.addEdge(2, 5, "Estrutura de Dados");
    graph.addEdge(2, 4, "Calculo I");
    graph.addEdge(4, 6, "Calculo II");
    graph.addEdge(6, 7, "Calculo Numerico Computacional");
    graph.addEdge(5, 7, "Banco de Dados");

    graph.topologicalSort();

    return 0;
}
