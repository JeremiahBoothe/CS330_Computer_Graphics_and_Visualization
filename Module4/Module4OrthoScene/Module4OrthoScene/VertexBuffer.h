#pragma once
#include "ShapeObject.h"

class VertexBuffer
{
	unsigned int renderID;

public:
	VertexBuffer(const void* data, unsigned int size);

	~VertexBuffer();

	void Bind();
	void Unbind();
};