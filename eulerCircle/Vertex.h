#ifndef ALGORITHMS_EX1_VERTEX_H
#define ALGORITHMS_EX1_VERTEX_H

#include "Neighbor.h"
#include <list>
#include <iostream>


class Vertex {
private:
    int vertexNumber;
    char color;
    //Neighbor* pos; // Points to the next unmarked edge.
    std::list<Neighbor>::iterator pos; // Points to the next unmarked edge.
    std::list<Neighbor> neighbors;
    int inDegree;
    int outDegree;
    int totalDegree;

public:
    Vertex(int vertexNumber);
    Vertex() = default;
    ~Vertex() = default;
    int getVertexNumber() const;
    char getColor() const;
    void setColor(char color);
    //Neighbor* getPos() const; 
    //void setPos(Neighbor* pos);
    std::list<Neighbor>::iterator getPos() const;
    void setPos(const std::list<Neighbor>::iterator&);
    std::list<Neighbor>& getNeighbors();
    void setNeighbors(const std::list<Neighbor>& neighbors);
    int getInDegree() const;
    void setInDegree(int inDegree);
    int getOutDegree() const;
    void setOutDegree(int outDegree);
    int getTotalDegree() const;
    void setTotalDegree(int totalDegree);
    void addEdge(int vertex);
    void printNeighborList();
};


#endif //ALGORITHMS_EX1_VERTEX_H

