#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;

vector<int> g[N], a(N, -1);
bool flag = true;

int dfs(int u, int fa) {
  for (auto v : g[u]) {
    if (v != fa) {
      if (a[v] == -1) {
        a[v] = (a[u] ^ 1);
        dfs(v, u);
      } else {
        flag &= (a[v] ^ a[u]);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  a[1] = 0;
  dfs(1, 0);
  if (!flag) {
    cout << (ll)n * (n - 1) / 2 - m << endl;
  } else {
    int cx = 0;
    for (int i = 1; i <= n; i++) {
      cx += a[i];
    }
    cout << (ll)cx * (n - cx) - m << endl;
  }
  return 0;
}
