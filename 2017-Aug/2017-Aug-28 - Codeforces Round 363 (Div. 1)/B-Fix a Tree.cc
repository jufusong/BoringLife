#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int a[N], b[N], vis[N], root = -1;
vector<int> g[N];

void dfs(int u, int k) {
  vis[u] = k;
  for (auto v : g[u]) {
    if (vis[v] == k) {
      if (root == -1) root = v;
      a[v] = root;
    } else if (!vis[v]){
      dfs(v, k);
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    g[a[i]].push_back(i);
    if (a[i] == i) root = i;
  }
  for (int i = 1, k = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, k++);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (a[i] != b[i]);
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
