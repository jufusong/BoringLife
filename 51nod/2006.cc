#include <bits/stdc++.h>

using namespace std;

struct Hungrarian {
  vector<vector<int>> g;
  vector<int> match;
  vector<bool> vis;
  int n, m;
  Hungrarian(int n, int m, const vector<pair<int, int>> &edges = {}) : n(n), m(m) {
    g.assign(n + 1, {});
    match.assign(m + 1, -1);
    for (auto e : edges) {
      g[e.first].push_back(e.second);
    }
  }
  bool Find(int c) {
    if (match[c] == -1) return true;
    vis[c] = true;
    int u = match[c];
    for (auto v : g[u]) {
      if (!vis[v] && Find(v)) {
        match[v] = u;
        return true;
      }
    }
    return false;
  }
  int Run() {
    for (int u = 1; u <= n; u++) {
      vis.assign(m, false);
      for (auto v : g[u]) {
        if (Find(v)) {
          match[v] = u;
          break;
        }
      }
    }
    return m + 1 - count(match.begin(), match.end(), -1);
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  int u, v;
  while (cin >> u >> v, u != -1) {
    edges.push_back({u, v});
  }
  int mx = Hungrarian(n, m, edges).Run();
  mx == 0 ? cout << "No Solution!" : cout << mx;
  return 0;
}
