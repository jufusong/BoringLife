#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<pair<int, int>> g[N];
vector<int> sp;
int dep[N], dfn[N], lg[2 * N], sum[N];
pair<int, int> dp[21][2 * N];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  dfn[u] = sp.size();
  sp.push_back(u);
  for (auto e : g[u]) {
    int v = e.first;
    if (v != fa) {
      sum[v] = sum[u] + e.second;
      dfs(v, u);
      sp.push_back(u);
    }
  }
}

void lca_init() {
  int n = sp.size();
  for (int i = 1, j = 0; i <= n; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = {dfn[sp[i]], sp[i]};
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int LCA(int u, int v) {
  int l = dfn[u], r = dfn[v];
  if (l > r) swap(l, r);
  int j = lg[r - l + 1];
  return min(dp[j][l], dp[j][r - (1 << j) + 1]).second;
}

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
}ds(N);

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 1, u, t; i <= n; i++) {
    cin >> u >> t;
    if (u != -1) {
      g[u].push_back({i, t});
      ds.merge(i, u);
    } else {
      vec.push_back(i);
    }
  }
  for (auto r : vec) {
    dfs(r, 0);
  }
  lca_init();
  int Q;
  cin >> Q;
  while (Q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (u == v || ds.find(v) != ds.find(u)) {
      cout << "NO" << endl;
      continue;
    }
    if (t == 1) {
      int lca = LCA(u, v);
      if (v != lca && lca == u && sum[v] - sum[u] == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      int lca = LCA(u, v);
      if (v != lca && sum[v] - sum[lca] == dep[v] - dep[lca] && sum[u] - sum[lca] == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
