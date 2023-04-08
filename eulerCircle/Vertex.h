#ifndef ALGORITHMS_EX1_VERTEX_H
#define ALGORITHMS_EX1_VERTEX_H

#include "Neighbor.h"
#include <list>


class Vertex {

private:
    int vertexNumber;
    Neighbor* pos; // Points to the next unmarked edge.
    std::list<Neighbor> neighbors;
    int inDegree;
    int outDegree;
    int totalDegree;

public:
    Vertex(int vertexNumber);
    ~Vertex() = default;
    Neighbor* getPos() const;
    void setPos(Neighbor* pos);
    const std::list<Neighbor>& getNeighbors() const;
    void setNeighbors(const std::list<Neighbor>& neighbors);
    int getInDegree() const;
    void setInDegree(int inDegree);
    int getOutDegree() const;
    void setOutDegree(int outDegree);
    int getTotalDegree() const;
    void setTotalDegree(int totalDegree);
    void addEdge(int vertex);
};


#endif //ALGORITHMS_EX1_VERTEX_H

