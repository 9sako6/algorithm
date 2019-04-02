#include <cassert>
#include <iostream>
#include <vector>

//
// Union-Find Tree size version
//
// verify: AOJ DSL_1_A
//
struct UnionFindSize {
    std::vector<int> data;
    const int n;
    UnionFindSize(int num) : data(num, -1), n(num) {}
    int find(int k) {
        assert(0 <= k && k < n);
        if (data[k] < 0) return k;
        return (data[k] = find(data[k]));
    }
    bool unite(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = find(x), y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    int size(int k) {
        assert(0 <= k && k < n);
        return (-data[find(k)]);
    }
    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return find(x) == find(y);
    }
};
