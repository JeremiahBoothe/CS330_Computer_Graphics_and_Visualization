#pragma once
#pragma once
#include "ShapeObject.h"

class IndexBuffer
{
	unsigned int renderID;

public:
	IndexBuffer(const void* data, unsigned int size);

	~IndexBuffer();

	void Bind();
	void Unbind();
};