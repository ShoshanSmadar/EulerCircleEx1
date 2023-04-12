#ifndef ALGORITHMS_EX1_GRAPH_H
#define ALGORITHMS_EX1_GRAPH_H

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Neighbor.h"


class Graph {

private:
    bool isDirected;
    std::vector<Vertex> vertices;
    int numOfEdges;

public:
    Graph(bool isDirected, int numOfVertices, int numOfEdges, std::vector<std::pair<int, int>> edges);
    ~Graph() = default;
    std::vector<Vertex>& getVertices();
    int getDegree(int ver) const;
    int getInDegree(int ver) const;
    int getOutDegree(int ver) const;
    void addDegree(int ver);
    void addInDegree(int ver);
    void addOutDegree(int ver);
    Graph createTransposeGraph();
    void visit(Vertex& v);
    bool areAllVerticesBlack();
    bool isConnected();
    bool isStronglyConnected();
    std::list<int> findCircuit(int vertex);
    bool isEulerian();
    void pasteToList(std::list<int>& l1, const std::list<int>& l2, std::list<int>::iterator& iteratorToPaste);
    std::list<int> findEulerCircle();
};


#endif //ALGORITHMS_EX1_GRAPH_H
