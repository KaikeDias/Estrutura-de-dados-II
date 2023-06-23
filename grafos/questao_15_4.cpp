#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, int start, int end, vector<int>& path, vector<vector<int>>& allPaths) {
    path.push_back(start);  // Adiciona o vértice atual ao caminho

    if (start == end) {  // Se o vértice atual é o destino, adiciona o caminho encontrado à lista de caminhos
        allPaths.push_back(path);
    }

    for (int vertex : graph[start]) {
        if (find(path.begin(), path.end(), vertex) == path.end()) {  // Evita ciclos verificando se o vértice já está no caminho
            dfs(graph, vertex, end, path, allPaths);  // Chama recursivamente a busca em profundidade para os vértices adjacentes
        }
    }

    path.pop_back();  // Remove o vértice atual do caminho antes de retroceder
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Vertice 0
        {2, 3},    // Vertice 1
        {3, 4},    // Vertice 2
        {4},       // Vertice 3
        {2, 5},    // Vertice 4
        {}         // Vertice 5
    };

    int start = 0;
    int end = 4;

    vector<int> path;
    vector<vector<int>> allPaths;

    dfs(graph, start, end, path, allPaths);

    // Imprime todos os caminhos encontrados
    for (const auto& p : allPaths) {
        for (int vertex : p) {
            cout << vertex << " -> ";
        }
        cout << endl;
    }

    return 0;
}

//b) o primeiro caminho encontrado pelo algoritmo DFS não é necessariamente o menor caminho entre o vértice de partida e o vértice de destino. O algoritmo DFS pode encontrar caminhos mais longos antes de encontrar um caminho mais curto, dependendo da ordem em que os vértices são visitados.