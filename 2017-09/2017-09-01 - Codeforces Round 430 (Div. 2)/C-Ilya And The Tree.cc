#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

vector<int> g[N];
int a[N], b[N];

void dfs(int u, int fa, const vector<int>& vec) {
  vector<int> ns;
  if (u == 1) {
    ns.push_back(a[u]);
  } else if (fa == 1) {
    ns.push_back(a[u]);
    ns.push_back(__gcd(vec[0], a[u]));
    ns.push_back(vec[0]);
  } else {
    ns.push_back(__gcd(vec[0], a[u]));
    ns.push_back(vec[0]);
    for (int i = 1; i < (int)vec.size(); i++) {
      ns.push_back(__gcd(a[u], vec[i]));
    }
  }
  sort(ns.begin(), ns.end());
  ns.erase(unique(ns.begin(), ns.end()), ns.end());
  b[u] = ns.back();
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u, ns);
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(1, -1, vector<int>());
  for (int i = 1; i <= n; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}
