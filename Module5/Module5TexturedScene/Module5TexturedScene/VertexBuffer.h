#pragma once
#include "ShapeObject.h"

/* Still haven't transfered over to using this */
class VertexBuffer
{
	unsigned int renderID;

	public:
		VertexBuffer(const void* data, unsigned int size);

		~VertexBuffer();

		void Bind();
		void Unbind();
};