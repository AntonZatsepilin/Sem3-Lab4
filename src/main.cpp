#include "graphs/graph.hpp"

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
        std::cout << "\n------------------- МЕНЮ -------------------\n";
        std::cout << "1. Добавить ребро\n";
        std::cout << "2. Удалить ребро\n";
        std::cout << "3. Раскрасить граф\n";
        std::cout << "4. Вывести граф\n";
        std::cout << "5. Найти кратчайший путь\n";
        std::cout << "0. Выход\n";
        std::cout << "--------------------------------------------\n";
        std::cout << "Выберите действие: ";
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
            g.colorGraph();
        } else if (choice == 4) {
            g.printGraph();
        } else if (choice == 5) {
            int s, d;
            std::cout << "Введите начальную и конечную вершины (s d): ";
            std::cin >> s >> d;
            g.shortestPath(s, d);
        } else if (choice == 0) {
            break;
        } else {
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
        }
    }

    return 0;
}