#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

typedef long long ll;

vector<pair<int, int>> g[N];
vector<pair<pair<int, int>, int>> circle;
int vis[N], pre[N], prel[N], dep[N];
ll dp[N], mxx = 0;

void dfs1(int u, int fa, int d) {
  vis[u] = true;
  dep[u] = d;
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (v != fa) {
      if (vis[v]) {
        if (dep[v] < dep[u]) {
          circle.push_back({{v, u}, w});
          for (int now = u; now != v; now = pre[now]) {
            circle.push_back({{now, pre[now]}, prel[now]});
          }
        }
      } else {
        pre[v] = u, prel[v] = w;
        dfs1(v, u, d + 1);
      }
    }
  }
}

void dfs2(int u) {
  ll mx = 0;
  for (auto e : g[u]) {
    int v = e.first, w = e.second;
    if (!vis[v]) {
      vis[v] = true;
      dfs2(v);
      dp[u] = max(dp[u], dp[v] + w);
      mxx = max(mxx, mx + dp[v] + w);
      mx = max(mx, dp[v] + w);
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  vector<pair<int, int>> edges;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v, w = 1;
    cin >> u >> v;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges.emplace_back(u, v);
  }
  dfs1(1, -1, 0);
  memset(vis, 0, sizeof(vis));
  for (auto x : circle) {
    vis[x.first.first] = true;
  }
  for (auto x : circle) {
    dfs2(x.first.first);
  }
  ll mx = 0, md = 0;
  vector<ll> a(circle.size() + 1), b(circle.size() + 1);
  for (int i = 0; i < (int)circle.size(); i++) {
    a[i + 1] = max(a[i], dp[circle[i].first.first] + mx);
    b[i + 1] = max(b[i], dp[circle[i].first.first] + md);
    mx = max(mx, dp[circle[i].first.first]) + circle[i].second;
    md += circle[i].second;
  }
  mx = dp[circle[0].first.first];
  md = 0;
  ll px = 0, py = 0;
  ll ans = 1e18;
  map<pair<int, int>, ll> mp;
  for (int i = (int)circle.size() - 1; i >= 0; i--) {
    ans = max(a[i + 1], max(px, b[i + 1] + py));
    md += circle[i].second;
    mx += circle[i].second;
    mp[circle[i].first] = ans;
    px = max(px, dp[circle[i].first.first] + mx);
    py = max(py, dp[circle[i].first.first] + md);
    mx = max(mx, dp[circle[i].first.first]);
  }
  for (auto e : edges) {
    int u, v;
    tie(u, v) = e;
    if (mp.count({u, v})) {
      cout << max(mp[{u, v}], mxx) << endl;
    } else if (mp.count({v, u})) {
      cout << max(mp[{v, u}], mxx) << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
