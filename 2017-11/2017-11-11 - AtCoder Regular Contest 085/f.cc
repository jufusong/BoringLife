#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int inf = 1e9;

struct ST {
  int a[N * 4], b[N * 4];

  void pushdown(int p) {
    if (b[p]) {
      a[p * 2] += b[p];
      a[p * 2 + 1] += b[p];
      b[p * 2] += b[p];
      b[p * 2 + 1] += b[p];
      b[p] = 0;
    }
  }

  void update(int l, int r, int p, int L, int R, int val) {
    if (l >= L && r <= R) {
      a[p] += val;
      b[p] += val;
      return;
    }
    pushdown(p);
    int m = (l + r) / 2;
    if (m >= L) update(l, m, p * 2, L, R, val);
    if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
    a[p] = min(a[p * 2], a[p * 2 + 1]);
  }

  int query(int l, int r, int p, int L, int R) {
    if (l >= L && r <= R) {
      return a[p];
    }
    pushdown(p);
    int m = (l + r) / 2, ret = inf;
    if (m >= L) ret = min(ret, query(l, m, p * 2, L, R));
    if (m + 1 <= R) ret = min(ret, query(m + 1, r, p * 2 + 1, L, R));
    return ret;
  }
}st[2];

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
    vec[i] += vec[i - 1];
  }
  int Q;
  cin >> Q;
  vector<pair<int, int>> q(Q);
  for (int i = 0; i < Q; i++) {
    cin >> q[i].second >> q[i].first;
  }
  sort(q.begin(), q.end());
  int ans = vec[n];
  int h = 0;
  for (int j = 1; j <= n; j++) {
    if (h > 0) {
      //      cout << " init " << h << " " << vec[j + 1] - vec[h + 1] << endl;
      st[vec[j] - vec[j - 1]].update(1, Q, 1, 1, h, 1);
    }
    while (h < Q && q[h].first <= j) {
      int l, r;
      tie(r, l) = q[h];
      cout << l << " lr " << r << endl;
      int c1 = vec[r] - vec[l - 1];
      int c0 = r - l + 1 - c1;
      int v = vec[r] - c1 + c0;
      int p = lower_bound(q.begin(), q.end(), make_pair(l, 0)) - q.begin();
      cout << p << " p " << c1 << " " << c0 << endl;
      for (int i = 1; i <= h; i++) {
        cout << st[0].query(1, Q, 1, i, i) << " ";
      }
      cout << endl;
      if (p < h) {
        v = min(v, st[0].query(1, Q, 1, p + 1, h));
      }
      if (p > 0) {
        v = min(v, st[1].query(1, Q, 1, 1, p) - c1 + c0);
      }
            cout << h << " " << v << endl;
      ans = min(ans, vec[n] - vec[r] + v);
      for (int j = 0; j < 2; j++) {
        st[j].update(1, Q, 1, h + 1, h + 1, v);
      }
      h++;
    }
  }
  cout << ans << endl;
  return 0;
}
