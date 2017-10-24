#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<T> spfa(int n, int S, const vector<tuple<int, int, T>>& edges) {
  vector<vector<pair<int, T>>> g(n + 1);
  for (auto& e : edges) {
    int u, v;
    T w;
    tie(u, v, w) = e;
    g[u].push_back({v, w});
  }
  vector<T> dis(n + 1, -1);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
  q.push({0, S});
  dis[S] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    for (auto& e : g[u]) {
      int v = e.first;
      T w = e.second;
      if (dis[v] < 0 || dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
  return dis;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, s, e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      edges.emplace_back(u, v, w);
      edges.emplace_back(v, u, w);
    }
    auto dis = spfa(n, s, edges);
    dis[e] == -1 ? puts("NONE") : printf("%d\n", dis[e]);
  }
  return 0;
}
