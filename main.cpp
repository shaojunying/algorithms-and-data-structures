#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heap/heap.h"

using namespace std;

int main() {
    MaxHeap<int> maxHeap = MaxHeap<int>(100);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 50; ++i) {
        maxHeap.insert(rand()%20);
    }
    maxHeap.showHeap();
    return 0;
}