#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[a[i]] = i;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(27));
    for (int i = 1; i <= 26; i++) {
      dp[1][i] = dp[1][i - 1] + 1;
    }
    for (int i = 2; i <= n; i++) {
      int f = (a[i - 1] != n && (a[i] == n || b[a[i - 1] + 1] > b[a[i] + 1]));
      for (int j = 1; j <= 26; j++) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j - f];
      }
    }
    cout << dp[n][26] << endl;
  }
  return 0;
}
