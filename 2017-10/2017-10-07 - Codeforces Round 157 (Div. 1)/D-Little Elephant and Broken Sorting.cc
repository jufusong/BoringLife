#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<double>> b(n + 1, vector<double>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      b[i][j] = (a[i] > a[j] ? 1 : 0);
    }
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    b[x][y] = b[y][x] = .5;
    for (int i = 1; i <= n; i++) {
      if (i != x && i != y) {
        b[x][i] = b[y][i] = (b[x][i] + b[y][i]) / 2;
        b[i][x] = b[i][y] = (b[i][x] + b[i][y]) / 2;
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += b[i][j];
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
