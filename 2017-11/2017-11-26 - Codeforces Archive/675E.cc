#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<class T>
struct IntervalTree {
  vector<T> a, b;
  int n;

  IntervalTree(int size) {
    a = vector<T>(size * 4);
    b = vector<T>(size * 4);
    n = size;
  }
  // modify here
  void pushDown(int l, int r, int p) {
    
  }
  // modify here
  void pushUp(int l, int r, int p) {
    a[p] = min(a[p * 2], a[p * 2 + 1]);
  }
  
  void update(int L, int R, T val) {
    update(1, n, 1, L, R, val);
  }
  
  void update(int l, int r, int p, int L, int R, T val) {
    if (l >= L && r <= R) {
      // modify here
      a[p] += val;
      b[p] += val;
      // modify here
      return;
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    if (m >= L) update(l, m, p * 2, L, R, val);
    if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
    pushUp(l, r, p);
  }

  T query(int L, int R) {
    return query(1, n, 1, L, R);
  }

  T query(int l, int r, int p, int L, int R) {
    if (l >= L && r <= R) {
      return a[p];
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    // modify here
    T ret = 1e18;
    if (m >= L) ret = min(ret, query(l, m, p * 2, L, R));
    if (m + 1 <= R) ret = min(ret, query(m + 1, r, p * 2 + 1, L, R));
    // modify here
    return ret;
  }
};

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  IntervalTree<ll> it(n);
  vector<int> a(n + 1, 0);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  vector<ll> b(n + 1, 0);
  it.update(n, n, n);
  for (int i = n - 1; i >= 1; i--) {
    b[i] = it.query(i + 1, a[i]) + n - i - a[i];
    ans += b[i];
    it.update(i, i, b[i] + i);
  }
  cout << ans << endl;
  return 0;
}
