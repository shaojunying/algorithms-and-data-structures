#include <iostream>
#include "unionFind/unionFindTestHelper.h"

using namespace std;

int main() {

    int n = 1000000;

    UnionFindTestHelper unionFindTestHelper = UnionFindTestHelper();
//    unionFindTestHelper.testUnionFind1(n);
//    unionFindTestHelper.testUnionFind2(n);
    unionFindTestHelper.testUnionFind3(n);
    unionFindTestHelper.testUnionFind4(n);
    unionFindTestHelper.testUnionFind5(n);
    unionFindTestHelper.testUnionFind6(n);


    return 0;
}