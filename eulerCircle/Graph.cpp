#include "Graph.h"
using namespace std;

Graph::Graph(bool isDirected, int numOfVertices, int numOfEdges, vector<pair<int, int>> edges) {
    this->isDirected = isDirected;
    this->numOfEdges = numOfEdges;

    for (int i = 0; i < numOfVertices; i++) {
        this->vertices.push_back(Vertex(i + 1));
        vertices[i].setColor('w'); // initialize all vertices with white color.
    }

    // create edges accordingly.
    for (int i = 0; i < numOfEdges; i++) {
        Neighbor& neighbor1 =  this->vertices[edges[i].first-1].addEdge(edges[i].second);

        if (isDirected) {
            this->addInDegree(edges[i].first-1);
            this->addOutDegree(edges[i].second-1);
        }
        else
        {
            Neighbor& neighbor2 = this->vertices[edges[i].second-1].addEdge(edges[i].first);
            this->addDegree(edges[i].first-1);
            this->addDegree(edges[i].second-1);

            // set mutual pointers to edges if the graph is not directed.
            neighbor1.setMutualEdge(&neighbor2);
            neighbor2.setMutualEdge(&neighbor1);

        }
    }

    // set pos to be the first neighbor in the list of every neighbor.
    for (int i = 0; i < numOfVertices; i++) {
        list<Neighbor>::iterator it = vertices[i].getNeighbors().begin();
        this->vertices[i].setPos(it);
    }
}

vector<Vertex>& Graph::getVertices() {
    return this->vertices;
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

// adds 1 to the degree.
void Graph::addDegree(int ver)
{
    vertices[ver].setTotalDegree(getDegree(ver) + 1);
}

// adds 1 to the in degree.
void Graph::addInDegree(int ver)
{
    vertices[ver].setInDegree(getInDegree(ver) + 1);
}

// adds 1 to the out degree.
void Graph::addOutDegree(int ver)
{
    vertices[ver].setOutDegree(getOutDegree(ver) + 1);
}

// checks if the graph is Eulerian.
bool Graph::isEulerian()
{
    if (this->isDirected)
    {
        if (!isStronglyConnected())
            return false;  // if a directed graph is not strongly connected, is  not Eulerian.
        for (int i = 0; i < (int)vertices.size(); i++)
        {
            if (vertices[i].getInDegree() != vertices[i].getOutDegree()) // if a directed graph is strongly connected,
                                                                         // check if in degree equals out degree.
                return false;
        }
        return true;
    }
    else //case not directed
    {
        if (!isConnected())
            return false;  // if an undirected graph is not connected, is  not Eulerian.
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].getTotalDegree() % 2 != 0)  // if an Undirected graph is connected, check if all degrees are even.
                return false;
        }
        return true;
    }
}


//void Graph::printGraph()
//{
//    for (int i = 0; i < vertices.size(); i++)
//    {
//        cout << "The neighbors of vertex " << vertices[i].getVertexNumber() << " are: ";
//        vertices[i].printNeighborList();
//        cout << endl;
//        cout << "The color of vertex " << vertices[i].getVertexNumber() << " is: " << vertices[i].getColor() << endl;
//    }
//}

// creates transpose graph to a directed graph only (irrelevant if graph is not directed!).
Graph Graph::createTransposeGraph() {
    vector<pair<int, int>> edges;
    pair<int, int> edge;
    for (int i = 0; i < vertices.size(); i++) {
        edge.second = this->vertices[i].getVertexNumber();
        for (list<Neighbor>::iterator it = vertices[i].getNeighbors().begin(); it != vertices[i].getNeighbors().end(); ++it){
            edge.first = it->getDestination();
            edges.push_back(edge);
        }
    }
    return Graph(this->isDirected, this->vertices.size(), this->numOfEdges, edges);
}

void Graph::visit(Vertex& v) {
    v.setColor('g'); // color v in grey.
    for (list<Neighbor>::iterator it = v.getNeighbors().begin(); it != v.getNeighbors().end(); ++it){
        int vertexNum = it->getDestination();
        if (vertices[vertexNum-1].getColor() == 'w'){
            visit(vertices[vertexNum-1]);
        }
    }
    v.setColor('b');
}

// checks of all vertices of the graph are black.
bool Graph::areAllVerticesBlack() {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].getColor() !=  'b')
            return false;
    }
    return true;
}

// checks if an undirected graph is connected.
bool Graph::isConnected() {
    this->visit(vertices[0]);

    if (this->areAllVerticesBlack())
        return true;

    return false;
}

// checks if a directed graph is strongly connected.
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

// finds a circle in the graph from 'vertex'.
list<int> Graph::findCircuit(int vertex) {
    list<int> result;
    result.push_back(vertex);

    while (this->getVertices()[vertex-1].getPos() != this->getVertices()[vertex-1].getNeighbors().end()) {
        list<Neighbor>::iterator currentEdge = this->getVertices()[vertex - 1].getPos();

        currentEdge->setIsMarked(true);
        this->getVertices()[vertex-1].updatePos();

        if (currentEdge->getMutualEdge()) {
            currentEdge->getMutualEdge()->setIsMarked(true);

            vertices[currentEdge->getDestination() - 1].updatePos();
        }
        vertex = currentEdge->getDestination();
        result.push_back(vertex);
    }
    return result;
}

// pastes 'l2' to 'l1' from 'iteratorToPaste'.
void Graph::pasteToList(std::list<int> l1, std::list<int> l2, std::list<int>::iterator& iteratorToPaste) {

    for (int i = 0; i < l2.size()-1; i++) {
        l1.insert(next(iteratorToPaste,i+1), *next(l2.begin(), i+1));
    }
}

// gets an Eulerian graph and returns an Euler circle.
std::list<int> Graph::findEulerCircle() {
    std::list<int> result = findCircuit(1);
    int totalExtraListSize = 0;

    for (int i = 0; i < result.size(); i++) {
        int vertexNumber = *next(result.begin(), i);
        if (this->vertices[vertexNumber-1].getPos() != this->vertices[vertexNumber-1].getNeighbors().end()) {
            std::list<int> lst = findCircuit(vertexNumber);
            std::list<int>::iterator iteratorToPaste = next(result.begin(), totalExtraListSize + 1);
            pasteToList(result, lst, iteratorToPaste);
            totalExtraListSize += lst.size();
        }
    }
    return result;
}
