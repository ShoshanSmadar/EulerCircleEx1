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
    bool isEulerian;

public:
    Graph(bool isDirected, int numOfVertices, int numOfEdges, std::vector<std::pair<int, int>> edges);
    ~Graph() = default;


    Vertex getVertex(int num);
    Neighbor* getNextNeighbor(int numIn);
    int getDegree(int ver) const;
    int getInDegree(int ver) const;
    int getOutDegree(int ver) const;
    void reduceDegree(int ver);
    void reduceInDegree(int ver);
    void reduceOutDegree(int ver);
    void addDegree(int ver);
    void addInDegree(int ver);
    void addOutDegree(int ver);


    //bool isConected();
    //bool isConectedStrong();

    bool isEuler();

    //void FindEuler();
    void printGraph();
};


#endif //ALGORITHMS_EX1_GRAPH_H
