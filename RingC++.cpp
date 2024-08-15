//#include "RingC++.h"
//
//
//RingBuffer::RingBuffer(int capacity)
//    : _begin_index(0)
//    , _end_index(0)
//    , _size(0)
//    , _capacity(capacity)
//{
//    buffer = new char[capacity];
//}
//
//RingBuffer::~RingBuffer()
//{
//    delete[] buffer;
//}
//
//int RingBuffer::Enqueue(const char* data, int bytes)
//{
//    if (bytes == 0) return 0;
//
//    int capacity = _capacity;
//    int bytes_to_write = std::min(bytes, capacity - _size); // Free Size�� ��
//
//    // ����Ⱑ �߻��ϴ��� Ȯ��
//    if (_size + bytes_to_write > capacity) {
//        // ����Ⱑ �߻��� ���ɼ��� �ִ� ���, ���⸦ ����
//        bytes_to_write = capacity - _size;
//    }
//
//
//    // ���� ������ �ϴ� ����Ʈ��, ( Free Size ) ���� �۰ų� ���ٸ�
//    if (bytes_to_write <= capacity - _end_index)
//    {
//        memcpy(buffer + _end_index, data, bytes_to_write);
//        _end_index += bytes_to_write;
//        if (_end_index == capacity) _end_index = 0;
//    }
//    // �Ѿ����� ....
//    else
//    {
//        int Use_Size = capacity - _end_index;  // Use Size
//        memcpy(buffer + _end_index, data, Use_Size);  // ��� ������ ��ŭ ����
//
//        int Remaining_Byte = bytes_to_write - Use_Size;  // �ϴ� �� ����Ʈ ����, ���� ����Ʈ ������
//        memcpy(buffer, data + Use_Size, Remaining_Byte); // �տ��ٰ� ��
//
//        _end_index = Remaining_Byte;
//    }
//
//    _size += bytes_to_write;
//    return bytes_to_write;
//}
//
//int RingBuffer::Dequeue(char* data, int bytes)
//{
//    if (bytes == 0) return 0;
//
//    int capacity = _capacity;
//    int bytes_to_read = std::min(bytes, _size);
//
//    // Read in a single step
//    if (bytes_to_read <= capacity - _begin_index)
//    {
//        memcpy(data, buffer + _begin_index, bytes_to_read);
//        _begin_index += bytes_to_read;
//        if (_begin_index == capacity) _begin_index = 0;
//    }
//    // Read in two steps
//    else
//    {
//        int size_1 = capacity - _begin_index;
//        memcpy(data, buffer + _begin_index, size_1);
//        int size_2 = bytes_to_read - size_1;
//        memcpy(data + size_1, buffer, size_2);
//        _begin_index = size_2;
//    }
//
//    _size -= bytes_to_read;
//    return bytes_to_read;
//}
//
//


#include "RingC++.h"

RingBuffer::RingBuffer(size_t capacity)
    : _begin_index(0)
    , _end_index(0)
    , _size(0)
    , _capacity(capacity)
{
    buffer = new char[capacity];
}

RingBuffer::~RingBuffer()
{
    delete[] buffer;
}

size_t RingBuffer::Enqueue(const char* data, size_t bytes)
{
    if (bytes == 0) return 0;

    size_t capacity = _capacity;
    size_t bytes_to_write = std::min(bytes, capacity - _size); // Free Size�� ��

    if (_size + bytes_to_write > capacity) {
        bytes_to_write = capacity - _size;
    }

    if (bytes_to_write <= capacity - _end_index)
    {
        memcpy(buffer + _end_index, data, bytes_to_write);
        _end_index += bytes_to_write;
        if (_end_index == capacity) _end_index = 0;
    }
    else
    {
        size_t Use_Size = capacity - _end_index;
        memcpy(buffer + _end_index, data, Use_Size);

        size_t Remaining_Byte = bytes_to_write - Use_Size;
        memcpy(buffer, data + Use_Size, Remaining_Byte);

        _end_index = Remaining_Byte;
    }

    _size += bytes_to_write;
    return bytes_to_write;
}

size_t RingBuffer::Dequeue(char* data, size_t bytes)
{
    if (bytes == 0) return 0;

    size_t capacity = _capacity;
    size_t bytes_to_read = std::min(bytes, _size);

    if (bytes_to_read <= capacity - _begin_index)
    {
        memcpy(data, buffer + _begin_index, bytes_to_read);
        _begin_index += bytes_to_read;
        if (_begin_index == capacity) _begin_index = 0;
    }
    else
    {
        size_t size_1 = capacity - _begin_index;
        memcpy(data, buffer + _begin_index, size_1);
        size_t size_2 = bytes_to_read - size_1;
        memcpy(data + size_1, buffer, size_2);
        _begin_index = size_2;
    }

    _size -= bytes_to_read;
    return bytes_to_read;
}

size_t RingBuffer::GetFreeSize() const
{
    return _capacity - _size;
}

size_t RingBuffer::size() const
{
    return _size;
}


