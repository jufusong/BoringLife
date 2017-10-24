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
  void merge(int u, int v) { pre[find(u)] = find(v); }
};

int kruskal(int n, vector<tuple<int, int, int>> edges) {
  sort(edges.begin(), edges.end(),
       [](const tuple<int, int, int> &x, const tuple<int, int, int> &y) {
         return get<2>(x) < get<2>(y);
       });
  int cnt = 0, ret = 0;
  DisjointSet ds(n);
  for (auto e : edges) {
    int u, v, w;
    tie(u, v, w) = e;
    if (ds.find(u) != ds.find(v)) {
      ds.merge(u, v);
      ret += w, cnt++;
    }
  }
  return cnt == n - 1 ? ret : -1;
}

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_tuple(u, v, w));
  }
  cout << kruskal(n, edges) << endl;
  return 0;
}
