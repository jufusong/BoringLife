#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

template <class T> struct Dinic {
  struct Edge {
    int dest, back;
    T cap;
  };
  vector<vector<Edge> > g;
  vector<int> dis;
  Dinic(int n) : g(n), dis(n) {}

  void addEdge(int u, int v, T cap) {
    Edge a = (Edge){v, (int)g[v].size(), cap};
    Edge b = (Edge){u, (int)g[u].size(), 0};
    g[u].push_back(a);
    g[v].push_back(b);
  }

  bool bfs(int st, int ed) {
    fill(dis.begin(), dis.end(), -1);
    dis[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < g[u].size(); i++) {
        Edge& e = g[u][i];
        if (e.cap && dis[e.dest] == -1) {
          dis[e.dest] = dis[u] + 1;
          q.push(e.dest);
          if (e.dest == ed) return true;
        }
      }
    }
    return false;
  }

  T dfs(int u, int ed, T flow) {
    if (u == ed) return flow;
    T ret = 0;
    for (int i = 0; i < g[u].size(); i++) {
      Edge& forward = g[u][i], back = g[forward.dest][forward.back];
      if (forward.cap && dis[forward.dest] == dis[u] + 1) {
        T f = dfs(forward.dest, ed, flow == -1 ? forward.cap : min(forward.cap, flow - ret));
        forward.cap -= f;
        back.cap += f;
        ret += f;
        if (ret == flow) break;
      }
    }
    if (!ret) dis[u] = -1;
    return ret;
  }
  
  T maxFlow(int st, int ed) {
    T ret = 0;
    while (bfs(st, ed)) {
      ret += dfs(st, ed, -1);
    }
    return ret;
  }
};

template <class T> struct ISAP {
  struct Edge {
    int dest, back;
    T cap;
  };
  vector<vector<Edge> > g;
  vector<int> d, vd;
  ISAP(int n) : g(n), d(n), vd(n * 2) {
    vd[0] = n;
  }

  void addEdge(int u, int v, T cap) {
    Edge a = (Edge){v, (int)g[v].size(), cap};
    Edge b = (Edge){u, (int)g[u].size(), 0};
    g[u].push_back(a);
    g[v].push_back(b);
  }

  T sap(int u, int st, int ed, T flow) {
    if (u == ed) return flow;
    T ret = 0;
    for (int i = 0; i < g[u].size(); i++) {
      Edge& forward = g[u][i];
      Edge& back = g[forward.dest][forward.back];
      if (d[forward.dest] < d[u] && forward.cap) {
        T f = sap(forward.dest, st, ed, flow == -1 ? forward.cap : min(flow - ret, forward.cap));
        ret += f;
        forward.cap -= f;
        back.cap += f;
        if (ret == flow) return ret;
      }
    }
    if (!(--vd[d[u]])) d[st] = g.size() + 2;
    vd[++d[u]]++;
    return ret;
  }
  
  T maxFlow(int st, int ed) {
    T ret = 0;
    while (d[st] < g.size()) ret += sap(st, st, ed, -1);
    return ret;
  }
};

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  ISAP<long long> dinic(n + 2);
  int st = 0, ed = n + 1;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    dinic.addEdge(0, i, a);
    dinic.addEdge(i, ed, b);
  }
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    dinic.addEdge(u, v, c);
    dinic.addEdge(v, u, c);
  }
  printf("%lld\n", dinic.maxFlow(st, ed));
  return 0;
}
