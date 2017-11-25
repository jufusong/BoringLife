#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int inf = 1e9 + 5;

template<class T>
struct RMQ {
  vector<vector<T>> f;
  vector<int> lg;

  void init(const vector<T>& a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  
  T query(int l, int r) {
    if (f.size() == 0 || l > r) return inf;
    int j = lg[r - l + 1];
    return min(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

vector<int> g[N];
int root, st[N], ed[N], stamp, dep[N], vv[N];
vector<int> tz[N], tp[N], tu[N];

void dfs(int u, int fa) {
  st[u] = ++stamp;
  dep[u] = dep[fa] + 1;
  tu[dep[u]].push_back(u);
  tz[dep[u]].push_back(vv[u]);
  tp[dep[u]].push_back(st[u]);
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);      
    }
  }
  ed[u] = stamp;
}

RMQ<int> layer[N][22];

int query(int u, int lay, int m) {
  int idx = lower_bound(tp[lay].begin(), tp[lay].end(), st[u]) - tp[lay].begin();
  int idy = upper_bound(tp[lay].begin(), tp[lay].end(), ed[u]) - tp[lay].begin();
  //  cout << layer[lay][m].query(idx, idy - 1) << " " << u << " " << lay << " " << m << " " << idx << " " << idy << endl;
  return layer[lay][m].query(idx, idy - 1);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d%d", &n, &root);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &vv[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(root, 0);
  for (int i = n; i >= 1; i--) {
    layer[i][0].init(tz[i]);
    for (int j = 1; j <= 20; j++) {
      if (i + (1 << max(0, j - 2)) > n) {
        layer[i][j] = layer[i][j - 1];
        continue;
      }
      vector<int> vec = layer[i][j - 1].f[0];
      for (int k = 0; k < tz[i].size(); k++) {
        int u = tu[i][k];
        int nx = (i + (1 << (j - 1)));
        if (j >= 2) nx = i + (1 << (j - 2));
        vec[k] = min(vec[k], query(u, nx, j - 1));
      }
      layer[i][j].init(vec);
    }
  }
  int last = 0, T;
  scanf("%d", &T);
  while (T--) {
    int p, q;
    scanf("%d%d", &p, &q);
    int x = (p + last) % n + 1;
    int k = (q + last) % n;
    last = vv[x];
    for (int i = 20, now = dep[x]; i >= 0 && now <= n; i--) {
      if ((1 << i) <= k) {
        k -= (1 << i);
        last = min(last, query(x, now, i + 1));
        now += (1 << i);
      }
    }
    printf("%d\n", last);
  }
  return 0;
}
