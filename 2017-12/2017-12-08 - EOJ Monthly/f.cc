#include <bits/stdc++.h>

using namespace std;

vector<long long> P;
vector<vector<int>> g;
long long S;
vector<int> d;
vector<long long> ans, f;

void dfs1(int u, int fa) {
  d[u] = d[fa] + 1;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs1(v, u);
    }
  }
}

void dfs2(int u, int fa) {
  long long x = f[u];
  for (auto v : g[u]) {
    if (v != fa) {
      dfs2(v, u);
      x -= f[v];
    }
  }
  ans[u] = x;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  ans = f = P = vector<long long>(n + 1);
  g.resize(n + 1);
  d.resize(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &P[i]);
  }
  long long Z = (P[1] - P[g[1][0]]) % 2;
  long long low = 0, high = 1e12;
  auto cal = [&](long long mid) {
    long long S = mid * 2 + Z;
    dfs1(1, 0);
    for (int i = 1; i <= n; ++i) {
      for (auto j: g[i]) {
        int u = i, v = j;
        if (d[u] > d[v]) {
          swap(u, v);
        }
        f[v] = (S + P[u] - P[v]) / 2;
      }
    }
    f[1] = S;
    dfs2(1, 0);
  };
  while (low <= high) {
    long long mid = (low + high) / 2;
    cal(mid);
    long long v = 0;
    for (int i = 1; i <= n; i++) {
      v += (d[i] - 1) * ans[i];
    }
    if (v > P[1]) high = mid - 1;
    else low = mid + 1;
  }
  cal(high);
  for (int i = 1; i <= n; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
