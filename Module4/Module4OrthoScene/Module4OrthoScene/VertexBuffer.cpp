#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) :
    renderID()
{


    glGenBuffers(1, &renderID);
    glBindBuffer(GL_ARRAY_BUFFER, renderID); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &renderID);
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, renderID);

}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}