#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500005;

vector<int> g[N];

namespace AT {
  vector<int> sp, ng[N];
  int dep[N], dfn[N], lg[2 * N], st[N], ed[N], stamp = 0;
  pair<int, int> dp[21][2 * N];

  void dfs(int u, int fa) {
    st[u] = ++stamp;
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u);
        sp.push_back(u);
      }
    }
    ed[u] = ++stamp;
  }

  void init(int root = 1) {
    dfs(root, 0);
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

  int d1[N];
  ll d2[N];

  int construct(const vector<int> &vec) {
    vector<int> a = vec;
    auto cmp = [](int u, int v) { return st[u] < st[v]; };
    sort(a.begin(), a.end(), cmp);
    for (int i = 1; i < (int)vec.size(); i++) {
      a.push_back(LCA(a[i], a[i - 1]));
    }
    sort(a.begin(), a.end(), cmp);
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> sd;
    for (auto v : a) {
      // init data on Vertex V
      ng[v].clear();
      d1[v] = d2[v] = 0;
      // init data on Vertex V
      for (; !sd.empty() && !(st[sd.back()] <= st[v] && st[v] <= ed[sd.back()]); sd.pop_back());
      if (!sd.empty()) {
        ng[sd.back()].push_back(v);
      }
      sd.push_back(v);
    }
    return a[0];
  }

  int dfs1(int u) {
    if (ng[u].empty()) d1[u] = 1;
    for (auto v : ng[u]) {
      d1[u] += dfs1(v);
    }
    return d1[u];
  }

  void dfs2(int u, int d, ll val) {
    val += (ll)(dep[u] - d - ng[u].empty()) * d1[u];
    d2[u] = val;
    for (auto v : ng[u]) {
      dfs2(v, dep[u], val);
    }
  }

  void query(const vector<int> &vec) {
    int root = construct(vec);
    dfs1(root);
    dfs2(root, 0, 0);
  }

} // namespace AT

int dep[N];
ll ans[N];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, root;
  cin >> n;
  vector<int> fa(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> fa[i];
    if (fa[i]) g[fa[i]].push_back(i);
    else root = i;
  }
  AT::init(root);
  dfs(root, 0);
  vector<vector<int>> vec(n + 1);
  for (int i = 1; i <= n; i++) {
    vec[dep[i]].push_back(i);
  }
  for (int i = 1; i <= n && !vec[i].empty(); i++) {
    AT::query(vec[i]);
    for (auto v : vec[i]) {
      ans[v] = AT::d2[v] + ans[fa[v]];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
