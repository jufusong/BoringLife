#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<vector<pair<int, int>>> g;
vector<int> a;

int dfs(int u) {
  if (a[u] == -1) {
    a[u] = 0;
    for (auto e : g[u]) {
      a[u] = max(a[u], dfs(e.first) + e.second);
    }
  }
  return a[u];
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<pair<int, int>>());
    a.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[v].push_back({u, w});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dfs(i));
    }
    cout << ans << endl;
  }
  return 0;
}
