#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

const int N = 100005;

vector<int> g[N];
ll dp[2][N], ans = 0;
int sz[N];

ll powMod(ll n, ll m, ll mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = multiplyMod(n, n, mod)) {
    if (m & 1)
      ans = multiplyMod(ans, n, mod);
  }
  return ans;
}

void dfs1(int u, int fa) {
  dp[0][u] = dp[1][u] = 1;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs1(v, u);
      dp[0][u] = dp[0][u] * (dp[0][v] + dp[1][v]) % mod;
      dp[1][u] = dp[1][u] * (dp[1][v] + dp[0][v]) % mod;
      sz[u] += sz[v];
    }
  }
  if (sz[u] == 1) {
    dp[1][u] = 0;
  }
}

void dfs2(int u, int fa, ll v1, ll v2) {
  ll x = dp[0][u] * (v1 + v2) % mod, y = dp[1][u] * (v1 + v2) % mod;
  ans = (ans + x + y) % mod;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs2(v, u, x * powMod(dp[0][v], mod - 2, mod) % mod, y * powMod(dp[1][v]))
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, -1);
  dfs2(1, -1, 1, 1);
  cout << ans << endl;
  return 0;
}
