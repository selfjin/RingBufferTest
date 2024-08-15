#include "RingBuffer.h"




RingBuffer::RingBuffer() : write(0), read(0), size(0), capacity(Ring_Buffer_Size)
{
	buffer = (char*)malloc(sizeof(char) * Ring_Buffer_Size);

	// buffer = new char[Ring_Buffer_Size];
}

RingBuffer::~RingBuffer()
{
	free(buffer);
}

char* RingBuffer::getWritePos()
{
	return &buffer[write];
}

//int RingBuffer::getReadPos()
//{
//	return 0;
//}

int RingBuffer::getUseSize()
{
	return 0;
}

int RingBuffer::getFreeSize()
{
	return 0;
}


//-------------------------------------------------------------
// 
//-------------------------------------------------------------
