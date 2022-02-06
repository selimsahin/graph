#pragma once

#include <vector>
#include <iostream>

#include "vertex.hpp"
#include "edges.hpp"

template <class EdgeImp>
class Graph {
    public:
        uint32_t AddVertex(void *data, size_t size);
        void AddEdge(const Vertex& v1, const Vertex& v2, uint32_t weight);

        void* DeleteVertex(uint32_t id);
        bool DeleteEdge(const Vertex& v1, const Vertex& v2);

        void PrintGraph();

        bool Hello(int i, double d);

    private:
        EdgeImp edges;
        std::vector<Vertex> vertices;
};

template <class EdgeImp>
void Graph<EdgeImp>::PrintGraph()
{
    std::cout << "Vertex List :\n";

    for (auto a : vertices)
    {
        std::cout << a.GetId() << " - ";
    }

    std::cout << "\n**************************\n";
}

template <class EdgeImp>
uint32_t Graph<EdgeImp>::AddVertex(void *data, size_t size)
{
    vertices.push_back(Vertex::CreateVertex(data, size));
    return vertices.back().GetId();
}

template <class EdgeImp>
void Graph<EdgeImp>::AddEdge(const Vertex& v1, const Vertex& v2, uint32_t weight)
{
    edges.Add(v1, v2, weight);
}

template <class EdgeImp>
void* Graph<EdgeImp>::DeleteVertex(uint32_t id)
{
    void *data = nullptr;

    for (auto iter = vertices.begin(); iter != vertices.end(); ++iter)
    {
        if (iter->GetId() == id)
        {
            data = iter->GetData();
            vertices.erase( iter );
            break;
        }
    }

    return data;
}

template <class EdgeImp>
bool Graph<EdgeImp>::DeleteEdge(const Vertex& v1, const Vertex& v2)
{
    edges.Delete(v1, v2);
    
    return true;
}