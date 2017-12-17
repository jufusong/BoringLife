#include <bits/stdc++.h>

struct Matrix {
  static constexpr int md = 1e9 + 7;
  int rowCount, columnCount;
  std::vector<std::vector<int>> a;

  Matrix(int rowCount, int columnCount) {
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    a.assign(rowCount, std::vector<int>(columnCount));
  }

  Matrix(const std::vector<std::vector<int>>& a) : a(a), rowCount(a.size()), columnCount(a[0].size()) {}
  
  static Matrix identityMatrix(int size) {
    Matrix result(size, size);
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
    Matrix result(rowCount, o.columnCount);
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
    auto result = Matrix::identityMatrix(rowCount);
    auto t = *this;
    for (; n; n >>= 1, t = t * t) {
      if (n & 1) result = result * t;
    }
    return result;
  }
};

using namespace std;

const int mod = 1e9 + 7;
const int inf = 2e9;

int inverse(int a, int md) {
  return a == 1 ? a : (long long)(md - md / a) * inverse(md % a, md) % md;
}

long long solve(int x, int y) {
  int k = min(x, y);
  if (k < 0) return 0;
  Matrix mat({{1, 0, 0, 0, 0},
              {1, 1, 0, 0, 0},
              {0, -1, 1, 0, 0},
              {0, -1, 0, 1, 0},
              {0, 1, -1, -1, 1}});
  mat = mat ^ k;
  long long b = x, c = y, a = b * c;
  long long ret = a * mat.a[1][0] + b * mat.a[2][0] + c * mat.a[3][0] + mat.a[4][0];
  return (ret % mod + mod) % mod;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<long long> f(n + 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = (f[i - 1] + (long long) i * (i - 1) % mod * inverse(2, mod)) % mod;
  }
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a.insert(a.end(), a.begin(), a.end());
  vector<pair<int, int>> st(1, {inf, -1});
  vector<int> L(a.size(), 0), R(a.size());
  for (int i = 0; i < a.size(); i++) {
    while (a[i] > st.back().first) st.pop_back();
    L[i] = st.back().second;
    st.push_back({a[i], i});
  }
  st = vector<pair<int, int>>{{inf, a.size()}};
  for (int i = a.size() - 1; i >= 0; i--) {
    while (a[i] >= st.back().first) st.pop_back();
    R[i] = st.back().second;
    st.push_back({a[i], i});
  }
  int mx = *max_element(a.begin(), a.end());
  long long sum = n, ans = 0;
  sum = sum * (sum + 1) % mod * inverse(2, mod) % mod;
  sum = sum * (sum + 1) % mod * inverse(2, mod) % mod;
  for (int i = 0; i < n; i++) {
    if (a[i] != mx) {
      long long cnt = 0;
      auto rg = [](int x, int y) {
        if (x > y) return 0LL;
        if (x < 0) x = 0;
        return (long long)(x + y) * (y - x + 1) / 2 % mod;
      };
      if (L[i] == -1) {
        int x = i + 1, y = R[i] - i;
        cnt += f[x + y] - f[x] - f[y];
        int k = n - L[i + n] - 1;
        int r = R[i] - i;
        if (i == 0) r--;
        if (r >= 1) {
          cnt += rg(k - i + 2, k) * r % mod;
          if (i > 1) k = k - i + 1;
          cnt += solve(k, r);
        }
      } else if (R[i] > n) {
        int x = i - L[i], y = n - i;
        cnt += f[x + y] - f[x] - f[y];
        int k = R[i] - n - 1;
        if (k >= 0) {
          int r = i - L[i];
          cnt += rg(k - (n - i - 1) + 1, k) * r % mod;
          k = k - (n - i - 1);
          cnt += solve(k, r);
        }
      } else {
        int x = i - L[i], y = R[i] - i;
        cnt = f[x + y] - f[x] - f[y];
      }
      cnt = (cnt % mod + mod) % mod;
      sum = (sum - cnt + mod) % mod;
      ans = (ans + cnt * a[i]) % mod;
    }
  }
  ans = (ans + mx * sum) % mod;
  cout << ans << endl;
  return 0;
}
