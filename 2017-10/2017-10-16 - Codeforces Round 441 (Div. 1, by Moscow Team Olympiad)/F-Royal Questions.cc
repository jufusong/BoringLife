#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  vector<int> pre;
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void Union(int u, int v) { pre[find(u)] = find(v); }
};

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<tuple<int, int, int>> a(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    a[i] = {w, u, v};
  }
  vector<int> b(n + 1, 1);
  DisjointSet ds(n);
  sort(a.begin(), a.end(), greater<tuple<int, int, int>>());
  int ans = 0;
  for (auto e : a) {
    int u, v, w;
    tie(w, u, v) = e;
    int fu = ds.find(u), fv = ds.find(v);
    if (fu == fv) {
      ans += (b[fu] ? w : 0);
      b[fu] = 0;
    } else {
      ans += (b[fu] || b[fv] ? w : 0);
      ds.Union(fu, fv);
      b[fv] = (b[fv] + b[fu] == 2);
    }
  }
  cout << ans << endl;
  return 0;
}
