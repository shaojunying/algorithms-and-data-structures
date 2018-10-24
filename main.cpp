#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heap/heap.h"
#include "heap/heapSort.h"
#include "heap/indexHeap.h"

using namespace std;

int main() {

    MaxIndexHeap<int> maxIndexHeap = MaxIndexHeap<int>(100);

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 50; ++i) {
        maxIndexHeap.insert(i,rand()%1000);
    }
    for (int k = 0; k < 50; ++k) {
        maxIndexHeap.change(k,rand()%1888);
    }
    for (int j = 0; j < 50; ++j) {
        int result_index = maxIndexHeap.extractMax();
        cout<<maxIndexHeap.getItem(result_index)<<" ";
    }

    return 0;
}