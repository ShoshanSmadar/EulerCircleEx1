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
    if (directed == 'y' && directed == 'n' && numOfVer > 0 && numOfEdges >0)
    {
        cout << "wrong input!";
    }
    else 
    {
        edges = getEdges(numOfEdges);
        Graph graph(directed == 'y', numOfVer, numOfEdges, edges);
        if (graph.isEuler())
        {
            graph.initEdgeMark();
            graph.FindEuler();
        }
    }
    
//    graph.printGraph();
//    cout << endl;
//    graph.visit(graph.getVertices()[0]);
//    graph.printGraph();
//    cout << graph.isStronglyConnected() << endl;

    return 0;
}


vector<pair<int, int>> getEdges(int numOfEdges) {

    vector<pair<int, int>> edges;
    pair<int, int> edge;
    for (int i = 0; i < numOfEdges; i++)
    {
        cin >> edge.first >> edge.second;
        edges.push_back(edge);
        if (edge.first < 1 || edge.first > numOfEdges | edge.second < 1 || edge.second > numOfEdges)
        {
            cout << "wrong input";
        }
    }
    return edges;
}
