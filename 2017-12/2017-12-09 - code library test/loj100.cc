#include <bits/stdc++.h>

using namespace std;

struct Matrix {
  static constexpr int md = 1e9 + 7;
  int rowCount, columnCount;
  vector<vector<int>> a;

  Matrix(int rowCount, int columnCount) {
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    a.assign(rowCount, vector<int>(columnCount));
  }
  
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

const int mod = 1e9 + 7;

int main(int argc, char *argv[]) {
  int n, p, m;
  cin >> n >> p >> m;
  Matrix m1(n, p), m2(p, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j) {
      cin >> m1.a[i][j];
    }
  }
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> m2.a[i][j];
    }
  }
  for (auto v : (m1 * m2).a) {
    for (auto x : v) {
      cout << (x + mod) % mod << " ";
    }
    cout << endl;
  }
  return 0;
}
