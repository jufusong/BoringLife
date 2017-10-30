#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
const int M = 1000000;
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
  //    cout << u << " " << v << " " << w << " " << cost << endl;
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int N = 26 + n * 26 + (n / 2) * 26 + (n / 2);
  st = N + 1, ed = N + 2;
  init();
  vector<int> cnt(255);
  for (auto c : s) {
    cnt[c]++;
  }
  int Z = n * 26 + (n / 2) * 27;
  for (int i = 'a'; i <= 'z'; i++) {
    addEdge(st, Z + i - 'a' + 1, cnt[i], 0);
    for (int j = 1; j <= n; j++) {
      addEdge(Z + i - 'a' + 1, (i - 'a') * n + j, 1, i == s[j - 1] ? -b[j] : 0);
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= n / 2; j++) {
      int ux = i * n + j, uy = i * n + n + 1 - j;
      addEdge(ux, n * 26 + (n / 2) * i + j, 1, 0);
      addEdge(uy, n * 26 + (n / 2) * i + j, 1, 0);
      addEdge(n * 26 + (n / 2) * i + j, n * 26 + (n / 2) * 26 + j, 1, 0);
    }
  }
  for (int j = 1; j <= n / 2; j++) {
    addEdge(n * 26 + (n / 2) * 26 + j, ed, 2, 0);
  }
  cout << -minCost(N + 2) << endl;
  return 0;
}
