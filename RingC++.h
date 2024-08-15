#pragma once

#include <iostream>
#include <algorithm> 


//class RingBuffer
//{
//public:
//    RingBuffer(int capacity);
//    ~RingBuffer();
//
//    int getSize() const { return _size; }
//    int getCapacity() const { return _capacity; }
//    int Enqueue(const char* data, int bytes);
//    int Dequeue(char* data, int bytes);
//
//private:
//    int _begin_index;
//    int _end_index;
//    int _size;
//    int _capacity;
//    char* buffer;
//};


class RingBuffer {
public:
    RingBuffer(size_t capacity);
    ~RingBuffer();

    size_t Enqueue(const char* data, size_t bytes);
    size_t Dequeue(char* data, size_t bytes);

    size_t GetFreeSize() const;  // ������ ���� ���� ũ�⸦ ��ȯ
    size_t size() const;         // ���ۿ� ����� ������ ũ�⸦ ��ȯ

private:
    char* buffer;
    size_t _begin_index;
    size_t _end_index;
    size_t _size;
    size_t _capacity;
};