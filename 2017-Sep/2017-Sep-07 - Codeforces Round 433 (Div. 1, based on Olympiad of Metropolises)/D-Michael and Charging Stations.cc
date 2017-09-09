#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(50, inf));
  dp[0][0] = 0;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    t /= 100;
    for (int j = 0; j < 50; j++) {
      if (j + t / 10 < 50) {
        dp[i + 1][j + t / 10] = min(dp[i + 1][j + t / 10], dp[i][j] + t);
      }
      int tx = max(0, j - t);
      int ty = t - (j - tx);
      dp[i + 1][tx] = min(dp[i + 1][tx], dp[i][j] + ty);
    }
  }
  int ans = inf;
  for (int i = 0; i < 50; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans * 100 << endl;
  return 0;
}
