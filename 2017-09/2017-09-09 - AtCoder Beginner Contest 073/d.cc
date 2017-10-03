#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> a(r);
  for (int i = 0; i < r; i++) {
    cin >> a[i];
  }
  vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = d[v][u] = min(d[v][u], w);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  vector<int> p;
  for (int i = 0; i < r; i++) {
    p.push_back(i);
  }
  int ans = inf;
  do{
    int sum = 0;
    for (int i = 1; i < r; i++) {
      sum += d[a[p[i]]][a[p[i - 1]]];
    }
    ans = min(ans, sum);
  }while(next_permutation(p.begin(), p.end()));
  cout << ans << endl;
  return 0;
}
