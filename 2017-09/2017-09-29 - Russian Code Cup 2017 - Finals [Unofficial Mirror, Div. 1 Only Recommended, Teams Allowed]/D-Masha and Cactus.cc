#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

vector<int> g[N];
int L[N], R[N];

namespace fw {
  int in[N * 2];

  int lowbit(int n) {return n & (-n);}

  void update(int p, int val) {
    for (int i = p; i < N * 2; i += lowbit(i)) {
      in[i] += val;
    }
  }

  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
}

namespace LCA {
  vector<int> sp;
  int dep[N], dfn[N], lg[2 * N], lay = 0;
  pair<int, int> dp[21][2 * N];

  void dfs(int u, int fa) {
    L[u] = ++lay;
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u);
        sp.push_back(u);
      }
    }
    R[u] = ++lay;
  }

  void init() {
    dfs(1, 0);
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

  int LCA(int u, int v) {
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int j = lg[r - l + 1];
    return min(dp[j][l], dp[j][r - (1 << j) + 1]).second;
  }
}

vector<tuple<int, int, int>> a[N];
int f[N][2];

void dfs(int u) {
  for (auto v : g[u]) {
    dfs(v);
    f[u][0] += f[v][1];
  }
  f[u][1] = f[u][0];
  for (auto e : a[u]) {
    int x, y, w;
    tie(x, y, w) = e;
    auto solve = [&u](int k) {
      if (k == u) return 0;
      return fw::query(L[k]) - fw::query(L[u]);
    };
    f[u][1] = max(f[u][1], w + f[u][0] + solve(x) + solve(y));
  }
  fw::update(L[u], f[u][0] - f[u][1]);
  fw::update(R[u] + 1, f[u][1] - f[u][0]);
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 2, u; i <= n; i++) {
    cin >> u;
    g[u].push_back(i);
  }
  LCA::init();
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[LCA::LCA(u, v)].push_back({u, v, w});
  }
  dfs(1);
  cout << f[1][1] << endl;
  return 0;
}
