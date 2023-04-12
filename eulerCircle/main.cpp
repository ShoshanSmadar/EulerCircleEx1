#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;


vector<pair<int, int>> getEdges(int numOfEdges);
bool checkValidation(char isDirected, int numOfVertices, int numOfEdges, vector<pair<int, int>> edges);
void printList(list<int> myList);

int main() {
    char isDirected;
    int numOfVertices;
    int numOfEdges;
    vector<pair<int, int>> edges;
    cout << "Is the graph directed: y/n" << endl;
    cin >> isDirected >> numOfVertices >> numOfEdges;
    edges = getEdges(numOfEdges);
    bool isValid = checkValidation(isDirected, numOfVertices, numOfEdges, edges);
    if (isValid) {
        Graph graph(isDirected == 'y', numOfVertices, numOfEdges, edges);
        if (graph.isEulerian()) {
            cout << "The graph is aulerian" << endl;
            list<int> EulerCircle = graph.findEulerCircle();
            printList(EulerCircle);
        }
        else {
            cout << "The graph is not aulerian" << endl;
        }
    }
    else {
        cout << "invalid input!" << endl;
    }
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

bool checkValidation(char isDirected, int numOfVertices, int numOfEdges, vector<pair<int, int>> edges) {

    int maxNumOfEdgesDirected = numOfVertices*(numOfVertices-1);
    int maxNumOfEdgesUndirected  = (numOfVertices*(numOfVertices-1))/2;

    if (isDirected !=  'n' && isDirected != 'y')
        return false;
    if (numOfVertices <= 0 || numOfEdges < 0)
        return false;
    if (isDirected ==  'n' && numOfEdges > maxNumOfEdgesUndirected)
        return false;
    if (isDirected == 'y' && numOfEdges > maxNumOfEdgesDirected)
        return false;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].first <= 0 || edges[i].first > numOfVertices || edges[i].second <= 0 || edges[i].second > numOfVertices)
            return false;
    }
    return true;
}

void printList(list<int> myList) {
    cout << "(";

    for (int i = 0; i < myList.size(); i++) {
        cout << *(next(myList.begin(),i));
        if (i < myList.size() - 1)
            cout << ",";
    }
    cout << ")" << endl;
}
