#pragma once
#include "ShapeObject.h"

/* Still haven't transfered over to using this */
class IndexBuffer
{
	unsigned int renderID;

	public:
		IndexBuffer(const void* data, unsigned int size);

		~IndexBuffer();

		void Bind();
		void Unbind();
};