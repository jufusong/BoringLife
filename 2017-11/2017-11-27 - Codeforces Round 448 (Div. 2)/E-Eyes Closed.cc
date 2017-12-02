#include <bits/stdc++.h>

template<class T>
struct IntervalTree {
  std::vector<T> a, b, c;
  int n;

  IntervalTree(int size) {
    a = c = std::vector<T>(size * 4);
    b = std::vector<T>(size * 4, 1);
    n = size;
  }

  void pushDown(int l, int r, int p) {
    int m = (l + r) / 2;
    int l1 = m - l + 1, l2 = r - l + 1 - l1;
    a[p * 2 + 0] = a[p * 2 + 0] * b[p] + c[p] * l1;
    b[p * 2 + 0] *= b[p];
    c[p * 2 + 0] = c[p] + b[p] * c[p * 2 + 0];
    a[p * 2 + 1] = a[p * 2 + 1] * b[p] + c[p] * l2;
    b[p * 2 + 1] *= b[p];
    c[p * 2 + 1] = c[p] + b[p] * c[p * 2 + 1];
    b[p] = 1;
    c[p] = 0;
  }

  void pushUp(int l, int r, int p) {
    a[p] = a[p * 2] + a[p * 2 + 1];
  }
  
  void update(int L, int R, T val, T val2) {
    update(1, n, 1, L, R, val, val2);
  }
  
  void update(int l, int r, int p, int L, int R, T val, T val2) {
    if (l >= L && r <= R) {
      a[p] = a[p] * val + val2 * (r - l + 1);
      b[p] *= val;
      c[p] = c[p] * val + val2;
      return;
    }
    pushDown(l, r, p);
    int m = (l + r) / 2;
    if (m >= L) update(l, m, p * 2, L, R, val, val2);
    if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val, val2);
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
    T ret = 0;
    if (m >= L) ret += query(l, m, p * 2, L, R);
    if (m + 1 <= R) ret += query(m + 1, r, p * 2 + 1, L, R);
    return ret;
  }
};

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, Q;
  cin >> n >> Q;
  IntervalTree<double> tree(n);
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    tree.update(i, i, 1, t);
  }
  while (Q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      double sum1 = tree.query(l1, r1), sum2 = tree.query(l2, r2);
      double n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
      //      cout << sum1 << " " << sum2 << endl;
      tree.update(l1, r1, (n1 - 1) / n1, sum2 / n2 / n1);
      tree.update(l2, r2, (n2 - 1) / n2, sum1 / n1 / n2);
    } else {
      int l1, l2;
      cin >> l1 >> l2;
      printf("%.10f\n", tree.query(l1, l2));
      fflush(stdout);
    }

  }
  return 0;
}
