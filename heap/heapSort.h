//
// Created by shao on 2018/10/21.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_HEAPSORT_H
#define ALGORITHMS_AND_DATA_STRUCTURES_HEAPSORT_H

#include "heap.h"

/*算法1思路:
 * 按照元素在原数组中的顺序依次向堆中插入
 * 插入的过程中需要保证每次插入之后仍然是最大堆
 * 插入完成之后直接取出就是一个有序的数组
 * */
template <typename T>
void heapSort1(T array[],int n){
    MaxHeap<T> maxHeap =MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.insert(array[i]);
    }
    for (int i = 0; i < n; ++i) {
        array[i] = maxHeap.extractMax();
    }
}

/*算法2思路:
 * 按照元素的次序依次堆中的数组,
 * 在插入的时候不用保证每次插入仍然是最大堆
 * 插入完成之后从最后一个非叶节点开始,对每个子堆执行heapify操作,进而实现最大堆
 * 之后直接取出就是一个有序数组
 * */
template <typename T>
void heapSort2(T array[], int n){
    MaxHeap<T> maxHeap = MaxHeap<T>(array,n);
    for (int i = 0; i < n; ++i) {
        array[i] = maxHeap.extractMax();
    }
}

template <typename T>
void __shiftDown(T array[],int end, int start){
//    在这里堆的下标从0开始,所以start的左右节点是2*start+1,2*start+2
    while (start*2 < end){
        int j = start*2;
        if (j+1<end&&array[j]<array[j+1]){
            j++;
        }

        if (array[j]<=array[start]){
            break;
        }
        swap(array[j],array[start]);
        start=j;

    }
}


/* 算法3思路
 * 首先对原来的数组进行一次heapify操作,让数组变成一个最大堆
 * 之后将array[0]和array[n-1]进行交换,最大值到了数组的末尾,
 * 再对数组除了最后一个元素之外的元素进行一个shiftDown操作，之后第二大的元素将到array【0】的位置
 * 再次交换
 * 重复操作，一直到最后
 * */
template <typename T>
void heapSort3(T array[],int n){
    /*首先从第一个非叶节点开始，依次对该节点和所有子节点执行shiftDown操作，最终完成一个最大堆
     *此过程就是一个heapify的过程,直接在原数组的基础上构建最大堆
     */
    for (int i = (n-1)/2; i >= 0; --i) {
        __shiftDown(array,n,i);
    }
    for (int i = n-1; i > 0; --i) {
        swap(array[0],array[i]);
        __shiftDown(array,i,0);
    }
}


#endif //ALGORITHMS_AND_DATA_STRUCTURES_HEAPSORT_H
