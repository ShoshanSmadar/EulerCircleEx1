#include "Vertex.h"
using namespace std;

Vertex::Vertex(int vertexNumber) {
    this->vertexNumber = vertexNumber;
    this->inDegree = 0;
    this->outDegree = 0;
    this->totalDegree = 0;
}

int Vertex::getVertexNumber() const {
    return this->vertexNumber;
}

char Vertex::getColor() const {
    return this->color;
}

void Vertex::setColor(char color) {
    this->color = color;
}

list<Neighbor>::iterator Vertex::getPos() const {
    return pos;
}

void Vertex::setPos(list<Neighbor>::iterator pos) {
    this->pos = pos;
}

list<Neighbor>& Vertex::getNeighbors() {
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

Neighbor& Vertex::addEdge(int vertex) {
    Neighbor neighbor(vertex);
    this->neighbors.push_back(neighbor);
    return neighbor;
}

void Vertex::printNeighborList() {
    for (list<Neighbor>::iterator it = neighbors.begin(); it != neighbors.end(); ++it){
        cout << it->getVertexNumber() << " ";
    }
}



