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
    int *reverse;


//
    void __shiftUp(int k) {
//        从第k个元素开始,将k个k的父元素k/2进行比较,如果data[k]>data[k/2]就进行交换,一直到k等于1
        while (k > 1 && data[index[k]] > data[index[k / 2]]) {
            swap(data[index[k]], data[index[k / 2]]);
            reverse[index[k]]=k;
            reverse[index[k/2]]=k/2;
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
                reverse[index[k]]=k;
                reverse[index[j]]=j;
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
        reverse = new int[capacity +1];
        this->capacity = capacity;
        count = 0;
    }

    ~MaxIndexHeap() {
        delete[] data;
        delete[] index;
        delete[] reverse;
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
        reverse[i]=count;
        data[i] = item;
        count++;
        __shiftUp(count);
    }

    Item getItem(int i){
        return data[i];
    }

    void change(int i,Item item){
        i++;
        data[i]=item;

//        for (int j = 0; j < count; ++j) {
//            if (index[j] == i){
//                __shiftDown(j);
//                __shiftUp(j);
//                return;
//            }
//        }
        __shiftUp(reverse[i]);
        __shiftDown(reverse[i]);

    }

//    此处返回的是最大值在data中的下标
    int extractMax() {
        assert(count>0);
        int result_index = index[1];
        swap(index[count], index[1]);
        reverse[index[count]]=count;
        reverse[index[1]]=1;
        count--;
        __shiftDown(1);
        return result_index;
    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_INDEXHEAP_H
