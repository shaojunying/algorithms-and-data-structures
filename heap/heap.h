//
// Created by shao on 2018/10/21.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_HEAP_H
#define ALGORITHMS_AND_DATA_STRUCTURES_HEAP_H

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

template <typename Item>
class MaxHeap{
private:
    Item* data;
//    当前堆中元素个数
    int count;
//    堆的容量
    int capacity;

//
    void shiftUp(int k){
//        从第k个元素开始,将k个k的父元素k/2进行比较,如果data[k]>data[k/2]就进行交换,一直到k等于1
        while (data[k]>data[k/2]){
            swap(data[k],data[k/2]);
            k/=2;
        }
    }

public:
//    让用户指定堆的大小
    MaxHeap(int capacity){
//        堆的索引从1开始
        data = new Item[capacity+1];
        this->capacity=capacity;
        count = 0;
    }
    ~MaxHeap(){
        delete [] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    void insert(Item item){
        assert(count+1<=capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }


//    展示堆
    void showHeap(){

//        只能打印100个元素以内的堆信息
        if (size()>=100){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

//        只能处理整数信息
        if (typeid(Item)!= typeid(int)){
            cout<<"This print function can only work for int item";
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";

        for (int i = 1; i <=size(); ++i) {
            assert(data[i]>0&&data[i]<100);
            cout<<data[i]<<" ";
        }

        cout<<endl;
        cout<<endl;

//        首先需要确定堆的层数
        int max_level = 0;
//        计算过程中剩余元素个数
        int reminder_node = size();
//        当前层中堆的元素
        int nodes_number_in_cur_level = 1;
        while (reminder_node > 0){
            max_level++;
            reminder_node-=nodes_number_in_cur_level;
            nodes_number_in_cur_level*=2;
        }
//        首先找出当前堆中最下层的节点的最大个数
        int max_nodes_number_in_max_level = static_cast<int>(pow(2, max_level - 1));
        int max_nodes_number_in_cur_level = max_nodes_number_in_max_level;
//        之后进行遍历
        int node_index_in_array = 1;
        for (int i = 0; i < max_level;i++){
//            找出第i层对应的节点个数
//            除了最大层之外,其余每层的节点数都是pow(2,i)个
//            但是,如果最大层不满的话,那么节点数就是count-(pow(2,i)-1) < pow(2,i)
            nodes_number_in_cur_level = (int) min(size() - (pow(2, i) - 1), pow(2, i));
//            对于第i层,需要输出对应层的节点
            string string1 = string(static_cast<unsigned int>(max_nodes_number_in_max_level * 3 - 1), ' ');
            bool isLeft = true;
            for (int index_in_cur_level = 0; index_in_cur_level < nodes_number_in_cur_level; ++index_in_cur_level,node_index_in_array++) {
//                这里需要将对应层的节点值放在字符串上
                putNumbersInLines(string1, data[node_index_in_array], index_in_cur_level,
                                  max_nodes_number_in_cur_level * 3 - 1, isLeft);
                isLeft=!isLeft;
            }
            cout<<string1<<endl;

            if (i == max_level - 1)
            {
                break;
            }

            string string2 = string(static_cast<unsigned int>(max_nodes_number_in_max_level * 3 - 1), ' ');
            for (int index_in_cur_level = 0; index_in_cur_level < nodes_number_in_cur_level; ++index_in_cur_level) {
                putBranchInLines(string2, index_in_cur_level, max_nodes_number_in_cur_level * 3 - 1);

            }
            cout<<string2<<endl;
            max_nodes_number_in_cur_level/=2;
        }
    }

private:

//  param1: string1 被放入的字符串
//  param2: item    要被放入的元素值
//  param3: node_index_in_cur_level 要被放入的元素在所在层级的下标
//  param4: cur_tree_width  当前子树要放入字符串的长度
//  param5: isLeft  当前节点是处在父节点的左边还是右边
    void putNumbersInLines(string& string1, Item item, int node_index_in_cur_level, int cur_tree_width, bool isLeft) {
//        这里是否-1只影响树的最底层
//        -1之后整体将会向左偏移一位
        int sub_tree_width = (cur_tree_width-1)/2;
        int offset = node_index_in_cur_level*(cur_tree_width+1)+sub_tree_width;
        assert(offset+1<string1.size());
        if (item<10){
            if (isLeft) {
                string1[offset + 0] = '0' + item;
            } else{
                string1[offset + 1] = '0' + item;
            }
        } else{
            string1[offset+0] = '0'+item/10;
            string1[offset+1] = '0'+item%10;
        }
    }
    void putBranchInLines(string &string2, int index_in_cur_level, int cur_tree_width) {
        int sub_tree_width = (cur_tree_width-1)/2;
        int sub_sub_tree_width = (sub_tree_width-1)/2;

//             在sub_sub处放置左节点,sub_sub+sub放置右节点
        int left_offset = sub_sub_tree_width+(cur_tree_width+1)*index_in_cur_level;
        assert(left_offset+1<string2.size());
        int right_offset = sub_sub_tree_width+sub_tree_width+1+(cur_tree_width+1)*index_in_cur_level;
        assert(right_offset<string2.size());
        string2[left_offset+1] = '/';
        string2[right_offset] = '\\';
    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_HEAP_H
