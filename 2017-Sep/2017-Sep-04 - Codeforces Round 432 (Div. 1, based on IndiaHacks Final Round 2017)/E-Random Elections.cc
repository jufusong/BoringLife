#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll dp[1<<20][21], ans = 0;

void update(ll x, int k) {
  ans = (ans + x * (1LL << k)) % mod;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (s[i] == '1') {
      dp[i][0] = 1;
      update(dp[i][0], n);
    }
  }
  auto add = [](ll& x, ll y) {
    x = (x + y) % mod;
    if (x < 0) x += mod;
  };
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < (1 << n); i++) {
      if (s[i] == '1') {
        for (int k = 0; k < n; k++) {
          int t = (i ^ (1 << k));
          add(dp[i][j], dp[t][j - 1]);

        }
                  if (j >= 2) {
            add(dp[i][j], -dp[i][j - 2]);
          }
        if (j == 2) cout << i << " " << dp[i][j] << endl;
        update(dp[i][j], n - j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
