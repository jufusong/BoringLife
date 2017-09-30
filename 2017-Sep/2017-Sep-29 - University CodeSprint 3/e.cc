#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> g[N];
int a[N], dep[N];
int f[N][2];

int mx = 0, pu = -1, pd = -1;

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      f[u][0] += max(0, f[v][0]);
      f[u][1] += max(0, f[v][1]);
    }
  }
  if (a[u] == 0) {
    f[u][0]++, f[u][1]--;
  } else {
    f[u][1]++, f[u][0]--;
  }
  for (int i = 0; i < 2; i++) {
    if (f[u][i] > mx) {
      mx = f[u][i];
      pu = u, pd = i;
    }
  }
}

vector<int> ans;

void dfs2(int u, int d) {
  ans.push_back(u);
  for (auto v : g[u]) {
    if (dep[v] > dep[u] && f[v][d] > 0) {
      dfs2(v, d);
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << mx << endl;
  dfs2(pu, pd);
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}
