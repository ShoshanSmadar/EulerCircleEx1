#include "Graph.h"
using namespace std;

Graph::Graph(bool isDirected, int numOfVertices, int numOfEdges, vector<pair<int, int>> edges) {
    this->isDirected = isDirected;
    this->isEulerian = false;
    this->numOfEdges = numOfEdges;

    for (int i = 0; i < numOfVertices; i++) {
        this->vertices.push_back(Vertex(i + 1));
        vertices[i].setColor('w'); // initialize all vertices with white color.
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

    // set pos to be the first neighbor in the list of every neighbor.
    for (int i = 0; i < numOfVertices; i++) {
        list<Neighbor>::iterator it = vertices[i].getNeighbors().begin();
        this->vertices[i].setPos(&*it);
    }
}

Vertex Graph::getVertex(int num)
{
    return vertices[num];
}

vector<Vertex> Graph::getVertices() {
    return this->vertices;
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
    else //case not directed
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

void Graph::printGraph()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << "The neighbors of vertex " << vertices[i].getVertexNumber() << " are: ";
        vertices[i].printNeighborList();
        cout << endl;
        cout << "The color of vertex " << vertices[i].getVertexNumber() << " is: " << vertices[i].getColor() << endl;
    }
}

// creates transpose graph to a directed graph only (irrelevant if graph is not directed!).
Graph Graph::createTransposeGraph() {
    vector<pair<int, int>> edges;
    pair<int, int> edge;
    for (int i = 0; i < vertices.size(); i++) {
        edge.second = this->vertices[i].getVertexNumber();
        for (list<Neighbor>::iterator it = vertices[i].getNeighbors().begin(); it != vertices[i].getNeighbors().end(); ++it){
            edge.first = it->getVertexNumber();
            edges.push_back(edge);
        }
    }
    return Graph(this->isDirected, this->vertices.size(), this->numOfEdges, edges);
}

void Graph::visit(Vertex& v) {
    v.setColor('g'); // color v in grey.
    for (list<Neighbor>::iterator it = v.getNeighbors().begin(); it != v.getNeighbors().end(); ++it){
        int vertexNum = it->getVertexNumber();
        if (vertices[vertexNum-1].getColor() == 'w'){
            it->setIsMarked(true);
            visit(vertices[vertexNum-1]);
        }
    }
    v.setColor('b');
}

bool Graph::areAllVerticesBlack() {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].getColor() !=  'b')
            return false;
    }
    return true;
}

// checks if a not directed graph is connected.
bool Graph::isConnected() {
    this->visit(vertices[0]);

    if (this->areAllVerticesBlack())
        return true;

    return false;
}

bool Graph::isStronglyConnected() {
    this->visit(vertices[0]);

    if (this->areAllVerticesBlack()) {
        Graph gt = createTransposeGraph();
        gt.visit(gt.vertices[0]);
        if (gt.areAllVerticesBlack())
            return true;
    }
  return false;
}
