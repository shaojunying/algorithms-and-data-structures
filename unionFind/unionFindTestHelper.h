//
// Created by shao on 2018/10/24.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_UNIONFINDTESTHELPER_H
#define ALGORITHMS_AND_DATA_STRUCTURES_UNIONFINDTESTHELPER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "unionFind1.h"

class UnionFindTestHelper{
public:

    void testUnionFind(int n){
        srand(time(nullptr));

        UnionFind unionFind = UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; ++i) {
            int p = rand()%n;
            int q = rand()%n;
            unionFind.unionElements(p,q);
        }
        for (int j = 0; j < n; ++j) {
            int p = rand()%n;
            int q = rand()%n;
            unionFind.isConnected(p,q);
        }
        time_t endTime = clock();
        std::cout<<"UF1 "<<n*2<<" ops: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<std::endl;
    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_UNIONFINDTESTHELPER_H
