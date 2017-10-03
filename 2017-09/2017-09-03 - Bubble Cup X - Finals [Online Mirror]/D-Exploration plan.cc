#include <bits/stdc++.h>

using namespace std;

const int N = 1205;
const int M = 2000000;
const int inf = 1e9;

struct Edge {
  int v, w, next;
} g[M];
int cnt = 0, head[N], st, ed, dis[N], cur[N];
void init() {
  memset(head, -1, sizeof(head));
  cnt = 0;
}
void addedge(int u, int v, int w = 1) {
  g[cnt].v = v, g[cnt].w = w, g[cnt].next = head[u], head[u] = cnt++;
  g[cnt].v = u, g[cnt].w = 0, g[cnt].next = head[v], head[v] = cnt++;
}
bool bfs() {
  memset(dis, -1, sizeof(dis));
  dis[st] = 0;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; ~i; i = g[i].next) {
      int v = g[i].v, w = g[i].w;
      if (w && dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
        if (v == ed)
          return true;
      }
    }
  }
  return false;
}
int dfs(int u, int limit) {
  if (u == ed)
    return limit;
  int ans = 0;
  for (int &i = cur[u]; ~i; i = g[i].next) {
    int v = g[i].v, w = g[i].w;
    if (w && dis[v] == dis[u] + 1) {
      int t = dfs(v, min(limit - ans, w));
      g[i].w -= t;
      g[i ^ 1].w += t;
      ans += t;
      if (ans == limit)
        break;
    }
  }
  if (!ans)
    dis[u] = -1;
  return ans;
}
int dinic(int n) {
  int ans = 0;
  while (bfs()) {
    for (int i = 1; i <= n; i++)
      cur[i] = head[i];
    ans += dfs(st, inf);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int V, E, N, K;
  cin >> V >> E >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<vector<int>> d(V + 1, vector<int>(V + 1, inf));
  for (int i = 1; i <= V; i++) {
    d[i][i] = 0;
  }
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = d[v][u] = min(d[v][u], w);
  }
  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int mx = 1731311;
  int low = 0, high = mx;
  while (low <= high) {
    int mid = (low + high) / 2;
    st = 2 * V + 1, ed = 2 * V + 2;
    init();
    for (auto x : a) {
      addedge(st, x, 1);
    }
    for (int i = 1; i <= V; i++) {
      addedge(i + V, ed, 1);
      for (int j = 1; j <= V; j++) {
        if (d[i][j] <= mid) {
          addedge(i, j + V, inf);
        }
      }
    }
    if (dinic(2 * V + 2) >= K) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << (low > mx ? -1 : low) << endl;
  return 0;
}
