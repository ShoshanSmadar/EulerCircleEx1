#include "Graph.h"
using namespace std;

Graph::Graph(bool isDirected, int numOfVertices, int numOfEdges, vector<pair<int, int>> edges) {
    this->isDirected = isDirected;
    this->isEulerian = false;

    for (int i = 0; i < numOfVertices; i++) {
        this->vertices.push_back(Vertex(i + 1));
    }

    for (int i = 0; i < numOfEdges; i++) {
        this->vertices[edges[i].first-1].addEdge(edges[i].second);
        if (isDirected) {
            this->addInDegree(edges[i].first-1);
            this->addOutDegree(edges[i].second-1);
        }
        else
        {
            this->vertices[edges[i].second-1].addEdge(edges[i].first);
            this->addDegree(edges[i].first-1);
            this->addDegree(edges[i].second-1);
        }
    }
}

Vertex Graph::getVertic(int num)
{
    return vertices[num];
}

Neighbor* Graph::getNextNeighbor(int numIn)
{
    return vertices[numIn].getPos();
}

int Graph::getDegree(int ver) const
{
    return vertices[ver].getTotalDegree();
}

int Graph::getInDegree(int ver) const
{
    return vertices[ver].getInDegree();
}

int Graph::getOutDegree(int ver) const
{
    return vertices[ver].getOutDegree();
}

//the method reduces the degree by one
void Graph::reduceDegree(int ver)
{
    vertices[ver].setTotalDegree(getDegree(ver)-1);
}

//the method reduces the degree by one
void Graph::reduceInDegree(int ver)
{
    vertices[ver].setOutDegree(getInDegree(ver)-1);
}

//the method reduces the degree by one
void Graph::reduceOutDegree(int ver)
{
    vertices[ver].setOutDegree(getOutDegree(ver)-1);
}

//the method adds 1 to the degree
void Graph::addDegree(int ver)
{
    vertices[ver].setTotalDegree(getDegree(ver) + 1);
}

//the method adds 1 to the degree
void Graph::addInDegree(int ver)
{
    vertices[ver].setOutDegree(getInDegree(ver) + 1);
}

//the method adds 1 to the degree
void Graph::addOutDegree(int ver)
{
    vertices[ver].setOutDegree(getOutDegree(ver) + 1);
}

bool Graph::isEuler()
{
    if (this->isDirected)
    {
       // if (!isConectedStrong())
       //     return false;
        for (int i = 0; i < (int)vertices.size(); i++)
        {
            if (vertices[i].getInDegree() != vertices[i].getOutDegree())
                return false;
        }
        return true;
    }
    else//case not directed
    {
       // if (!isConected())
        //    return false;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].getTotalDegree() % 2 != 0)
                return false;
        }
        return true;
    }
}

/*void Graph::printGraph()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout >> vertices[i].
    }

}*/

