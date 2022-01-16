#pragma once

class Vertex {
    public:
        static Vertex CreateVertex(void *data, size_t size);
        uint64_t GetId() const { return id_; }
        void* GetData() const { return data_; }
    
    private:
        Vertex();
        Vertex(void *data, size_t size);
        
        uint32_t id_;
        void *data_;
        size_t size_;
        static uint32_t next_id_;
};

uint32_t Vertex::next_id_ = 1;

Vertex::Vertex()
{
    id_ = next_id_;
    data_ = nullptr;
    size_ = 0;
    
    ++next_id_;
}

Vertex::Vertex(void *data, size_t size)
{
    id_ = next_id_;
    data_ = data;
    size_ = size;
    
    ++next_id_;
}

Vertex Vertex::CreateVertex(void *data, size_t size)
{
    return Vertex(data, size);
}