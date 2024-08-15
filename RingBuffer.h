#pragma once
#include <iostream>

#define Ring_Buffer_Size 10000


class RingBuffer
{
public:
	RingBuffer();
	~RingBuffer();

	//-------------------------------------------------------------
	// 
	//-------------------------------------------------------------

	char* getWritePos();
	char* getReadPos();
	int getUseSize();
	int getFreeSize();

	int clear();
	void resize();
	
	//-------------------------------------------------------------
	// 
	//-------------------------------------------------------------

	

	
private:
	int write;
	int read;
	int size;
	int capacity;

	char* buffer;

};

