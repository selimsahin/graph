#pragma once

#include "vertex.hpp"

class Edges {
public:
    virtual void Add(const Vertex& v1, const Vertex& v2, uint32_t weight) = 0;
    virtual void Delete(const Vertex& v1, const Vertex& v2) = 0;
};