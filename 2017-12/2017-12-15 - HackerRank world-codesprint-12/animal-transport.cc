#include <bits/stdc++.h>

using namespace std;

template <class T> struct IntervalTree {
  std::vector<T> a, b;
  int n;
  IntervalTree(int size) {
    a = std::vector<T>(size * 4);
    b = std::vector<T>(size * 4);
    n = size;
  }
  void pushDown(int l, int r, int p) {
    if (b[p]) {
      int m = (l + r) / 2;
      a[p * 2] += b[p];
      a[p * 2 + 1] += b[p];
      b[p * 2] += b[p];
      b[p * 2 + 1] += b[p];
      b[p] = 0;
    }
  }
  void pushUp(int l, int r, int p) { a[p] = max(a[p * 2],  a[p * 2 + 1]); }
  void update(int L, int R, T val) { update(1, n, 1, L, R, val); }
  void update(int l, int r, int p, int L, int R, T val) {
    if (l >= L && r <= R) {
      a[p] += val;
      b[p] += val;
      return;
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    if (m >= L) update(l, m, p * 2, L, R, val);
    if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
    pushUp(l, r, p);
  }
  T query(int L, int R) { return query(1, n, 1, L, R); }
  T query(int l, int r, int p, int L, int R) {
    if (l >= L && r <= R) {
      return a[p];
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    T ret = 0;
    if (m >= L) ret = max(ret, query(l, m, p * 2, L, R));
    if (m + 1 <= R) ret = max(ret, query(m + 1, r, p * 2 + 1, L, R));
    return ret;
  }
};

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int, int>>> g(m + 1);
    vector<char> T(n);
    vector<int> S(n), D(n);
    for (int i = 0; i < n; ++i) {
      cin >> T[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> S[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> D[i];
    }
    for (int i = 0; i < n; ++i) {
      if (D[i] > S[i]) {
        g[D[i]].push_back({S[i], T[i] == 'D' || T[i] == 'M'});
      }
    }
    IntervalTree<int> fw[2] = {m + 1, m + 1};
    vector<int> f(m + 1, 0);
    vector<int> ans(n + 1, inf);
    for (int i = 1; i <= m; i++) {
      f[i] = f[i - 1];
      for (auto e : g[i]) {
        int p = e.first, t = e.second;
        fw[t].update(1, p + 1, 1);
      }
      f[i] = max(fw[0].query(1, i), fw[1].query(1, i));
      fw[0].update(i + 1, i + 1, f[i]);
      fw[1].update(i + 1, i + 1, f[i]);
      if (ans[f[i]] == inf) ans[f[i]] = i;
    }
    for (int i = n - 1; i >= 1; i--) {
      ans[i] = min(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
      cout << (ans[i + 1] == inf ? -1 : ans[i + 1]) << " ";
    }
    cout << endl;
  }
  return 0;
}
