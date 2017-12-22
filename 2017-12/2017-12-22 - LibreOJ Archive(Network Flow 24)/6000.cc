#include <bits/stdc++.h>

struct Hungarian {
  std::vector<int> cx, cy;
  Hungarian(const std::vector<std::vector<int>> &g, int n, int m) : cx(n, -1), cy(m, -1) {
    for (int i = 0; i < n; i++) {
      if (cx[i] == -1) {
        std::vector<bool> vis(m, false);
        dfs(g, i, vis);
      }
    }
  }
  bool dfs(const std::vector<std::vector<int>> &g, int u, std::vector<bool> &vis) {
    for (auto v : g[u]) {
      if (!vis[v]) {
        vis[v] = true;
        if (cy[v] == -1 || dfs(g, cy[v], vis)) {
          cx[u] = v, cy[v] = u;
          return true;
        }
      }
    }
    return false;
  }
};

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(m);
  for (int u, v; cin >> u >> v; ) {
    g[u - 1].push_back(v - m - 1);
  }
  Hungarian hg(g, m, n - m);
  int cnt = 0;
  for (auto x : hg.cy) {
    cnt += (x != -1);
  }
  cout << cnt << endl;
  return 0;
}
