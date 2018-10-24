//
// Created by shao on 2018/10/24.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND1_H
#define ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND1_H

#include <assert.h>

class UnionFind{
private:
    int count;
    int* id;

public:
    UnionFind(int n){
        count=n;
        id = new int[n];
        for (int i = 0; i < n; ++i) {
            id[i]=i;
        }
    }

    ~UnionFind(){
        delete [] id;
    }

    int find(int p){
        assert(p>=0&&p<count);
        return id[p];
    }

    bool isConnected(int p, int q){
        return find(p)==find(q);
    }

    void unionElements(int p, int q){
        int pId = find(p);
        int qId = find(q);

        if (pId==qId){
            return;
        }
        for (int i = 0; i < count; ++i) {
            if (find(i)==pId){
                id[i]=qId;
            }
        }
    }

};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND1_H
