//
// Created by shao on 2018/10/26.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_BINARYSEARCH_H
#define ALGORITHMS_AND_DATA_STRUCTURES_BINARYSEARCH_H

#include <assert.h>

/*
 * 非递归实现二分查找
 * */
template <typename Item>
int binarySearch(const Item nums[],int n,Item target){
//    我们这里二分查找的时候找的是[l,r]
    int l = 0,r = n-1;
    while (l<=r){
//        int mid = (l+r)/2;
        int mid = l + (r-l)/2;
        if (nums[mid]==target){
            return mid;
        } else if (nums[mid] > target){
            r = mid-1;
        } else{
            l = mid +1;
        }
    }
    return -1;
}

/*
 * 递归实现二分查找
 * */
template <typename Item>
int binarySearchByRecursion(const Item nums[],int n,Item target){
    binarySearchByRecursionHelper(nums,0,n-1,target);
}

template <typename Item>
int binarySearchByRecursionHelper(const Item nums[],int l,int r,Item target){
    if (l > r){
        return -1;
    }
    int mid = l + (r-l)/2;
    if (nums[mid] == target){
        return mid;
    } else if (nums[mid]>target){
        return binarySearchByRecursionHelper(nums,l,mid-1,target);
    } else{
        return binarySearchByRecursionHelper(nums,mid-1,r,target);
    }
}

template <typename Item>
/*
 * 该函数功能
 * 如果nums中存在target,那么返回第一个target的下标
 * 如果nums中不存在,那么返回最后一个小于target的元素下标
 * */
int binarySearchFloor(const Item nums[], int n, Item target){
//    我们这里l指向的是最后一个小于target的元素,所以初始的时候为-1
    int l =-1,r = n-1;
    while (l<r){
//        这里对l+r/2进行向上取整
//        如果我们向下取整,那么如果l+1==r的情况下进行l=mid将会产生死循环
        int mid = l+(r-l+1)/2;
        if (nums[mid]>=target){
            r=mid-1;
        } else{
//            因为我们需要将l指向最后一个小于target的元素,所以我们这里不能设置成mid+1,
//            可能mid就是最后一个小于target的元素
            l=mid;
        }
    }
//    在l+1==r情况下才会发生不满足l《r的情况，但是根据上面分析可知不满足之后只有可能l==r
    assert(l==r);
    if (l+1<n&&nums[l+1]==target){
        return l+1;
    }
    return l;
}

template <typename Item>
int binarySearchCeil(const Item nums[], int n, Item target){
    int l =-1,r = n-1;
    while (l<r){
        int mid = l+(r-l)/2;
        if (nums[mid]<=target){
            l=mid+1;
        } else{
            r=mid;
        }
    }
//    在l+1==r情况下才会发生不满足l《r的情况，但是根据上面分析可知不满足之后只有可能l==r
    assert(l==r);
    if (l-1>0&&nums[l-1]==target){
        return l-1;
    }
    return l;
}


#endif //ALGORITHMS_AND_DATA_STRUCTURES_BINARYSEARCH_H
