#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 1e8;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  queue<pair<int, int>> q;
  vector<vector<int>> dis(n + 1, vector<int>(2, inf));
  vector<vector<bool>> vis(n + 1, vector<bool>(2));
  for (auto e : g[1]) {
    if (e.second == 0) {
      int v = e.first;
      dis[v][1] = 1;
      if (!vis[v][1]) {
        vis[v][1] = true;
        q.push({v, 1});
      }
    }
  }
  while (!q.empty()) {
    int u = q.front().first, x = q.front().second;
    q.pop();
    vis[u][x] = false;
    for (auto e : g[u]) {
      int v = e.first, c = e.second;
      int d = max(dis[u][x] + 1, c + (c % 2 == x ? 1 : 2));
      if (dis[v][d % 2] > d) {
        dis[v][d % 2] = d;
        if (!vis[v][d % 2]) {
          vis[v][d % 2] = true;
          q.push({v, d % 2});
        }
      }
    }
  }
  int ans = min(dis[n][0], dis[n][1]);
  cout << (ans == inf ? -1 : ans) << endl;
  return 0;
}
