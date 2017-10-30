#include <bits/stdc++.h>

using namespace std;

struct Matrix {
  int rowCount, columnCount, md;
  vector<vector<int>> a;

  Matrix(int rowCount, int columnCount, int mod) {
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    this->md = mod;
    a.assign(rowCount, vector<int>(columnCount));
  }
  
  static Matrix identityMatrix(int size, int mod) {
    Matrix result(size, size, mod);
    for (int i = 0; i < size; i++) {
      result.a[i][i] = 1;
    }
    return result;
  }
  
  Matrix operator+(const Matrix &o) {
    assert(rowCount == o.rowCount);
    assert(columnCount == o.columnCount);
    Matrix result = *this;
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < columnCount; j++) {
        result.a[i][j] = (this->a[i][j] + o.a[i][j]) % md;
      }
    }
    return result;
  }

  Matrix operator*(const Matrix &o) {
    assert(columnCount == o.rowCount);
    Matrix result(rowCount, o.columnCount, md);
    for (int i = 0; i < rowCount; i++) {
      for (int j = 0; j < o.columnCount; j++) {
        for (int k = 0; k < columnCount; k++) {
          result.a[i][j] = (result.a[i][j] + (long long)this->a[i][k] * o.a[k][j]) % md;
        }
      }
    }
    return result;
  }

  Matrix operator^(long long n) {
    assert(rowCount == columnCount);
    auto result = Matrix::identityMatrix(rowCount, md);
    auto t = *this;
    for (; n; n >>= 1, t = t * t) {
      if (n & 1) result = result * t;
    }
    return result;
  }
};

const int mod = 1e9 + 7;

pair<vector<bool>, vector<int>> primeSieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> prime;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
      is_prime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
  return {is_prime, prime};
}

typedef long long ll;

int main(int argc, char *argv[]) {
  auto ret = primeSieve(15485863);
  string s;
  for (auto x : ret.second) {
    s += to_string(x);
  }
  ll L = s.size();
  ll b = 1;
  ll c = 1;
  for (int i = 0; i < s.size(); i++) {
    b = b * 10 % mod;
  }
  for (int i = 1; i < s.size(); i++) {
    c = (c * 10 + 1) % mod;
  }
  ll K = 1e12;
  Matrix m(5, 5, mod);
  m.a = {
    {1, 0, (int)c, 0, 0},
    {0, (int)b, (int)((mod - L * b % mod) % mod), 0, 0},
    {0, 0, (int)b, 1, 0},
    {0, 0, 0, 1, 0},
    {(int)(mod - L), (int)c, (int)((mod - c * L % mod) % mod), 0, 1}
  };
  m = m ^ K;
  ll ans = 0;
  for (int i = (int)s.size() - 1, y = 1; i >= 0; i--, y = ((ll)y * 10 + 1) % mod) {
    int v = s[i] - '0';
    ll x = ((K - 1) % mod * L + i + 1) % mod;
    ll xy = x * y % mod;
    ll z = (x * m.a[0][3] + (ll)y * m.a[1][3] + xy * m.a[2][3] + m.a[4][3]) % mod;
    ans = (ans + z * v) % mod;
  }
  cout << ans << endl;
  return 0;
}
