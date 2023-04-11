
#ifndef ALGORITHMS_EX1_NEIGHBOR_H
#define ALGORITHMS_EX1_NEIGHBOR_H


class Neighbor {

private:
    int vertexNumber;
    bool isMarked;
    Neighbor* mutualEdge; // Pointer from edge (x,y) to (y,x) if the graph is not directed.
                            // Points to nullptr if the graph is directed.

public:
    Neighbor(int vertexNumber);
    ~Neighbor() = default;
    int getDestination() const;
    bool isEdgeMarked() const;
    void setIsMarked(bool isMarked);
    void setMutualEdge(Neighbor* neighbor);
    Neighbor* getMutualEdge();
};



#endif //ALGORITHMS_EX1_NEIGHBOR_H
