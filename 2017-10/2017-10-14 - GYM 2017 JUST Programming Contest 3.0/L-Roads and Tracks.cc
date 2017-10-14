#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<ll>> f(n + 1, vector<ll>(m, 1e18));
    auto g = f;
    f[0][0] = g[0][0] = 0;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%lld", &a[i][j]);
      }
    }
    vector<vector<ll>> b(n, vector<ll>(m - 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        scanf("%lld", &b[i][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      vector<ll> c(m);
      for (int j = 1; j < m; j++) {
        c[j] = c[j - 1] + b[i - 1][j - 1];
      }
      for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          int tj = j, tk = k;
          if (f[i - 1][tj] < f[i - 1][tk]) swap(tj, tk);
          if (f[i - 1][tj] > f[i - 1][tk]) {
            f[i - 1][tj] = f[i - 1][tk];
            g[i - 1][tj] = g[i - 1][tk] + c[k] - c[j];
          } else {
            g[i - 1][tj] = min(g[i - 1][tj], g[i - 1][tk] + c[k] - c[j]);
            swap(tj, tk);
            g[i - 1][tj] = min(g[i - 1][tj], g[i - 1][tk] + c[k] - c[j]);
          }
        }
      }
      for (int j = 0; j < m; j++) {
        f[i][j] = f[i - 1][j] + a[i - 1][j];
        g[i][j] = g[i - 1][j];
      }
    }
    pair<ll, ll> ans = {1e18, 1e18};
    for (int i = 0; i < m; i++) {
      ans = min(ans, {f[n][i], g[n][i]});
    }
    printf("%lld %lld\n", ans.first, ans.second);
  }
  return 0;
}
