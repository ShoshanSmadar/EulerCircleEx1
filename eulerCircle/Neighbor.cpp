#include "Neighbor.h"

Neighbor::Neighbor(int vertexNumber) {
    this->vertexNumber = vertexNumber;
    this->isMarked = false;
    this->mutualEdge = nullptr;
}

// returns the destination of an edge (from the vertex that is calling the method).
int Neighbor::getDestination() const {
    return vertexNumber;
}

bool Neighbor::isEdgeMarked() const {
    return this->isMarked;
}

void Neighbor::setIsMarked(bool isMarked) {
    this->isMarked = isMarked;
}

void Neighbor::setMutualEdge(Neighbor* neighbor) {
    this->mutualEdge = neighbor;
}

Neighbor* Neighbor::getMutualEdge() {
    return this->mutualEdge;
}
