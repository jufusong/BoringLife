#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll f[2][2001][11], g[2][2001][11];

ll powMod(ll n, ll m, ll mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = n * n % mod) {
    if (m & 1) ans = ans * n % mod;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  vector<ll> J(2001, 1);
  for (int i = 1; i <= 2000; i++) {
    J[i] = (J[i - 1] * i) % mod;
  }
  int T;
  cin >> T;
  while (T--) {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[0][0][0] = 1;
    int n;
    cin >> n;
    vector<ll> v1, v2;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      if (to_string(v).size() % 2) {
        v1.push_back(v);
      } else {
        v2.push_back(v);
      }
    }
    int n1 = v1.size();
    int now = 0;
    for (int i = 0; i < n1; i++) {
      ll v = v1[i];
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k < 11; k++) {
          int tk = (k + v) % 11;
          f[now ^ 1][j + 1][tk] = (f[now ^ 1][j + 1][tk] + f[now][j][k]) % mod;
          tk = (k + v * 10) % 11;
          f[now ^ 1][j][tk] = (f[now ^ 1][j][tk] + f[now][j][k]) % mod;
        }
      }
      memset(f[now], 0, sizeof(f[now]));
      now ^= 1;
    }
    for (int i = 0; i < 11; i++) {
      g[0][0][i] = f[now][n1 - n1 / 2][i] * J[n1 / 2] % mod * J[n1 - n1 / 2] % mod;
    }
    now = 0;
    for (int i = 0; i < (int)v2.size(); i++) {
      ll v = v2[i];
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k < 11; k++) {
          int tk = (k + v) % 11;
          int x = (n1 + 1) / 2, y = n1 + 1 - x;
          x += (i - j);
          y += j;
          g[now ^ 1][j + 1][tk] = (g[now ^ 1][j + 1][tk] + g[now][j][k] * y) % mod;
          tk = (k + v * 10) % 11;
          g[now ^ 1][j][tk] = (g[now ^ 1][j][tk] + g[now][j][k] * x) % mod;
        }
      }
      memset(g[now], 0, sizeof(g[now]));
      now ^= 1;
    }
    ll ans = 0;
    for (int i = 0; i <= 2000; i++) {
      ans = (ans + g[now][i][0]) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
