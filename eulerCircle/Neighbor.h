
#ifndef ALGORITHMS_EX1_NEIGHBOR_H
#define ALGORITHMS_EX1_NEIGHBOR_H


class Neighbor {

private:
    int vertexNumber;
    bool isMarked;
    Neighbor* mutualVertex; // Pointer from edge (x,y) to (y,x) if the graph is not directed.
                            // Points to nullptr if the graph is directed.

public:
    Neighbor(int vertexNumber);
    ~Neighbor() = default;
    int getVertexNumber() const;
    bool isEdgeMarked() const;
    void setIsMarked(bool isMarked);
    Neighbor* getmutualVertex();
    void setMutualVertex(Neighbor* N);
};


#endif //ALGORITHMS_EX1_NEIGHBOR_H
