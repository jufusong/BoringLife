#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

vector<int> g[N], sp;
int dep[N], dfn[N], lg[2 * N];
pair<int, int> dp[21][2 * N];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  dfn[u] = sp.size();
  sp.push_back(u);
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      sp.push_back(u);
    }
  }
}

void lca_init() {
  int n = sp.size();
  for (int i = 1, j = 0; i <= n; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = {dfn[sp[i]], sp[i]};
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int lca(int u, int v) {
  int l = dfn[u], r = dfn[v];
  if (l > r) swap(l, r);
  int j = lg[r - l + 1];
  return min(dp[j][l], dp[j][r - (1 << j) + 1]).second;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  n++;
  vector<int> a(n + 1);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a[i]);
    g[a[i]].push_back(i);
  }
  dfs(1, 0);
  lca_init();
  set<int> s1, s2;
  s1.insert(1);

  auto dis = [](int u, int v) {
    return dep[u] + dep[v] - dep[lca(u, v)] * 2;
  };

  for (int i = 2, mx = 0; i <= n; i++) {
    int d1 = s1.empty() ? 0 : dis(i, *s1.begin());
    int d2 = s2.empty() ? 0 : dis(i, *s2.begin());
    if (max(d1, d2) > mx) {
      if (d1 >= d2) {
        for (auto u : s2) {
          if (dis(u, i) == d1) {
            s1.insert(u);
          }
        }
        s2 = set<int>{i};
      } else {
        for (auto u : s1) {
          if (dis(u, i) == d2) {
            s2.insert(u);
          }
        }
        s1 = set<int>{i};
      }
      mx = max(d1, d2);
    } else if (max(d1, d2) == mx) {
      d1 >= d2 ? s2.insert(i) : s1.insert(i);
    }
    printf("%d\n", (int)s1.size() + (int)s2.size());
  }
  return 0;
}
