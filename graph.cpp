#include <vector>
#include <iostream>

// TO DO:
//  - Implement node as template to contain an arbitrary data member type: template <class Data> class Node {...}

class Graph {
    public:
    Graph() = default;
    Graph(vector<Node*> v);
    bool addNode(Node* newNode, vector<Node*> neigbors, vector<double> weights);
    bool deleteNode(Node* node);


    private:
    vector<Node*> _nodes;
    size_t _size;
}


class Node {
    public:
    Node() = default;

    private:
    vector<Node*> _neigbors;
    vector<double> _weights;
    size_t _id;
}