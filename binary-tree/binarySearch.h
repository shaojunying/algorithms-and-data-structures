//
// Created by shao on 2018/10/26.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_BINARYSEARCH_H
#define ALGORITHMS_AND_DATA_STRUCTURES_BINARYSEARCH_H

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


#endif //ALGORITHMS_AND_DATA_STRUCTURES_BINARYSEARCH_H
