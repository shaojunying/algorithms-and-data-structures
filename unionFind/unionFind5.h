//
// Created by shao on 2018/10/26.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND5_H
#define ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND5_H

#include <assert.h>

namespace UnionFind5 {
    class UnionFind {
    private:
        int count;
        int *parent;
        int *rank;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank=  new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i]=1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);

            while (p != parent[p]) {
                parent[p] =  parent[parent[p]];
                p = parent[p];
            }
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pId = find(p);
            int qId = find(q);

            if (pId == qId) {
                return;
            }
            if (rank[pId]>rank[qId]) {
                parent[qId] = pId;
            } else if (rank[qId]>rank[pId]){
                parent[pId]=qId;
            } else{
                parent[pId]=qId;
                rank[qId]++;
            }
        }

    };
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND5_H
