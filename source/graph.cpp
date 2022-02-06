#include <vector>
#include <iostream>

using namespace std;

// TO DO:
//  - Implement node as template to contain an arbitrary data member type, such as: template <class Data> class Node {...}

class Node {
    public:
    Node(size_t id): _id(id) {
        cout<<"The node "<<_id<<" was created."<<endl;
        };
    bool addNeighbor(Node* nodePtr, double w){
        _neigbors.push_back(nodePtr);
        _weights.push_back(w);
        cout<<"A neighbor added to "<<_id<<" node."<<endl;
    }

    private:
    vector<Node*> _neigbors;
    vector<double> _weights;
    size_t _id;
};

class Graph {
    public:
    Graph(size_t id): _id(id), _size(0) {
        cout<<"An empty Graph was created"<<endl;
    }
    Graph(vector<Node*> v);
    bool addNode(Node* newNode, vector<Node*> neigbors, vector<double> weights);
    bool deleteNode(Node* node);


    private:
    vector<Node*> _nodes;
    size_t _size;
    size_t _id;
};

int main() {
    cout<<"main started"<<endl;
    Node n1(1);
    Node n2(2);
    Graph g1(1);
    cout<<"main ended"<<endl;

    return 0;
}