#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 100005;

vector<int> g[N];
ll dp[N][11][3];
ll M, inv;
int X, K;

ll powMod(ll n, ll m, ll mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = n * n % mod) {
    if (m & 1) ans = ans * n % mod;
  }
  return ans;
}

void dfs(int u, int fa) {
  dp[u][0][0] = 1;
  dp[u][1][1] = 1;
  dp[u][1][2] = 0;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      vector<vector<ll>> a(11, vector<ll>(3));
      for (int i = 0; i <= X; i++) {
        for (int j = 0; j + i <= X; j++) {
          a[i + j][0] = (a[i + j][0] + dp[u][i][0] * (dp[v][j][0] + dp[v][j][2])) % mod;
          a[i + j][1] = (a[i + j][1] + dp[u][i][1] * (dp[v][j][2] + dp[v][j][0] * inv % mod * (K - 1) % mod)) % mod;
          a[i + j][2] = (a[i + j][2] + dp[u][i][2] * (dp[v][j][0] + dp[v][j][1] + dp[v][j][2]) + dp[u][i][0] * dp[v][j][1] % mod * (K - 1)) % mod;
        }
      }
      for (int i = 0; i <= X; i++) {
        for (int j = 0; j < 3; j++) {
          dp[u][i][j] = a[i][j];
        }
      }
    }
  }
  for (int i = 0; i <= X; i++) {
    dp[u][i][0] = dp[u][i][0] * (M - 1) % mod;
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n >> M;
  inv = powMod(M - 1, mod - 2, mod);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> K >> X;
  dfs(1, 0);
  ll ans = 0;
  for (int i = 0; i <= X; i++) {
    for (int j = 0; j < 3; j++) {
      ans = (ans + dp[1][i][j]) % mod;
      //      cout << dp[1][i][j] << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
