#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<double>> a(1 << n, vector<double>(1 << n));
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      cin >> a[i][j];
      a[i][j] /= 100;
    }
  }
  vector<vector<double>> dp(n + 1, vector<double>(1 << n));
  auto b = dp;
  for (int i = 0; i < (1 << n); i++) {
    dp[0][i] = 1.0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      for (int k = 0; k < (1 << n); k++) {
        if ((k >> (i - 1)) != (j >> (i - 1)) && (k >> i) == (j >> i)) {
          dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * a[j][k];
        }
      }
      b[i][j] = b[i - 1][j] + dp[i][j] * (1 << (i - 1));
    }
  }
  double ans = 0;
  set<int> se;
  for (int i = n, j = 1; i >= 1; i--, j *= 2) {
    vector<int> c;
    for (int k = 0; k < (1 << n); k++) {
      if (!se.count(k)) c.push_back(k);
    }
    sort(c.begin(), c.end(), [&b, &i](int x, int y) {
        return b[i][x] < b[i][y];
      });
  }
  return 0;
}
