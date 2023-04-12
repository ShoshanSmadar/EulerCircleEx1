#include <iostream>
#include <vector>
//#include <pair>
#include "Graph.h"
using namespace std;


vector<pair<int, int>> getEdges(int numOfEdges);

Graph BuildDefaultUnDirectedGraph() {
    bool is_directed = false;
    int num_vertices = 6;
    int numEdges  = 10;
    std::vector<std::pair<int, int>> edges  = {{1,2},
                                               {1,3},
                                               {2,3},
                                               {2,4},
                                               {2,5},
                                               {3,4},
                                               {3,5},
                                               {4,5},
                                               {4,6},
                                               {5,6}};
    return Graph(is_directed, num_vertices, numEdges, edges);
}

std::string printList(std::list<int> myList) {
    string result;
    for (int curr : myList) {
        result += ", " + std::to_string(curr);
    }
    return result;
}

bool compareLists(std::list<int> l1, std::list<int> l2) {
    if (l1.size() != l2.size()) {
        return false;
    }
    for (int i =  0; i < l1.size(); i++) {
        if (*(next(l1.begin(),i)) != *(next(l1.begin(),i)))
            return false;
    }
    return true;
}

void test_IsConnected_Directed() {
    Graph graph(true, 6, 10, {
        {1,2},
        {2,3},
        {2,4},
        {3,1},
        {3, 4},
        {4, 5},
        {4, 6},
        {5, 2},
        {5,3},
        {6,5}});
    bool actual_is_connected = graph.isConnected();
    bool expected_is_connected = true;

    cout << "test_IsConnected_Directed: " << (actual_is_connected == expected_is_connected) << endl;
}
void test_IsConnected_Directed_NotConnected()  {
    Graph graph(true, 4, 4, {{1,2},
                              {2,4},
                              {3,4},
                              {4,1}});
    bool actual_is_connected = graph.isConnected();
    bool expected_is_connected = false;

    cout << "test_IsConnected_Directed_NotConnected: " << (actual_is_connected == expected_is_connected) << endl;
}

