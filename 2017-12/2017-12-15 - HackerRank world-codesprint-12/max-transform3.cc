#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int inf = 2e9;

template <class T> struct SparseTable {
  std::vector<std::vector<T>> f;
  std::vector<int> lg;
  SparseTable() {}
  SparseTable(const std::vector<T> &a) { init(a); }
  void init(const std::vector<T> &a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, std::vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int j = lg[r - l + 1];
    return max(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

int solve(vector<int> a) {
  int n = a.size();
  SparseTable<int> sd(a);
  for (int k = 1; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      int mx = sd.query(i, i + k);
      a.push_back(mx);
    }
  }
  vector<pair<int, int>> st(1, {inf, -1});
  vector<int> L(a.size()), R(a.size());
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
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    int x = (i - L[i]), y = R[i] - i;
    ans = (ans + (long long) x * y % mod * a[i]) % mod;
  }
  return ans;
}

int inverse(int a, int md) {
  return a == 1 ? a : (long long)(md - md / a) * inverse(md % a, md) % md;
}

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

long long sol(int x, int y) {
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

int solve2(vector<int> a) {
  int n = a.size();
  vector<long long> f(n + 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = (f[i - 1] + (long long) i * (i - 1) % mod * inverse(2, mod)) % mod;
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
          cnt += sol(k, r);
        }
      } else if (R[i] > n) {
        int x = i - L[i], y = n - i;
        cnt += f[x + y] - f[x] - f[y];
        int k = R[i] - n - 1;
        if (k >= 0) {
          int r = i - L[i];
          cnt += rg(k - (n - i - 1) + 1, k) * r % mod;
          k = k - (n - i - 1);
          cnt += sol(k, r);
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
  return ans;
}
int main(int argc, char *argv[]) {
  int dd = 0;
  srand(time(0));
  while (true) {
    vector<int> a;
    for (int i = 0; i < 1000; i++) {
      a.push_back(rand() % 10 + 1);
    }
    if (solve(a) != solve2(a)) {
      cout << "ddddd" << endl;
      for (auto x : a) {
        cout << x << " ";
      }
      cout << endl;
      cout << solve(a) << " " << solve2(a) << endl;
      break;
    }
    cout << dd++ << endl;
  }
  /*  int n;
  cin >> n;
  f.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] = (f[i - 1] + (long long) i * (i + 1) % mod * inverse(2, mod)) % mod;
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
      long long cnt = (long long)(i - L[i]) * (R[i] - i) % mod;
      int x = (i + n - L[i + n]), y = R[i] - i;
      cnt = (cnt + solve(x - 1, y - 1)) % mod;
      sum = (sum - cnt + mod) % mod;
      ans = (ans + cnt * a[i]) % mod;
    }
  }
  ans = (ans + mx * sum) % mod;
  cout << ans << endl;*/
  return 0;
}
