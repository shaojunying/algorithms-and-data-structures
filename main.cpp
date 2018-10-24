#include <iostream>
#include "unionFind/unionFindTestHelper.h"

using namespace std;

int main() {

    UnionFindTestHelper unionFindTestHelper = UnionFindTestHelper();
    unionFindTestHelper.testUnionFind1(100000);
    unionFindTestHelper.testUnionFind2(100000);


    return 0;
}