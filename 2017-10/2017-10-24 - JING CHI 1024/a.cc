#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, m1, m2, L;
    cin >> n >> m1 >> m2 >> L;
    vector<vector<int>> g1(n + 1);
    vector<vector<pair<int, int>>> g2(n + 1);
    for (auto i = 0; i < m1; ++i) {
      int u, v;
      cin >> u >> v;
      g1[u].push_back(v);
      g1[v].push_back(u);
    }
    for (auto i = 0; i < m2; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      g2[u].push_back({v, w});
      g2[v].push_back({u, w});
    }
    vector<vector<int>> f(n + 1, vector<int>(m1 + 1, inf));
    vector<vector<bool>> vis(n + 1, vector<bool>(m1 + 1));
    f[1][0] = 0;
    vis[1][0] = false;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty()) {
      int u, y;
      tie(u, y) = q.front();
      vis[u][y] = false;
      q.pop();
      if (y < m1) {
        for (auto v : g1[u]) {
          if (f[v][y + 1] > f[u][y] + 1) {
            f[v][y + 1] = f[u][y] + 1;
            if (!vis[v][y + 1]) {
              vis[v][y + 1] = true;
              q.push({v, y + 1});
            }
          }
        }
      }
      for (auto e : g2[u]) {
        int v = e.first, w = e.second;
        if (f[v][y] > f[u][y] + w) {
          f[v][y] = f[u][y] + w;
          if (!vis[v][y]) {
            vis[v][y] = true;
            q.push({v, y});
          }
        }
      }
    }
    int ans = inf;
    for (int i = 0; i <= m1; i++) {
      if (f[n][i] <= L) {
        ans = min(ans, f[n][i] - i);
      }
    }
    cout << (ans == inf ? -1 : ans) << endl;
  }
  return 0;
}
