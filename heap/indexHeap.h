//
// Created by shao on 2018/10/22.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_INDEXHEAP_H
#define ALGORITHMS_AND_DATA_STRUCTURES_INDEXHEAP_H

#include <iostream>
#include <cmath>
#include <assert.h>
#include <typeinfo>
#include <array>

using namespace std;

template <typename Item>
class MaxIndexHeap {
private:
    Item *data;
//    当前堆中元素个数
    int count;
//    堆的容量
    int capacity;
//    下标数组
    int *index;


//
    void __shiftUp(int k) {
//        从第k个元素开始,将k个k的父元素k/2进行比较,如果data[k]>data[k/2]就进行交换,一直到k等于1
        while (k > 1 && data[index[k]] > data[index[k / 2]]) {
            swap(data[index[k]], data[index[k / 2]]);
            k /= 2;
        }
    }

    void __shiftDown(int k) {
        while (2 * k <= size()) {
            int j = 2 * k;
            if (j + 1 <= size() && data[index[j + 1]] > data[index[j]]) {
                j++;
            }
            if (data[index[k]] < data[index[j]]) {
                swap(data[index[k]], data[index[j]]);
                k = j;
            } else {
                break;
            }
        }

    }

public:
//    让用户指定堆的大小
    MaxIndexHeap(int capacity) {
//        堆的索引从1开始
        data = new Item[capacity + 1];
        index = new int[capacity +1];
        this->capacity = capacity;
        count = 0;
    }

    ~MaxIndexHeap() {
        delete[] data;
        delete[] index;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(int i,Item item) {
        assert(count + 1 <= capacity);
        assert(i+1>0&&i+1<=capacity);

        i++;
        index[count+1]=i;
        data[i] = item;
        count++;
        __shiftUp(count);
    }

    Item getItem(int i){
        return data[index[i]];
    }

    int extractMax() {
        assert(count>0);
        int result = index[1];
        swap(index[count], index[1]);
        count--;
        __shiftDown(1);
        return result;
    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_INDEXHEAP_H
