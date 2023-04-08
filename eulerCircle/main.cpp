#include <iostream>
#include <vector>
//#include <pair>
#include "Graph.h"
using namespace std;


vector<pair<int, int>> getEdges(int nofEdges);

int main() {
    char directed;
    int nofVer;
    int nofEdges;
    std::vector<std::pair<int, int>> edges;
    cout << "Is the graph directed: y/n";
    cin >> directed >> nofVer >> nofEdges;
    edges = getEdges(nofEdges);
    Graph graph(directed == 'y', nofVer, nofEdges, edges);

    return 0;
}


std::vector<std::pair<int, int>> getEdges(int nofEdges)
{
    std::vector<std::pair<int, int>> edges;
    pair<int, int> edge;
    for (int i = 0; i < nofEdges; i++)
    {
        cin >> edge.first >> edge.second;
        edges.push_back(edge);
    }
    return edges;
}
