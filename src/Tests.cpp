#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graphs/graph.hpp"

TEST_CASE("Testing Graph class") {
    Graph g(5);

    CHECK(g.isValidVertex(0) == true);
    CHECK(g.isValidVertex(5) == false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.colorGraph();

    CHECK(g.getColor(0) == 0);
    CHECK(g.getColor(1) == 1);
    CHECK(g.getColor(2) == 2);
    CHECK(g.getColor(3) == 0);
    CHECK(g.getColor(4) == 0);

    g.removeEdge(1, 2);

    CHECK(g.hasEdge(1, 2) == false);
    CHECK(g.hasEdge(0, 1) == true);

    g.shortestPath(0, 4);
    g.shortestPath(0, 5);

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    g2.colorGraph();

    CHECK(g2.getColor(0) == 0);
    CHECK(g2.getColor(1) == 1);
    CHECK(g2.getColor(2) == 0);

    g2.removeEdge(0, 1);

    CHECK(g2.hasEdge(0, 1) == false);
    CHECK(g2.hasEdge(1, 2) == true);

    g2.shortestPath(0, 2);
}

TEST_CASE("Testing Graph with negative vertices") {
    Graph g(5);

    CHECK(g.isValidVertex(-1) == false);
    CHECK(g.isValidVertex(-5) == false);

    g.addEdge(-1, 1);
    g.addEdge(0, -2);
    g.addEdge(-1, -2);

    CHECK(g.hasEdge(-1, 1) == false);
    CHECK(g.hasEdge(0, -2) == false);
    CHECK(g.hasEdge(-1, -2) == false);
}

TEST_CASE("Testing Graph with large number of vertices") {
    Graph g(1000);

    CHECK(g.isValidVertex(999) == true);
    CHECK(g.isValidVertex(1000) == false);

    g.addEdge(0, 999);
    g.addEdge(500, 500);

    g.colorGraph();

    CHECK(g.getColor(0) == 0);
    CHECK(g.getColor(999) == 1);
    CHECK(g.getColor(500) == 0);

    g.removeEdge(0, 999);

    CHECK(g.hasEdge(0, 999) == false);
    CHECK(g.hasEdge(500, 500) == true);
}

TEST_CASE("Testing Graph with no edges") {
    Graph g(5);

    g.colorGraph();

    CHECK(g.getColor(0) == 0);
    CHECK(g.getColor(1) == 0);
    CHECK(g.getColor(2) == 0);
    CHECK(g.getColor(3) == 0);
    CHECK(g.getColor(4) == 0);

    CHECK(g.hasEdge(0, 1) == false);
    CHECK(g.hasEdge(1, 2) == false);
    CHECK(g.hasEdge(2, 3) == false);
    CHECK(g.hasEdge(3, 4) == false);
}