#include <cassert>
#include <iostream>
#include <vector>
#include "../UnionFindWeighted.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

int main() {
    int N, M;
    std::cin >> N >> M;
    WeightedUnionFind<int> uf(N);
    while (M--) {
        int a, b, c, d;
        std::cin >> a >> b >> c;
        if (a == 0) {
            std::cin >> d;
            uf.unite(b, c, d);
        } else {
            if (uf.same(b, c)) {
                std::cout << uf.diff(b, c) << std::endl;
            } else {
                std::cout << "?" << std::endl;
            }
        }
    }
    return 0;
}
