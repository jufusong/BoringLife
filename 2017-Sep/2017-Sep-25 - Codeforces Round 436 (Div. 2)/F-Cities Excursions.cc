#include <bits/stdc++.h>

using namespace std;

const int N = 3001;

vector<int> g[N], st;
int a[N], b[N][20], sta[N], lay, low[N], scc, dfn[N];

void init(int n)
{
  lay = scc = 0;
  memset(sta, 0, sizeof(sta));
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  st.clear ();
}

void dfs(int u, int fa, int dep)
{
  a[u] = dep;
  b[u][0] = fa;
  for (int i = 1; (1 << i) < dep; i++) {
    b[u][i] = b[b[u][i - 1]][i - 1];
  }
  sta[u] = 1;
  dfn[u] = low[u] = ++lay;
  st.push_back(u);
  bool flag = false;
  for (auto v : g[u]) {
    if (sta[v] == 0) {
      if (flag || dep == -1) {
        dfs(v, u, -1);
      } else {
        dfs(v, u, dep + 1);
      }
    }
    if (sta[v] == 1) {
      if (low[v] <= low[u]) {
        flag = true;
      }
      low[u] = min(low[u], low[v]); 
    }
  }
  if (low[u] == dfn[u]){
    scc ++;
    while (true) {
      int v = st.back();
      st.pop_back();
      low[v] = scc;
      sta[v] = 2;
      if (v == u) break;
    };
  }
}

int main(int argc, char *argv[]) {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }
  vector<tuple<int, int, int, int>> vec(1);
  for (int i = 0; i < q; i++) {
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    vec.push_back({s, t, k, i});
  }
  sort(vec.begin(), vec.end(), [](const tuple<int, int, int, int>& x, const tuple<int, int, int, int>& y) {
      return get<0>(x) < get<0>(y);
    });
  vector<int> ans(q);
  for (int i = 1; i <= q; i++) {
    if (get<0>(vec[i]) != get<0>(vec[i - 1])) {
      init(n);
      memset(a, 0, sizeof(a));
      int rt = get<0>(vec[i]);
      dfs(rt, 0, 1);
    }
    int t, k, id;
    tie(ignore, t, k, id) = vec[i];
    if (a[t] <= 0 || a[t] < k) {
      ans[id] = -1;
      //      cout << -1 << endl;
    } else {
      int d = a[t] - k;
      int x = t;
      for (int i = 20; i >= 0; i--) {
        if ((1 << i) <= d) {
          x = b[x][i];
          d -= (1 << i);
        }
      }
      ans[id] = x;
    }
  }
  for (auto x : ans) {
    printf("%d\n", x);
  }
  return 0;
}
