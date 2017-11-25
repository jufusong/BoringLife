#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;
const int inf = 1e9;
const int mod = 1e9 + 7;

vector<int> g[N];
int sz[N], d[N], st[N], root, minn, top, K;
bool done[N];

void dfs1(int u, int fa, int n) {
  sz[u] = 1;
  int mx = 0;
  for (auto v : g[u]) {
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

void dfs2(int u, int fa) {
  st[top++] = u;
  d[u] = d[fa] + 1;
  for (auto v : g[u]) {
    if (v != fa && !done[v]) {
      dfs2(v, u);
    }
  }
}

ll cal(int l, int r) {
  ll ret = 0;
  unordered_map<int, int> mp;
  for (int i = l; i < r; i++) {
    ret = (ret + mp[K - d[st[i]]]) % mod;
    mp[d[st[i]]]++;
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
  for (auto v : g[u]) {
    if (!done[v]) {
      ans = (ans + solve(v, sz[v])) % mod;
    }
  }
  done[u] = false;
  st[0] = u;
  top = 1;
  d[u] = 0;
  for (auto v : g[u]) {
    if (!done[v]) {
      int pre = top;
      dfs2(v, u);
      ans = (ans - cal(pre, top) + mod) % mod;
    }
  }
  return (ans + cal(0, top)) % mod;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n >> K;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << solve(1, n) * ((ll)K * (K + 1) / 2 % mod) % mod<< endl;
  return 0;
}
