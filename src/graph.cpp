#include "graph.hpp"

#include <algorithm>
#include <iostream>

Graph::Graph(int V) : V(V), adj(V), color(V, -1) {}

bool Graph::isValidVertex(int v) { return v >= 0 && v < V; }

void Graph::addEdge(int v, int w) {
    if (!isValidVertex(v) || !isValidVertex(w)) {
        std::cout << "Неверные вершины. Попробуйте еще раз.\n";
        return;
    }
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::removeEdge(int v, int w) {
    if (!isValidVertex(v) || !isValidVertex(w)) {
        std::cout << "Неверные вершины. Попробуйте еще раз.\n";
        return;
    }
    adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), w), adj[v].end());
    adj[w].erase(std::remove(adj[w].begin(), adj[w].end(), v), adj[w].end());
}

void Graph::colorGraph() {
    color[0] = 0;
    for (int u = 1; u < V; u++) {
        std::vector<bool> available(V, false);
        for (int i : adj[u])
            if (color[i] != -1) available[color[i]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false) break;

        color[u] = cr;
    }
}

void Graph::printGraph() {
    for (int u = 0; u < V; u++) {
        std::cout << "Vertex " << u << " ---> Color " << color[u] << "\n";
        std::cout << "Adjacent vertices: ";
        for (auto v : adj[u]) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}

void Graph::shortestPath(int s, int d) {
    if (!isValidVertex(s) || !isValidVertex(d)) {
        std::cout << "Неверные вершины. Попробуйте еще раз.\n";
        return;
    }

    std::vector<int> dist(V, -1);
    std::queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i : adj[u]) {
            if (dist[i] == -1) {
                q.push(i);
                dist[i] = dist[u] + 1;
                if (i == d) {
                    std::cout << "Кратчайший путь от " << s << " до " << d << " составляет " << dist[d] << " шагов.\n";
                    return;
                }
            }
        }
    }

    if (dist[d] == -1) {
        std::cout << "Путь от " << s << " до " << d << " не существует.\n";
    }
}

int Graph::getColor(int v) {
    if (isValidVertex(v)) {
        return color[v];
    } else {
        std::cout << "Неверная вершина. Попробуйте еще раз.\n";
        return -1;
    }
}

bool Graph::hasEdge(int v, int w) {
    if (!isValidVertex(v) || !isValidVertex(w)) {
        std::cout << "Неверные вершины. Попробуйте еще раз.\n";
        return false;
    }
    return std::find(adj[v].begin(), adj[v].end(), w) != adj[v].end();
}