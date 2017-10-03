#include <bits/stdc++.h>

using namespace std;

int b[305][10][305];
int lg[555];
int dp[305][2][2];

int main(int argc, char *argv[]) {
  for (int i = 1, j = 0; i <= 500; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  int n, m, P;
  while (~scanf("%d%d%d", &n, &m, &P)) {
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        a[i][j] += a[i - 1][j];
      }
    }
    for (int j = 1; j <= m; j++) {
      for (int i = 1; i <= n; i++) {
        b[j][0][i] = a[i][j] - a[i - 1][j];
      }
      for (int k = 1; (1 << k) <= n; k++) {
        for (int h = 1; h + (1 << k) - 1 <= n; h++) {
          b[j][k][h] = min(b[j][k - 1][h], b[j][k - 1][h + (1 << (k - 1))]);
        }
      }
    }
    auto query = [](int l, int r, int dp[][305]) {
      int j = lg[r - l + 1];
      return min(dp[j][l], dp[j][r - (1 << j) + 1]);
    };
    int mx = -1e9;
    for (int x = 1; x <= n; x++) {
      for (int y = x; y <= n; y++) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            dp[0][i][j] = -1e9;
          }
        }
        dp[0][0][1] = 0;

        for (int i = 1; i <= m; i++) {
          int v = a[y][i] - a[x - 1][i];
          int mn = query(x, y, b[i]);
          //        printf("%d %d %d %d %d\n", x, y, i, v, mn);
          dp[i][0][1] = dp[i - 1][0][1] + v;
          dp[i][1][1] = max(dp[i - 1][0][1] + v + P - mn, dp[i - 1][1][1] + v);
          if (i > 1) {
            dp[i][0][0] = max(v, dp[i - 1][0][0] + v);
            dp[i][1][0] = max(v + P - mn, max(dp[i - 1][1][0] + v, dp[i - 1][0][0] + v + P - mn));
          } else {
            dp[i][0][0] = dp[i][1][0] = -1e9;
          }
          //                  printf("%d %d %d %d\n", dp[i][0][1], dp[i][1][1], dp[i][0][0], dp[i][1][0]);
          mx = max(mx, dp[i][0][0]);
          mx = max(mx, dp[i][1][0]);
          mx = max(mx, dp[i][1][1]);
          if (x == 1 && y == n && i == m) {
            
          } else {
            mx = max(mx, dp[i][0][1]);
          }
        }
      }
    }
    cout << mx << endl;
  }
  return 0;
}
