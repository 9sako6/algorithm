#include <cassert>
#include <iostream>
#include <vector>
#include "../UnionFindSize.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    UnionFindSize uf{n};
    vector<int> ans;
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            ans.push_back(uf.same(x, y));
        } else {
            uf.unite(x, y);
        }
    }
    for (auto &a : ans) {
        cout << a << endl;
    }

    return 0;
}