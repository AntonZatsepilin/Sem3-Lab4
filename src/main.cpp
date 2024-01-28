#include <chrono>
#include <iostream>
#include <queue>
#include <vector>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> color;

   public:
    Graph(int V) : V(V), adj(V), color(V, -1) {}

    bool isValidVertex(int v) { return v >= 0 && v < V; }

    void addEdge(int v, int w) {
        if (!isValidVertex(v) || !isValidVertex(w)) {
            std::cout << "Неверные вершины. Попробуйте еще раз.\n";
            return;
        }
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void removeEdge(int v, int w) {
        if (!isValidVertex(v) || !isValidVertex(w)) {
            std::cout << "Неверные вершины. Попробуйте еще раз.\n";
            return;
        }
        adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), w), adj[v].end());
        adj[w].erase(std::remove(adj[w].begin(), adj[w].end(), v), adj[w].end());
    }

    void colorGraph() {
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

    void printGraph() {
        for (int u = 0; u < V; u++) {
            std::cout << "Vertex " << u << " ---> Color " << color[u] << "\n";
            std::cout << "Adjacent vertices: ";
            for (auto v : adj[u]) {
                std::cout << v << " ";
            }
            std::cout << "\n";
        }
    }
    void shortestPath(int s, int d) {
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
                        std::cout << "Кратчайший путь от " << s << " до " << d << " составляет " << dist[d]
                                  << " шагов.\n";
                        return;
                    }
                }
            }
        }

        if (dist[d] == -1) {
            std::cout << "Путь от " << s << " до " << d << " не существует.\n";
        }
    }
};

int main() {
    int V;
    std::cout << "Введите количество вершин в графе: ";
    std::cin >> V;
    if (V <= 0) {
        std::cout << "Количество вершин должно быть положительным числом.\n";
        return 0;
    }
    Graph g(V);

    while (true) {
        std::cout << "\n1. Добавить ребро\n2. Удалить ребро\n3. Раскрасить граф\n4. Вывести граф\n5. Найти кратчайший "
                     "путь\n6. Выход\nВыберите действие: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int v, w;
            std::cout << "Введите вершины ребра (v w): ";
            std::cin >> v >> w;
            g.addEdge(v, w);
        } else if (choice == 2) {
            int v, w;
            std::cout << "Введите вершины ребра (v w): ";
            std::cin >> v >> w;
            g.removeEdge(v, w);
        } else if (choice == 3) {
            auto start = std::chrono::high_resolution_clock::now();
            g.colorGraph();
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            std::cout << "Время выполнения функции: " << duration.count() << " микросекунд" << std::endl;
        } else if (choice == 4) {
            g.printGraph();
        } else if (choice == 5) {
            int s, d;
            std::cout << "Введите начальную и конечную вершины (s d): ";
            std::cin >> s >> d;
            g.shortestPath(s, d);
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
        }
    }

    return 0;
}