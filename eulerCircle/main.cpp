#include <iostream>
#include <vector>
//#include <pair>
#include "Graph.h"
using namespace std;


vector<pair<int, int>> getEdges(int numOfEdges);

int main() {
    char directed;
    int numOfVer;
    int numOfEdges;
    std::vector<std::pair<int, int>> edges;
    cout << "Is the graph directed: y/n" << endl;
    cin >> directed >> numOfVer >> numOfEdges;
    edges = getEdges(numOfEdges);
    Graph graph(directed == 'y', numOfVer, numOfEdges, edges);
    graph.printGraph();
    Graph gt = graph.createTransposeGraph();
    cout << endl;
    gt.printGraph();

    return 0;
}


vector<pair<int, int>> getEdges(int numOfEdges) {

    vector<pair<int, int>> edges;
    pair<int, int> edge;
    for (int i = 0; i < numOfEdges; i++)
    {
        cin >> edge.first >> edge.second;
        edges.push_back(edge);
    }
    return edges;
}
