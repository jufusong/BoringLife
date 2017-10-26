#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct DisjointSet {
  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  vector<int> pre;
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void merge(int u, int v) { pre[find(u)] = find(v); }
};

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    DisjointSet ds(200005);
    vector<pair<int, int>> vec;
    int n, m, T, W;
    scanf("%d%d%d%d", &n, &m, &T, &W);
    vector<tuple<int, int, int, int>> a(n);
    for (int i = 0; i < n; i++) {
      int d, x, y, z;
      scanf("%d%d%d%d", &d, &x, &y, &z);
      a[i] = make_tuple(d, x, y, z);
      vec.push_back({d, x});
      vec.push_back({d, y});
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    auto getIndex = [&vec](int x, int y) {
      return lower_bound(vec.begin(), vec.end(), make_pair(x, y)) - vec.begin();
    };
    sort(a.begin(), a.end(), [](const tuple<int, int, int, int>& x, const tuple<int, int, int, int>& y) {
        return get<3>(x) < get<3>(y);
      });
    vector<int> p(m + 1);
    for (int i = 1; i <= m; i++) {
      scanf("%d", &p[i]);
    }
    vector<tuple<int, int, int, int>> td;
    vector<pair<int, int>> cc;
    ll ans = 0;
    int cnt = 0;
    for (auto e : a) {
      int d, x, y, z;
      tie(d, x, y, z) = e;
      int u = getIndex(d, x), v = getIndex(d, y);
      if (ds.find(u) != ds.find(v)) {
        ds.merge(u, v);
        cc.push_back({z, d});
        cnt++;
        ans += z;
      } else {
        td.push_back(e);
      }
    }
    vector<bool> b(200005);
    for (auto e : td) {
      int d, x, y, z;
      tie(d, x, y, z) = e;
      int u = ds.find(getIndex(d, x));
      if (!b[u]) {
        b[u] = true;
        cc.push_back({z, d});
        ans += z;
        cnt++;
      }
    }
    sort(cc.begin(), cc.end());
    for (int i = (int)cc.size() - 1; i >= 0; i--) {
      int z, d;
      tie(z, d) = cc[i];
      if (W && p[d]) {
        ans -= z;
        W--, p[d]--;
      }
    }
    cout << cnt << endl;
    cout << ans << endl;
  }
  return 0;
}
