#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<vector<pair<int, int>>> g;
int a[N], d[N], ans;
int dp[2][N];

void dfs(int u, int fa, int dep) {
  d[u] = dep;
  dp[0][u] = dp[1][u] = a[u];
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (v != fa) {
      dfs(v, u, dep + w);
      dp[0][u] = max(dp[0][u], dp[0][v] - w);
      dp[1][u] = min(dp[1][u], dp[1][v] + w);
    }
  }
  ans = max(ans, dp[0][u] - dp[1][u]);
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    g.assign(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    dfs(1, -1, 0);
    cout << ans << endl;
  }
  return 0;
}
