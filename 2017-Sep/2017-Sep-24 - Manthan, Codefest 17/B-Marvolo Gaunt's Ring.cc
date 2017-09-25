#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 4e18;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  ll P, Q, R;
  cin >> n >> P >> Q >> R;
  vector<vector<ll>> dp(n + 1, vector<ll>(3, -inf));
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(P * a[i], dp[i - 1][0]);;
    dp[i][1] = max(Q * a[i] + dp[i][0], dp[i - 1][1]);
    dp[i][2] = max(R * a[i] + dp[i][1], dp[i - 1][2]);
  }
  cout << dp[n][2] << endl;
  return 0;
}
