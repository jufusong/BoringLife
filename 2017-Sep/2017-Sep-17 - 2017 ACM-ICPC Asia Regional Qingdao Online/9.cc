#include <bits/stdc++.h>

using namespace std;


const int N = 1205;
const int M = 20000;
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
  std::queue<int> q;
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
      int t = dfs(v, std::min(limit - ans, w));
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
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &st, &ed);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      addedge(u, v, w * (m + 1) + 1);
    }
    printf("%d\n", dinic(n) % (m + 1));
  }
  return 0;
}
