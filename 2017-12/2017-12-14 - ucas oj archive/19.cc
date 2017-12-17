#include <bits/stdc++.h>

using namespace std;

template <class T> struct MCMF {
  struct Edge {
    int dest, back;
    T cap, cost;
  };
  T total_flow, total_cost;
  vector<vector<Edge>> g;
  MCMF(int n) : g(n), total_flow(0), total_cost(0) {}

  void addEdge(int u, int v, T cap, T cost) {
    Edge a{v, (int)g[v].size(), cap, cost};
    Edge b{u, (int)g[u].size(), 0, -cost};
    g[u].push_back(a);
    g[v].push_back(b);
  }

  bool spfaFlow(int st, int ed) {
    int n = g.size();
    vector<T> dis(n, numeric_limits<T>::max() / 3);
    vector<bool> vis(n, false);
    vector<Edge*> path(n, nullptr);
    dis[st] = 0, vis[st] = true;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int u = q.front();
      q.pop(), vis[u] = false;
      for (auto& forward : g[u]) {
        if (forward.cap && dis[forward.dest] > dis[u] + forward.cost) {
          dis[forward.dest] = dis[u] + forward.cost;
          path[forward.dest] = &forward;
          if (!vis[forward.dest]) {
            vis[forward.dest] = true, q.push(forward.dest);
          }
        }
      }
    }
    T flow = -1;
    if (path[ed] != nullptr) {
      for (int u = ed; u != st; ) {
        flow = (flow == -1 ? path[u]->cap : min(flow, path[u]->cap));
        Edge& back = g[path[u]->dest][path[u]->back];
        u = back.dest;
      }
      total_flow += flow;
      for (int u = ed; u != st; ) {
        Edge& back = g[path[u]->dest][path[u]->back];
        path[u]->cap -= flow;
        back.cap += flow;
        total_cost += flow * path[u]->cost;
        u = back.dest;
      }
    }
    return path[ed] != nullptr;
  }
  
  pair<T, T> mcmf(int st, int ed) {
    while (spfaFlow(st, ed));
    return {total_flow, total_cost};
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> vx(n, 0), vy(m, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vx[i] = max(vx[i], a[i][j]);
      vy[j] = max(vy[j], a[i][j]);
    }
  }
  long long sum = 0, S = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      S += a[i][j];
      if (a[i][j]) sum++;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (vx[i]) sum += vx[i] - 1;
  }
  for (int i = 0; i < m; ++i) {
    if (vy[i]) sum += vy[i] - 1;
  }
  vector<vector<int>> b(n, vector<int>(m, 0));
  int st = n + m, ed = n + m + 1;
  MCMF<long long> mf(n + m + 2);
  for (int i = 0; i < n; i++) {
    mf.addEdge(st, i, 1, 0);
  }
  for (int i = 0; i < m; ++i) {
    mf.addEdge(i + n, ed, 1, 0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      if (vx[i] == vy[j] && vx[i] && a[i][j]) {
        mf.addEdge(i, j + n, 1, -vx[i] + 1);
      }
    }
  }
  cout << (S - mf.mcmf(st, ed).second - sum) << endl;
  return 0;
}

