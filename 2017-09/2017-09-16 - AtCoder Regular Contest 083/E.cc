#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const int inf = 1e9;

vector<int> g[N];
int X[N], Y[N];
bool flag = true;

void dfs(int u) {
  vector<int> a(5001);
  for (auto v : g[u]) {
    dfs(v);
    vector<int> b(5001, inf);
    for (int i = 0; i <= 5000; i++) {
      if (i + X[v] <= 5000) b[i + X[v]] = min(b[i + X[v]], a[i] + Y[v]);
      if (i + Y[v] <= 5000) b[i + Y[v]] = min(b[i + Y[v]], a[i] + X[v]);
    }
    Y[u] = inf;
    for (int i = 0; i <= X[u]; i++) {
      Y[u] = min(Y[u], b[i]);
    }
    a = b;
  }
  if (Y[u] == inf) flag = false;
  //  cout << u <<  " " << X[u] << " " << Y[u] << endl;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    g[u].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> X[i];
  }
  dfs(1);
  cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}
