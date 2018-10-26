//
// Created by shao on 2018/10/26.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND3_H
#define ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND3_H

#include <assert.h>

namespace UnionFind3 {
    class UnionFind {
    private:
        int count;
        int *parent;
        int *size;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            size=  new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                size[i]=1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] size;
        }

        int find(int p) {
            assert(p >= 0 && p < count);

            while (p != parent[p]) {
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
            if (size[pId]>size[qId]) {
                parent[qId] = pId;
                size[pId]+=size[qId];
            } else{
                parent[pId]=qId;
                size[qId]+=size[pId];
            }
        }

    };
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_UNIONFIND3_H
