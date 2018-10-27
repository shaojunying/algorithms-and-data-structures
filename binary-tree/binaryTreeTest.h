//
// Created by shao on 2018/10/27.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREETEST_H
#define ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREETEST_H

#include "binarySearch.h"
#include <iostream>

using namespace std;

int testBinaryFloorAndCeil(){
    int a[] = {1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6};
    int n = sizeof(a)/sizeof(int);
    for( int i = 0 ; i <= 8 ; i ++ ){

        int floorIndex = binarySearchFloor(a, n, i);
        cout<<"the floor index of "<<i<<" is "<<floorIndex<<".";
        if( floorIndex >= 0 && floorIndex < n )
            cout<<"The value is "<<a[floorIndex]<<".";
        cout<<endl;

        int ceilIndex = binarySearchCeil(a, sizeof(a)/sizeof(int), i);
        cout<<"the ceil index of "<<i<<" is "<<ceilIndex<<".";
        if( ceilIndex >= 0 && ceilIndex < n )
            cout<<"The value is "<<a[ceilIndex]<<".";
        cout<<endl;
        cout<<endl;
    }
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREETEST_H
