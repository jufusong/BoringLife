#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1205;
const int M = 2000000;
const ll inf = 1e18;

struct Edge {
  int v, next;
  ll w;
} g[M];
int cnt = 0, head[N], st, ed, dis[N], cur[N];
void init() {
  memset(head, -1, sizeof(head));
  cnt = 0;
}
void addedge(int u, int v, ll w = 1) {
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
      int v = g[i].v;
      ll w = g[i].w;
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
ll dfs(int u, ll limit) {
  if (u == ed)
    return limit;
  ll ans = 0;
  for (int &i = cur[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    ll w = g[i].w;
    if (w && dis[v] == dis[u] + 1) {
      ll t = dfs(v, min(limit - ans, w));
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
ll dinic(int n) {
  ll ans = 0;
  while (bfs()) {
    for (int i = 1; i <= n; i++)
      cur[i] = head[i];
    ans += dfs(st, inf);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    a[i] = -a[i];
  }
  st = n + 1, ed = n + 2;
  init();
  ll S = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 0) {
      addedge(st, i, a[i]);
      S += a[i];
    } else {
      addedge(i, ed, -a[i]);
    }
    for (int j = i + i; j <= n; j += i) {
      addedge(i, j, inf);
    }
  }
  cout << sum + S - dinic(n + 2) << endl;
  return 0;
}
