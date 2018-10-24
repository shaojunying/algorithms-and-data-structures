#include <iostream>
#include "unionFind/unionFindTestHelper.h"

using namespace std;

int main() {

    UnionFindTestHelper unionFindTestHelper = UnionFindTestHelper();
    unionFindTestHelper.testUnionFind(100000);


    return 0;
}