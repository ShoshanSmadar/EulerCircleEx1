#include "Vertex.h"
using namespace std;

Vertex::Vertex(int vertexNumber) {
    this->vertexNumber = vertexNumber;
    this->pos = nullptr;
    this->inDegree = 0;
    this->outDegree = 0;
    this->totalDegree = 0;
}

Neighbor* Vertex::getPos() const {
    return pos;
}

void Vertex::setPos(Neighbor* pos) {
    this->pos = pos;
}

const list<Neighbor>& Vertex::getNeighbors() const {
    return neighbors;
}

void Vertex::setNeighbors(const list<Neighbor>& neighbors) {
    this->neighbors = neighbors;
}

int Vertex::getInDegree() const {
    return inDegree;
}

void Vertex::setInDegree(int inDegree) {
    this->inDegree = inDegree;
}

int Vertex::getOutDegree() const {
    return outDegree;
}

void Vertex::setOutDegree(int outDegree) {
    this->outDegree = outDegree;
}

int Vertex::getTotalDegree() const {
    return totalDegree;
}

void Vertex::setTotalDegree(int totalDegree) {
    this->totalDegree = totalDegree;
}

void Vertex::addEdge(int vertex) {
    this->neighbors.push_back(Neighbor(vertex));
}



