#include <iostream>

#include "graph.hpp"
#include "adjacency_matrix.hpp"

using namespace std;

int main()
{
    Graph<AdjacencyMatrix> graph;

    cout << graph.AddVertex(nullptr, 0) << " added\n";
    
    std::cout << "Hello Graph World\n";
    return 0;
}