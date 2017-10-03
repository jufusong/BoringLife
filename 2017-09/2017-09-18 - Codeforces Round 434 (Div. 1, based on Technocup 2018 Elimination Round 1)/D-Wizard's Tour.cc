#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

vector<int> g[N];
vector<tuple<int, int, int>> vec;
int dep[N];
bool vis[N];

int dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  vis[u] = true;
  vector<int> a;
  for (auto v : g[u]) {
    if (v != fa) {
      if (vis[v]) {
        if (dep[v] < dep[u]) {
          a.push_back(v);
        }
      } else if (dfs(v, u)) {
        a.push_back(v);
      }
    }
  }
  while ((int)a.size() >= 2) {
    vec.push_back({a.back(), u, a[(int)a.size() - 2]});
    a.pop_back(), a.pop_back();
  }
  if (a.empty()) return 1;
  if (fa != 0) vec.push_back({a[0], u, fa});
  return 0;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  cout << vec.size() << endl;
  for (auto e : vec) {
    int x, y, z;
    tie(x, y, z) = e;
    cout << x << " " << y << " " << z << endl;
  }
  return 0;
}
