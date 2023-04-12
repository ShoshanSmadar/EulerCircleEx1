#ifndef ALGORITHMS_EX1_VERTEX_H
#define ALGORITHMS_EX1_VERTEX_H

#include "Neighbor.h"
#include <list>
#include <iostream>


class Vertex {

private:
    int vertexNumber;
    char color;
    std::list<Neighbor>::iterator pos; // Points to the next unmarked edge.
    std::list<Neighbor> neighbors;
    int inDegree; // in use when graph is directed.
    int outDegree; // in use when graph is directed.
    int totalDegree; // in use when graph is undirected.

public:
    Vertex(int vertexNumber);
    ~Vertex() = default;
    int getVertexNumber() const;
    char getColor() const;
    void setColor(char color);
    std::list<Neighbor>::iterator getPos() const;
    void setPos(std::list<Neighbor>::iterator pos);
    void updatePos();
    std::list<Neighbor>& getNeighbors();
    int getInDegree() const;
    void setInDegree(int inDegree);
    int getOutDegree() const;
    void setOutDegree(int outDegree);
    int getTotalDegree() const;
    void setTotalDegree(int totalDegree);
    Neighbor& addEdge(int vertex);
};


#endif //ALGORITHMS_EX1_VERTEX_H

