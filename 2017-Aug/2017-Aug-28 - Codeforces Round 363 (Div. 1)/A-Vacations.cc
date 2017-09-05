#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(3, inf));
  fill(dp[0].begin(), dp[0].end(), 0);
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (1 & t) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
    }
    if (2 & t) {
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    }
    dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
  }
  cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
  return 0;
}
