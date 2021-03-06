#include <bits/stdc++.h>

struct Tarjan {
  const std::vector<std::vector<int>> &g;
  std::vector<int> st, sta, dfn, low;
  int n, scc, lay;

  Tarjan(const std::vector<std::vector<int>> &graph, int base = 1) : g(graph) {
    n = (int)g.size();
    scc = lay = 0;
    sta = dfn = low = std::vector<int>(n);
    for (int i = base; i < n; i++) if (!sta[i]) dfs(i);
  }

  void dfs(int u) {
    sta[u] = 1;
    dfn[u] = low[u] = ++lay;
    st.push_back(u);
    for (auto v : g[u]) {
      if (sta[v] == 0) dfs(v);
      if (sta[v] == 1) low[u] = std::min(low[u], low[v]);
    }
    if (low[u] == dfn[u]) {
      scc++;
      while (true) {
        int v = st.back();
        st.pop_back();
        low[v] = scc;
        sta[v] = 2;
        if (v == u) break;
      }
    }
  }
};

using namespace std;
const int N = 2005;
vector<vector<int>> g;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int t;
      cin >> t;
      if (t) g[i].push_back(j);
    }
  }
  puts(Tarjan(g).scc == 1 ? "YES" : "NO");
  return 0;
}
