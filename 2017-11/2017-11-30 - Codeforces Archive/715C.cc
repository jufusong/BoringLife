#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;
const int inf = 1e9;

vector<pair<int, int>> g[N];
int sz[N], d[N], st[N], root, minn, top;
bool done[N];

int V1[N], V2[N], p10[N];
int mod;

inline int inverse(int a, int mod) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

void dfs1(int u, int fa, int n) {
  sz[u] = 1;
  int mx = 0;
  for (auto e : g[u]) {
    int v = e.first;
    if (v != fa && !done[v]) {
      dfs1(v, u, n);
      sz[u] += sz[v];
      mx = max(mx, sz[v]);
    }
  }
  mx = max(mx, n - sz[u]);
  if (mx < minn) {
    minn = mx;
    root = u;
  }
}

void dfs2(int u, int fa, int x) {
  st[top++] = u;
  d[u] = d[fa] + 1;
  V1[u] = (V1[fa] * 10LL + x) % mod;
  V2[u] = (V2[fa] + (ll)x * p10[d[u] - 1]) % mod;
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (v != fa && !done[v]) {
      dfs2(v, u, w);
    }
  }
}

ll cal(int l, int r) {
  map<int, int> mp;
  for (int i = l; i < r; i++) {
    mp[V2[st[i]]]++;
  }
  ll ret = 0;
  for (int i = l; i < r; i++) {
    int v = st[i];
    ret += mp[(-(ll)V1[v] * inverse(p10[d[v]], mod) % mod + mod) % mod];
  }
  return ret;
}

ll solve(int u, int n) {
  minn = inf;
  dfs1(u, -1, n);
  u = root;
  dfs1(u, -1, n);
  done[u] = true;
  ll ans = 0;
  for (auto e : g[u]) {
    int v = e.first;
    if (!done[v]) {
      ans += solve(v, sz[v]);
    }
  }
  done[u] = false;
  st[0] = u;
  top = 1;
  d[u] = 0;
  V1[u] = V2[u] = 0;
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (!done[v]) {
      int pre = top;
      dfs2(v, u, w);
      ans -= cal(pre, top);
    }
  }
  return ans + cal(0, top);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n >> mod;
  p10[0] = 1;
  for (int i = 1; i < N; i++) {
    p10[i] = (ll)p10[i - 1] * 10 % mod;
  }
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  cout << solve(1, n) - n << endl;
  return 0;
}