void test_FindCircuit_Directed() {
    Graph graph(true, 6, 10, {
            {1,2},
            {2,3},
            {2,4},
            {3,1},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    list<int> expected_circuit = {1, 2, 3, 1};
    auto actual_circuit = graph.findCircuit(1);
    if (compareLists(expected_circuit, actual_circuit))  {
        cout << "test_FindCircuit_Directed: 1" << endl;
    } else {
        cout << "test_FindCircuit_Directed: FAILED expected: " << printList(expected_circuit)  << " actual: " << printList(actual_circuit) << endl;
    }
}

void test_FindCircuit_Directed_2() {
    Graph graph(true, 6, 10, {
            {1,2},
            {2,3},
            {2,4},
            {3,1},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    list<int> expected_circuit = {6, 5, 2, 3, 1, 2, 4, 5, 3, 4, 6};
    auto actual_circuit = graph.findCircuit(6);
    if (compareLists(expected_circuit, actual_circuit))  {
        cout << "test_FindCircuit_Directed_2: 1" << endl;
    } else {
        cout << "test_FindCircuit_Directed_2: FAILED expected: " << printList(expected_circuit)  << " actual: " << printList(actual_circuit) << endl;
    }
}

void test_IsEulerian_directed() {
    Graph graph(true, 6, 10, {
            {1,2},
            {2,3},
            {2,4},
            {3,1},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    bool expected_isEulerian= true;
    bool actual_isEulerian = graph.isEulerian();

    cout << "test_IsEulerian_directed: " << (expected_isEulerian == actual_isEulerian) << endl;
}

void test_IsEulerian_notEulerian() {
    Graph graph(true, 6, 9, {
            {1,2},
            {2,3},
            {2,4},
            {3,1},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    bool expected_isEulerian= false;
    bool actual_isEulerian = graph.isEulerian();

    cout << "test_IsEulerian_notEulerian: " << (expected_isEulerian == actual_isEulerian) << endl;
}

void test_IsEulerian_notConnected() {
    Graph graph(true, 6, 8, {
            {2,3},
            {2,4},
            {3,1},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    bool expected_isEulerian= false;
    bool actual_isEulerian = graph.isEulerian();

    cout << "test_IsEulerian_notConnected: " << (expected_isEulerian == actual_isEulerian) << endl;
}

void test_EulerCircle_Directed(){
    Graph graph(true, 4, 4, {
            {1,2},
            {2,3},
            {3,4},
            {4,1}});

    list<int> expected_Euler_circle = {1,2,3,4,1};
    list<int> actual_circuit = graph.findEulerCircle();
    if (compareLists(expected_Euler_circle, actual_circuit))  {
        cout << "test_EulerCircle_Directed: 1" << endl;
    } else {
        cout << "test_EulerCircle_Directed: FAILED expected: " << printList(expected_Euler_circle)  << " actual: " << printList(actual_circuit) << endl;
    }
}

void test_EulerCircle_Directed_2(){
    Graph graph(true, 5, 7, {
            {1,2},
            {2,3},
            {3,4},
            {3,5},
            {4,1},
            {4,3},
            {5,4},});

    list<int> expected_Euler_circle = {1,2,3,5,4,3,4,1};
    list<int> actual_circuit = graph.findEulerCircle();
    if (compareLists(expected_Euler_circle, actual_circuit))  {
        cout << "test_EulerCircle_Directed_2: 1" << endl;
    } else {
        cout << "test_EulerCircle_Directed_2: FAILED expected: " << printList(expected_Euler_circle)  << " actual: " << printList(actual_circuit) << endl;
    }
}

void test_IsConnected_Undirected() {
    Graph graph = BuildDefaultUnDirectedGraph();
    bool actual_is_connected = graph.isConnected();
    bool expected_is_connected = true;

    cout << "test_IsConnected_Undirected: " << (actual_is_connected == expected_is_connected) << endl;
}

void test_IsConnected_Undirected_NotConnceted() {
    std::vector<std::pair<int, int>> edges  = {{1,2},
                                               {1,3},
                                               {2,3},
                                               {2,4},
                                               {2,5},
                                               {3,4},
                                               {3,5},
                                               {4,5}};
    Graph graph(true, 6, 8, edges);
    bool actual_is_connected = graph.isConnected();
    bool expected_is_connected = false;

    cout << "test_IsConnected_Undirected_NotConnceted: " << (actual_is_connected == expected_is_connected) << endl;
}

void test_FindCircuit_Undirected() {
    Graph graph = BuildDefaultUnDirectedGraph();
    auto actual_circuit = graph.findCircuit(1);
    list<int> expected_circuit = {1, 2, 3, 1};

    if (compareLists(expected_circuit, actual_circuit))  {
        cout << "test_FindCircuit_Undirected: 1" << endl;
    } else {
        cout << "test_FindCircuit_Undirected: FAILED expected: " << printList(expected_circuit)  << " actual: " << printList(actual_circuit) << endl;
    }
}

void test_FindCircuit_Undirected_2() {
    Graph graph = BuildDefaultUnDirectedGraph();
    auto actual_circuit = graph.findCircuit(6);
    list<int> expected_circuit = {6,4,2,1,3,2,5,3,4,5,6};

    if (compareLists(expected_circuit, actual_circuit))  {
        cout << "test_FindCircuit_Undirected_2: 1" << endl;
    } else {
        cout << "test_FindCircuit_Undirected_2: FAILED expected: " << printList(expected_circuit)  << " actual: " << printList(actual_circuit) << endl;
    }
}

void test_IsEulerian_undirected() {
    Graph graph(false, 6, 10, {
            {1,2},
            {2,3},
            {2,4},
            {3,1},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    bool expected_isEulerian= true;
    bool actual_isEulerian = graph.isEulerian();

    cout << "test_IsEulerian_undirected: " << (expected_isEulerian == actual_isEulerian) << endl;
}

void test_IsEulerian_undirected_notEulerian() {
    Graph graph(false, 6, 9, {
            {1,2},
            {2,4},
            {3,1},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    bool expected_isEulerian= false;
    bool actual_isEulerian = graph.isEulerian();

    cout << "test_IsEulerian_undirected_notEulerian: " << (expected_isEulerian == actual_isEulerian) << endl;
}

void test_IsEulerian_undirected_notConnected() {
    Graph graph(false, 6, 8, {
            {2,3},
            {2,4},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});
    bool expected_isEulerian= false;
    bool actual_isEulerian = graph.isEulerian();

    cout << "test_IsEulerian_undirected_notConnected: " << (expected_isEulerian == actual_isEulerian) << endl;
}

void test_EulerCircle_undirected(){
    Graph graph(false, 6, 10, {
            {1,2},
            {2,3},
            {2,4},
            {3,1},
            {3, 4},
            {4, 5},
            {4, 6},
            {5, 2},
            {5,3},
            {6,5}});

    list<int> expected_Euler_circle = {1,2,4,5,6,4,3,5,2,3,1};
    list<int> actual_circuit = graph.findEulerCircle();
    if (compareLists(expected_Euler_circle, actual_circuit))  {
        cout << "test_EulerCircle_undirected: 1" << endl;
    } else {
        cout << "test_EulerCircle_undirected: FAILED expected: " << printList(expected_Euler_circle)  << " actual: " << printList(actual_circuit) << endl;
    }
}

int main() {
    // Directed graph:
    cout << "Directed: " << endl;
    test_IsConnected_Directed();
    test_IsConnected_Directed_NotConnected();

    test_FindCircuit_Directed();
    test_FindCircuit_Directed_2();

    test_IsEulerian_directed();
    test_IsEulerian_notEulerian();
    test_IsEulerian_notConnected();

    test_EulerCircle_Directed();
    test_EulerCircle_Directed_2();

    // Undirected graph:
    cout << endl<< endl  << "Undirected:" << endl;
    test_IsConnected_Undirected();
    test_IsConnected_Undirected_NotConnceted();

    test_FindCircuit_Undirected();
    test_FindCircuit_Undirected_2();

    test_IsEulerian_undirected();
    test_IsEulerian_undirected_notEulerian();

    test_EulerCircle_undirected();

    return 0;
    char directed;
    int numOfVer;
    int numOfEdges;
    std::vector<std::pair<int, int>> edges;
    cout << "Is the graph directed: y/n" << endl;
    cin >> directed >> numOfVer >> numOfEdges;
    edges = getEdges(numOfEdges);
    Graph graph(directed == 'y', numOfVer, numOfEdges, edges);
    graph.printGraph();
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
    }
    return edges;
}
