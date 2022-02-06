#pragma once

#include "edges.hpp"
#include <vector>

class AdjacencyMatrix : public Edges
{
public:
    AdjacencyMatrix() = default;
    ~AdjacencyMatrix() = default;

    virtual void Add(const Vertex& v1, const Vertex& v2, uint32_t weight) override
    {
        uint32_t v1Id = v1.GetId(),
                 v2Id = v2.GetId();

        uint32_t maxEdgeId = v1Id > v2Id ? v1Id : v2Id;

        if (maxEdgeId > sizeOfEdges_)
        {
            sizeOfEdges_ = maxEdgeId;

            edges_.reserve(maxEdgeId);

            for (auto a : edges_)
                a.reserve(maxEdgeId);
        }

        edges_[v2Id][v1Id] = edges_[v1Id][v2Id] = weight;
    };

    virtual void Delete(const Vertex& v1, const Vertex& v2) override
    {
        uint32_t v1Id = v1.GetId(),
                 v2Id = v2.GetId();

        edges_[v1Id][v2Id] = edges_[v2Id][v1Id] = 0;
    };

private:
    // It will store just weight of edges
    std::vector<std::vector<int>> edges_;
    uint32_t sizeOfEdges_;
};