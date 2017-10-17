#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> g[N];
int Z[N];
bool vis[N];

void update(int p, int val) {
  if (Z[p] != -1 && Z[p] != val) {
    cout << "No" << endl;
    exit(0);
  }
  Z[p] = val;
}

void dfs(int u) {
  for (auto v : g[u]) {
    if (!vis[v]) {
      vis[v] = true;
      update(v, 1);
      dfs(v);
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  memset(Z, -1, sizeof(Z));
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int len;
    cin >> len;
    a[i].resize(len);
    for (int j = 0; j < len; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < min(a[i].size(), a[i - 1].size()); j++) {
      if (a[i][j] != a[i - 1][j]) {
        if (a[i][j] > a[i - 1][j]) {
          g[a[i][j]].push_back(a[i - 1][j]);
        } else {
          update(a[i - 1][j], 1);
          update(a[i][j], 0);
        }
        flag = true;
        break;
      }
    }
    if (!flag && a[i].size() < a[i - 1].size()) {
      cout << "No" << endl;
      exit(0);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (Z[i] == 1 && !vis[i]) {
      vis[i] = true;
      dfs(i);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    cnt += (Z[i] == 1);
  }
  cout << "Yes" << endl;
  cout << cnt << endl;
  for (int i = 1; i <= m; i++) {
    if (Z[i] == 1) {
      cout << i << " " ;
    }
  }
  return 0;
}
