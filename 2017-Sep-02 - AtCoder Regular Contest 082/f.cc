#include <bits/stdc++.h>

using namespace std;

int X;

struct A {
  int t, a, id, p;
};

const int N = 100005;

int a[N * 4], b[N * 4];

void pushdown(int p) {
  a[p * 2] += b[p];
  a[p * 2 + 1] += b[p];
  b[p * 2] += b[p];
  b[p * 2 + 1] += b[p];
  b[p] = 0;
}

void update(int l, int r, int p, int L, int R, int val) {
  if (L > R) return;
  if (L <= l && R >= r) {
    a[p] += val;
    b[p] += val;
    return;
  }
  pushdown(p);
  int m = (l + r) / 2;
  if (m >= L) update(l, m, p * 2, L, R, val);
  if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
}

int query(int l, int r, int p, int P) {
  if (l == r) {
    return a[p];
  }
  pushdown(p);
  int m = (l + r) / 2;
  if (m >= P) return query(l, m, p * 2, P);
  else return query(m + 1, r, p * 2 + 1, P);
}

int main(int argc, char *argv[]) {
  int K;
  cin >> X >> K;
  vector<int> R(1, 0);
  for (int i = 0, t; i < K; i++) {
    cin >> t;
    R.push_back(t);
  }
  R.push_back(2e9);
  vector<A> Q;
  int m;
  cin >> m;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    Q.push_back({x, y, i, 0});
  }
  sort(Q.begin(), Q.end(), [](const A& x, const A& y) {
      return x.a < y.a;
    });
  int n = Q.size();
  for (int i = 0; i < (int)Q.size(); i++) {
    Q[i].p = i + 1;
    update(1, n, 1, i + 1, i + 1, Q[i].a);
  }
  int nl = 1, nr = n;
  vector<int> ans(n);
  sort(Q.begin(), Q.end(), [](const A& x, const A& y) {
      return x.t < y.t;
    });
  int h = 0;
  for (int i = 1; i < (int)R.size(); i++) {
    while (h < n && Q[h].t <= R[i]) {
      int p = Q[h].p;
      p = max(p, nl);
      p = min(p, nr);
      int x = query(1, n, 1, p);
      int y = Q[h].t - R[i - 1];
      if (i & 1) {
        y = -y;
      }
      ans[Q[h].id] = x + y;
      h++;
    }
    int y = R[i] - R[i - 1];
    if (i & 1) {
      y = -y;
      int low = nl, high = nr;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (query(1, n, 1, mid) + y > 0) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      if (high >= nl) {
        int v = query(1, n, 1, high);
        update(1, n, 1, high, high, -v);
        update(1, n, 1, high + 1, nr, y);
        nl = high;
      } else {
        update(1, n, 1, nl, nr, y);
      }
    } else {
      int low = nl, high = nr;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (query(1, n, 1, mid) + y < X) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      if (low <= nr) {
        int v = query(1, n, 1, low);
        update(1, n, 1, low, low, X-v);
        update(1, n, 1, nl, low - 1, y);
        nr = low;
      } else {
        update(1, n, 1, nl, nr, y);
      }
    }
  }
  for (auto x : ans) {
    x = max(x, 0);
    x = min(x, X);
    cout << x << endl;
  }
}
