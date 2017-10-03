#include <bits/stdc++.h>

using namespace std;

const double inf = 1e16;

int main(int argc, char *argv[]) {
  double A, B;
  cin >> A >> B;
  vector<vector<double>> a;
  string s;
  getline(cin, s);
  while (getline(cin, s)) {
    vector<double> b;
    stringstream ss(s);
    double t;
    while (ss >> t) {
      b.push_back(t);
    }
    a.push_back(b);
  }
  int n = a.size(), m = a[0].size();
  vector<vector<double>> dp(n + 1, vector<double>(m + 1, inf));
  vector<vector<pair<int, int>>> pre(n + 1, vector<pair<int, int>>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) {
        dp[i][j] = a[i - 1][j - 1];
      } else {
        auto update = [&pre, &dp](double v, int x, int y, int px, int py) {
          if (v < dp[x][y]) {
            dp[x][y] = v;
            pre[x][y] = {px, py};
          }
        };
        if (i >= 3 && j >= 2) {
          double v = dp[i - 2][j - 1] + A * (a[i - 2][j - 1] + a[i - 1][j - 1]);
          update(v, i, j, i - 2, j - 1);
        }
        if (i >= 2 && j >= 2) {
          double v = dp[i - 1][j - 1] + B * a[i - 1][j - 1];
          update(v, i, j, i - 1, j - 1);
        }
        if (i >= 2 && j >= 3) {
          double v = dp[i - 1][j - 2] + A * (a[i - 1][j - 2] + a[i - 1][j - 1]);
          update(v, i, j, i - 1, j - 2);
        }
      }
    }
  }
  printf("%.6f\n", dp[n][m]);
  vector<pair<int, int>> ans;
  int tx = n, ty = m;
  while (tx != 1 || ty != 1) {
    ans.push_back({tx, ty});
    auto zx = pre[tx][ty];
    tx = zx.first, ty = zx.second;
  }
  ans.push_back({1, 1});
  for (int i = (int)ans.size() - 1; i >= 0; i--) {
    int tx = ans[i].second, ty = ans[i].first;
    if (i != (int)ans.size() - 1) {
      int zx = ans[i + 1].second, zy = ans[i + 1].first;
      if (tx - zx == 2) {
        printf("(%d,%d)\n", tx - 1, ty);
      } else if (ty - zy == 2) {
        printf("(%d,%d)\n", tx, ty - 1);
      }
    }
    printf("(%d,%d)\n", ans[i].second, ans[i].first);
  }
  return 0;
}
