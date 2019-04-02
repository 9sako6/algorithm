#include "./header.hpp"

// 素数判定O(√n)
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

// 約数の列挙O(√n)
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

// 素因数分解O(√n)
map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

// エラトステネスの篩O(n log log n)
// n以下の素数テーブルを作る
vector<bool> sieve(int n) {
    int prime[n + 1];                    // i番目の素数
    vector<bool> is_prime(n + 1, true);  // is_prime[i]がtrueならiは素数
    int p = 0;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return is_prime;
}