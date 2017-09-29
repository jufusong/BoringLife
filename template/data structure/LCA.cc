#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> g[N];

namespace LCA {
  vector<int> sp;
  int dep[N], dfn[N], lg[2 * N];
  pair<int, int> dp[21][2 * N];

  void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u);
        sp.push_back(u);
      }
    }
  }

  void init() {
    dfs(1, 0);
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
}
