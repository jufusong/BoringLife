#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  vector<vector<int>> g(n + 1);
  set<pair<int, int>> se;
  for (int u = 1; u <= n; u++) {
    int l;
    cin >> l;
    while (l--) {
      int v;
      cin >> v;
      g[u].push_back(v);
    }
    reverse(g[u].begin(), g[u].end());
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!g[u].empty()) {
      int v = g[u].back();
      if (v == u || g[v].empty() || g[v].back() != u || se.count({u, v})) {
        continue;
      }
      g[v].pop_back();
      g[u].pop_back();
      se.insert({u, v});
      vec.push_back({u, v});
      q.push(u);
      q.push(v);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!g[i].empty()) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (auto e : vec) {
    cout << e.first << " " << e.second << endl;
  }
  return 0;
}
