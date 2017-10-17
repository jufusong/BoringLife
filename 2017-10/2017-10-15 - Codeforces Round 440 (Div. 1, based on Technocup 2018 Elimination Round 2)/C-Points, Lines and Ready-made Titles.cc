#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

const int N = 200005;

vector<int> g[N], st;
int sta[N], dfn[N], low[N], lay, scc;

void dfs(int u, int fa) {
  sta[u] = 1;
  dfn[u] = low[u] = ++lay;
  st.push_back(u);
  for (auto v : g[u]) {
    if (v != fa) {
      if (sta[v] == 0) dfs(v, u);
      if (sta[v] == 1) low[u] = min(low[u], low[v]);
    }
  }
  if (low[u] == dfn[u]) {
    scc++;
    while (true) {
      int v = st.back();
      st.pop_back();
      low[v] = scc;
      sta[v] = 2;
      if (v == u) break;
    };
  }
}
int tarjan(int n) {
  for (int i = 1; i <= n; i++) {
    if (!sta[i])
      dfs(i, 0);
  }
  return scc;
}

bool ff;
int SS;

namespace gg {
  vector<int> g[N];
  int cnt[N];
  ll P2[N];
  bool vv[N];
  ll f[N][2];

  void dfs(int u, int fa) {
    vv[u] = true;
    SS += cnt[u] * 2;
    if (cnt[u] > 1) ff = true;
    for (auto v : g[u]) {
      if (v != fa) {
        dfs(v, u);
      }
    }
    ll S0 = 1, S1 = 1, S2 = 1;
    bool flag = true;
    for (auto v : g[u]) {
      if (v != fa) {
        S0 = S0 * f[v][0] % mod;
        S1 = S1 * f[v][1] % mod;
        S2 = S2 * (f[v][0] + f[v][1]) % mod;
        flag = false;
      }
    }
    if (flag) {
      f[u][0] = f[u][1] = 1;
    } else {
      f[u][0] = S2;
      f[u][1] = (S2 - S1 + mod) % mod;
    }
  }
}

int main(int argc, char *argv[]) {
  gg::P2[0] = 1;
  for (int i = 1; i < N; i++) {
    gg::P2[i] = gg::P2[i - 1] * 2 % mod;
  }
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> vx, vy;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
    vx.push_back(vec[i].first);
    vy.push_back(vec[i].second);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  int nx = vx.size(), ny = vy.size();
  for (auto e : vec) {
    int x = lower_bound(vx.begin(), vx.end(), e.first) - vx.begin() + 1;
    int y = lower_bound(vy.begin(), vy.end(), e.second) - vy.begin() + 1;
    g[x].push_back(y + nx);
    g[y + nx].push_back(x);
  }
  int dcc = tarjan(nx + ny);
  for (int i = 1; i <= nx + ny; i++) {
    gg::cnt[low[i]]++;
    for (auto v : g[i]) {
      if (low[i] != low[v]) {
        gg::g[low[i]].push_back(low[v]);
      }
    }
  }
  ll ans = 1;
  for (int i = 1; i <= dcc; i++) {
    if (!gg::vv[i]) {
      ff = false;
      SS = 0;
      gg::dfs(i, 0);
      if (SS == 4) {
        ans = ans * 3 % mod;
      } else {
        if (ff) {

          ans = ans * gg::P2[SS / 2] % mod;
        } else {
          ans = ans * (gg::P2[SS / 2] - 1)% mod;
        }

      }
      /*      if (ff) {
        
      } else {
      ans = ans * gg::P2[SS / 2] % mod;*/
        //        ans = ans * (gg::f[i][0] + gg::f[i][1]) % mod;
      //      }
    }
  }
  cout << ans << endl;
  return 0;
}
