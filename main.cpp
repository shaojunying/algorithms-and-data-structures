#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heap/heap.h"

using namespace std;

int main() {
//    MaxHeap<int> maxHeap = MaxHeap<int>(50);
//    srand(static_cast<unsigned int>(time(nullptr)));
//    for (int i = 0; i < 50; ++i) {
//        maxHeap.insert(rand()%1000);
//    }
////    maxHeap.showHeap();
//    for (int i = 0; i < 50; ++i) {
//        cout<<maxHeap.extractMax()<<" ";
//    }
    int* a = new int[5000];
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 5000; ++i) {
        a[i]=rand()%1000;
    }
    heapSort2(a,5000);
    for (int j = 0; j < 5000; ++j) {
        cout<<a[j]<<" ";
    }

    return 0;
}