#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> color;

   public:
    Graph(int V);

    bool isValidVertex(int v);

    void addEdge(int v, int w);

    void removeEdge(int v, int w);

    void colorGraph();

    void printGraph();

    void shortestPath(int s, int d);

    int getColor(int v);

    bool hasEdge(int v, int w);
};