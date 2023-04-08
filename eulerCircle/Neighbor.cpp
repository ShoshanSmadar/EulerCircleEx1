#include "Neighbor.h"

Neighbor::Neighbor(int vertexNumber) {
    this->vertexNumber = vertexNumber;
    this->isMarked = false;
    this->mutualVertex = nullptr;
}

int Neighbor::getVertexNumber() const {
    return vertexNumber;
}

bool Neighbor::isEdgeMarked() const {
    return this->isMarked;
}

void Neighbor::setIsMarked(bool isMarked) {
    this->isMarked = isMarked;
}
