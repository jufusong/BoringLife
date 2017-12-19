#include <vector>
#include <cstdio>

using namespace std;

struct Hungarian {
  vector<int> cx, cy;
  
  Hungarian(const vector<vector<int> >& g, int n, int m) : cx(n, -1), cy(m, -1) {
    for (int i = 0; i < n; i++) {
      if (cx[i] == -1) {
        vector<bool> vis(m, false);
        dfs(g, i, vis);
      }
    }
  }

  bool dfs(const vector<vector<int> >& g, int u, vector<bool>& vis) {
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (!vis[v]) {
        vis[v] = true;
        if (cy[v] == -1 || dfs(g, cy[v], vis)) {
          cx[u] = v, cy[v] = u;
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
      int k;
      scanf("%d", &k);
      for (int j = 0; j < k; ++j) {
        int v;
        scanf("%d", &v);
        g[i].push_back(v - 1);
      }
    }
    Hungarian hg(g, n, m);
    int cnt = 0;
    for (int i = 0; i < hg.cy.size(); i++) {
      cnt += (hg.cy[i] != -1);
    }
    printf("%d\n", cnt);
  }
  return 0;
}
