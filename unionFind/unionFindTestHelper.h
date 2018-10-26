//
// Created by shao on 2018/10/24.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_UNIONFINDTESTHELPER_H
#define ALGORITHMS_AND_DATA_STRUCTURES_UNIONFINDTESTHELPER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "unionFind1.h"
#include "unionFind2.h"
#include "unionFind3.h"
#include "unionFind4.h"

class UnionFindTestHelper{
public:

    void testUnionFind1(int n){
        srand(time(nullptr));

        UnionFind1::UnionFind unionFind = UnionFind1::UnionFind(n);

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

    void testUnionFind2(int n){
        srand(time(nullptr));

        UnionFind2::UnionFind unionFind = UnionFind2::UnionFind(n);

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
        std::cout<<"UF2 "<<n*2<<" ops: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<std::endl;
    }


    void testUnionFind3(int n){
        srand(time(nullptr));

        UnionFind3::UnionFind unionFind = UnionFind3::UnionFind(n);

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
        std::cout<<"UF3 "<<n*2<<" ops: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<std::endl;
    }


    void testUnionFind4(int n){
        srand(time(nullptr));

        UnionFind4::UnionFind unionFind = UnionFind4::UnionFind(n);

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
        std::cout<<"UF4 "<<n*2<<" ops: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<std::endl;
    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_UNIONFINDTESTHELPER_H
