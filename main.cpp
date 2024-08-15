#define NOMINMAX

#include <Windows.h>
#include <algorithm>
#include "RingC++.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(void) noexcept {
    srand(static_cast<unsigned int>(time(0)));
    RingBuffer ring(50);
    const char str[] = "!1234567890 abcdefghijklmnopqrstuvwxyz 1234567890 abcdefghijklmnopqrstuvwxyz 123456789 abcdefghijklmnopqrstuvwz 1234567!";
    int index = 0;
    char readBuffer[128];
    int ccc = 0;

    while (true) {
        size_t size = rand() % (sizeof(str) - 1);  // null 문자는 제외
        size_t space = ring.GetFreeSize();
        size_t byte_to_copy = std::min(space, size);

        // PUSH
        size_t first = std::min(byte_to_copy, sizeof(str) - 1 - index);
        size_t second = byte_to_copy - first;

        ring.Enqueue(str + index, first);
        index = (index + first) % (sizeof(str) - 1);

        if (second > 0) {
            ring.Enqueue(str, second);
            index = second;
        }

        // POP
        size_t size2 = rand() % (sizeof(str) - 1);
        size_t calcualteSize = std::min(ring.size(), size2);
        calcualteSize = std::min(calcualteSize, sizeof(readBuffer) - 1);
        ccc += ring.Dequeue(readBuffer, calcualteSize);
        readBuffer[calcualteSize] = '\0';
        std::cout << readBuffer;
    }

    return 0;
}


