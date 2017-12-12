#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200005;
const int mod = 1e9 + 7;
vector<long long> P2(N);


int inverse(int a, int md) {
  return a == 1 ? a : (long long)(md - md / a) * inverse(md % a, md) % md;
}

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
  
  long long f[N][2];
  bool leaf[N];
  
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
      f[v][0] = f[v][1] = 0;
      leaf[v] = false;
      ng[v].clear();
      // init data on Vertex V
      for (; !sd.empty() && !(st[sd.back()] <= st[v] && st[v] <= ed[sd.back()]); sd.pop_back());
      if (!sd.empty()) {
        ng[sd.back()].push_back(v);
      }
      sd.push_back(v);
    }
    for (auto x : vec) {
      leaf[x] = true;
    }
    return a[0];
  }

  void dfs1(int u) {
    if (leaf[u]) {
      f[u][0] = 1;
      f[u][1] = 1;
      return;
    }
    long long sum = 1;
    vector<pair<long long, long long>> vec(1, {1, 1});
    for (auto v : ng[u]) {
      dfs1(v);
      vec.push_back({f[v][0], f[v][1]});
    }
    auto v2 = vec;
    f[u][0] = 1;
    for (int i = 1; i < vec.size(); i++) {
      f[u][0] = f[u][0] * (vec[i].first + vec[i].second) % mod;
      vec[i].first = (vec[i].first * vec[i - 1].first) % mod;
    }
    long long now = 1;
    for (int i = vec.size() - 1; i >= 1; i--) {
      f[u][1] = (f[u][1] + v2[i].second * now % mod * vec[i - 1].first) % mod;
      now = (now * v2[i].first) % mod;
    }
    f[u][0] = (f[u][0] - f[u][1] + mod) % mod;
  }

  long long query(const vector<int> &vec) {
    int root = construct(vec);
    dfs1(root);
    return f[root][1];
  }

} // namespace AT

int main(int argc, char *argv[]) {
  P2[0] = 1;
  for (int i = 1; i < N; i++) {
    P2[i] = P2[i - 1] * 2 % mod;
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    g[p + 1].push_back(i + 1);
  }
  n++;
  AT::init();
  vector<vector<int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[AT::dep[i]].push_back(i);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i].empty()) {
      auto vec = a[i];
      long long v = AT::query(vec);
      ans = (ans + v * P2[n - a[i].size()]) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
