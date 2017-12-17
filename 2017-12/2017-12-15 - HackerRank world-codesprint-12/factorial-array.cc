#include <bits/stdc++.h>

using namespace std;

struct IntervalTree {
  std::vector<vector<int>> a;
  vector<int> b;
  int n;
  IntervalTree(int size) {
    a = vector<vector<int>>(size * 4, vector<int>(40));
    b = vector<int>(size * 4);
    n = size;
  }
  void pushDown(int l, int r, int p) {
    if (b[p]) {
      for (int i = 0; i < 2; i++) {
        for (int j = 39; j >= 0; j--) {
          a[p * 2 + i][j] = (b[p] > j ? 0 : a[p * 2 + i][j - b[p]]);
        }
        b[p * 2 + i] += b[p];
      }
      b[p] = 0;
    }
  }
  void pushUp(int l, int r, int p) {
    for (int i = 0; i < 40; i++) {
      a[p][i] = a[p * 2][i] + a[p * 2 + 1][i];
    }
  }
  void update(int L, int R) { update(1, n, 1, L, R); }
  void update2(int p, int val) {update2(1, n, 1, p, val);}
  void update(int l, int r, int p, int L, int R) {
    if (l >= L && r <= R) {
      b[p]++;
      for (int i = 39; i >= 1; i--) {
        a[p][i] = a[p][i - 1];
      }
      a[p][0] = 0;
      return;
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    if (m >= L) update(l, m, p * 2, L, R);
    if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R);
    pushUp(l, r, p);
  }
  void update2(int l, int r, int p, int P, int val) {
    if (l == r) {
      a[p] = vector<int>(40);
      if (val < 40) a[p][val]++;
      return;
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    if (m >= P) update2(l, m, p * 2, P, val);
    else update2(m + 1, r, p * 2 + 1, P, val);
    pushUp(l, r, p);
  }
  
  vector<int> query(int L, int R) { return query(1, n, 1, L, R); }
  vector<int> query(int l, int r, int p, int L, int R) {
    if (l >= L && r <= R) {
      return a[p];
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    vector<int> ret(40);
    if (m >= L) {
      auto r1 = query(l, m, p * 2, L, R);
      for (int i = 0; i < 40; i++) {
        ret[i] += r1[i];
      }
    } 
    if (m + 1 <= R) {
      auto r1 = query(m + 1, r, p * 2 + 1, L, R);
      for (int i = 0; i < 40; i++) {
        ret[i] += r1[i];
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  const int mod = 1e9;
  vector<long long> fac(40);
  fac[0] = 1;
  for (int i = 1; i < 40; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  int n, m;
  cin >> n >> m;
  IntervalTree tree(n);
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    tree.update2(i, t);
  }
  for (int i = 0; i < m; ++i) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      tree.update(x, y);
    }
    if (op == 2) {
      auto ret = tree.query(x, y);
      long long ans = 0;
      for (int i = 0; i < 40; i++) {
        ans = (ans + fac[i] * ret[i]) % mod;
      }
      cout << ans << endl;
    }
    if (op == 3) {
      tree.update2(x, y);
    }
  }

  return 0;
}
