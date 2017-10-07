#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N * 4], b[N * 4], c[N * 4];

void pushdown(int p, int l, int r) {
  int m = (l + r) / 2;
  a[p * 2] += c[p];
  a[p * 2 + 1] += c[p];
  c[p * 2] += c[p];
  c[p * 2 + 1] += c[p];
  c[p] = 0;
}

void pushup(int p) {
  a[p] = min(a[p * 2], a[p * 2 + 1]);
  b[p] = (a[p] == a[p * 2] ? b[p * 2] : 0) + (a[p] == a[p * 2 + 1] ? b[p * 2 + 1] : 0);
}

void build(int l, int r, int p) {
  if (l == r) {
    b[p] = 1;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, p * 2);
  build(m + 1, r, p * 2 + 1);
  pushup(p);
}

void update(int l, int r, int p, int L, int R, int val) {
  if (l >= L && r <= R) {
    a[p] += val;
    c[p] += val;
    return;
  }
  pushdown(p, l, r);
  int m = (l + r) / 2;
  if (m >= L) update(l, m, p * 2, L, R, val);
  if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
  pushup(p);
}

int lay = 0, st[N], ed[N], n, ans[N];
vector<int> g[N], h[N];

int dfs1(int u, int fa) {
  st[u] = ++lay;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs1(v, u);
    }
  }
  ed[u] = lay;
}

void dfs2(int u, int fa) {
  for (auto v : h[u]) {
    update(1, n, 1, st[v], ed[v], 1);
  }
  if (a[1]) ans[u] = n;
  else ans[u] = n - b[1];
  for (auto v : g[u]) {
    if (v != fa) {
      dfs2(v, u);
    }
  }
  for (auto v : h[u]) {
    update(1, n, 1, st[v], ed[v], -1);
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int m;
  cin >> n >> m;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    h[x].push_back(y);
    h[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!h[i].empty()) h[i].push_back(i);
  }
  build(1, n, 1);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << (ans[i] > 0 ? ans[i] - 1 : 0)<< " ";
  }
  return 0;
}
