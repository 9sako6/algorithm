#include "./header.hpp"

template<typename T>
struct RMQ {
    int L;
    vector<T> data;
    const T MAX;
    RMQ(int N, T MAX) : MAX(MAX) {
        L = 1;
        while (L < N) L <<= 1;
        data.assign(L * 2, MAX);
    }
    void update(int i, T x) {
        i += L;
        data[i] = x;
        i >>= 1;
        while (i > 0) {
            data[i] = min(data[i * 2], data[i * 2 + 1]);
            i >>= 1;
        }
    }
    int query(int l, int r, int k, int sl, int sr) {
        if (sr <= l || r <= sl) return MAX;
        if (l <= sl && sr <= r) return data[k];
        T dl = query(l, r, k * 2, sl, (sl + sr) / 2);
        T dr = query(l, r, k * 2 + 1, (sl + sr) / 2, sr);
        return min(dl, dr);
    }
    // min of [l, r)
    int query(int l, int r) { return query(l, r, 1, 0, L); }
    T operator[](const int &k) const {
        return data[k + L];
    }
};

// verify: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A