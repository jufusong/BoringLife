#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
const int M = 2999999;
const int inf = 1e9;

struct Edge {
  int v, w, cost, next;
} g[M];

int head[N], st, ed, flow, cost, cnt;

void init() {
  memset(head, -1, sizeof(head));
  flow = cost = cnt = 0;
}

void addEdge(int u, int v, int w, int cost) {
  g[cnt].v = v, g[cnt].w = w, g[cnt].cost = cost, g[cnt].next = head[u],
  head[u] = cnt++;
  g[cnt].v = u, g[cnt].w = 0, g[cnt].cost = -cost, g[cnt].next = head[v],
  head[v] = cnt++;
}

bool spfaFlow(int n) {
  vector<int> dis(n + 1, inf);
  vector<bool> vis(n + 1, false);
  vector<int> path(n + 1, -1);
  dis[st] = 0;
  vis[st] = true;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = head[u]; ~i; i = g[i].next) {
      int v = g[i].v;
      if (g[i].w && dis[v] > dis[u] + g[i].cost) {
        dis[v] = dis[u] + g[i].cost;
        path[v] = i;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  int mxflow = inf;
  if (path[ed] != -1) {
    for (int u = ed; u != st; u = g[path[u] ^ 1].v) {
      mxflow = min(mxflow, g[path[u]].w);
    }
    flow += mxflow;
    for (int u = ed; u != st; u = g[path[u] ^ 1].v) {
      g[path[u]].w -= mxflow;
      g[path[u] ^ 1].w += mxflow;
      cost += mxflow * g[path[u]].cost;
    }
  }
  return path[ed] != -1;
}

int minCost(int n) {
  while (spfaFlow(n));
  return cost;
}

int main(int argc, char *argv[]) {
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> a(n + 1, {1, n});
  while (q--) {
    int t, l, r, v;
    cin >> t >> l >> r >> v;
    for (int i = l; i <= r; i++) {
      if (t == 1) {
        a[i].first = max(a[i].first, v);
      } else {
        a[i].second = min(a[i].second, v);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].first > a[i].second) {
      cout << -1 << endl;
      return 0;
    }
  }
  st = n + n + 1, ed = n + n + 2;
  init();
  for (int i = 1; i <= n; i++) {
    addEdge(st, i, 1, 0);
    for (int j = 1; j <= n; j++) {
      addEdge(i + n, ed, 1, j * j - (j - 1) * (j - 1));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = a[i].first; j <= a[i].second; j++) {
      addEdge(i, j + n, 1, 0);
    }
  }
  cout << minCost(n + n + 2) << endl;
  return 0;
}
