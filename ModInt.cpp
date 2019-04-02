template <int mod>
struct ModInt {
  using i64 = int64_t;
  i64 x;
  ModInt() : x(0) {}
  ModInt(i64 y) : x(y >= 0 ? y % mod : ((mod - (-y) % mod) % mod)) {}
  ModInt &operator+=(const ModInt &rhs) {
    if ((x += rhs.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &rhs) {
    if ((x += mod - rhs.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &rhs) {
    x = x * rhs.x % mod;
    return *this;
  }
  ModInt &operator/=(const ModInt &rhs) {
    *this *= rhs.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  ModInt operator==(const ModInt &rhs) const { return x == rhs.x; }
  ModInt operator!=(const ModInt &rhs) const { return x != rhs.x; }
  friend ostream &operator<<(ostream &os, const ModInt &rhs) {
    return os << rhs.x;
  }
  friend istream &operator>>(istream &is, ModInt &rhs) {
    i64 t;
    is >> t;
    rhs = ModInt<mod>(t);
    return (is);
  }
private:
  ModInt inverse() const {
    i64 a = x, u = 1LL, v = 0LL, t, b = (i64)mod;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
};
using mint = ModInt<1000000007>;