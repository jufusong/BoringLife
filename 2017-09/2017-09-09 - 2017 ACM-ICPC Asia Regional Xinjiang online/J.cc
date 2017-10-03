#include <bits/stdc++.h>
#define PII pair<int, int>
#define ll long long
#define MP make_pair
using namespace std;

const int maxm = 10010;
char a[50], b[50];
ll c;
int t, n, m, cnt;
struct Edge {
  int x, y;
  ll w;
} f[maxm];

map<string, int> city;
struct node {
  int u, v;
  int nxt;
  int cap, flow;
  ll cost;
} e[maxm << 5];
int tot, hd[maxm << 5];

void Add(int u, int v, int cap, ll cost) {
  // printf("%d %d %d %lld\n", u, v, cap, cost);
  e[tot].u = u, e[tot].v = v, e[tot].nxt = hd[u], e[tot].cap = cap,
  e[tot].flow = 0, e[tot].cost = cost, hd[u] = tot++;
  e[tot].u = v, e[tot].v = u, e[tot].nxt = hd[v], e[tot].cap = 0,
  e[tot].flow = 0, e[tot].cost = -cost, hd[v] = tot++;
}

ll d[maxm << 2];
int p[maxm << 2];
bool vis[maxm << 2];

void Spfa(int s, int t) {
  for (int i = 0; i <= 2 * n + 1; i++)
    vis[i] = 0, d[i] = -1, p[i] = -1;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = hd[u]; i != -1; i = e[i].nxt) {
      int v = e[i].v;
      if (e[i].cap > e[i].flow && (d[v] == -1 || d[v] > d[u] + e[i].cost)) {
        d[v] = d[u] + e[i].cost, p[v] = i;
        if (!vis[v])
          q.push(v), vis[v] = 1;
      }
    }
  }
}
int mf;
ll Mcmf(int s, int t) {
  mf = 0;
  ll mc = 0;
  while (1) {
    Spfa(s, t);
    if (d[t] == -1)
      break;
    int a = -1;
    for (int i = p[t]; i != -1; i = p[e[i].u]) {
      if (a == -1)
        a = e[i].cap - e[i].flow;
      else
        a = min(a, e[i].cap - e[i].flow);
    }
    for (int i = p[t]; i != -1; i = p[e[i].u])
      e[i].flow += a, e[i ^ 1].flow -= a;
    mf += a, mc += d[t] * a;
  }
  return mc;
}

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // printf("%lld\n", 1ll * 131072 * 1024 / 8);

  scanf("%d", &t);
  memset(hd, -1, sizeof(hd));
  tot = 0;
  while (t--) {
    scanf("%d", &m);
    n = cnt = 0;
    city.clear();
    for (int i = 1; i <= m; i++) {
      scanf("%s%s%lld", a, b, &c);
      if (!city[string(a)])
        city[string(a)] = ++n;
      if (!city[string(b)])
        city[string(b)] = ++n;
      f[cnt].x = city[string(a)], f[cnt].y = city[string(b)];
      f[cnt++].w = c;
    }
    if (!city[string("Dalian")] || !city[string("Xian")] ||
        !city[string("Shanghai")]) {
      printf("-1\n");
      continue;
    }
    /*
    if(!city[string("Dalian")])
        city[string("Dalian")] = ++n;
    if(!city[string("Xian")])
        city[string("Xian")] = ++n;
    if(!city[string("Shanghai")])
        city[string("Shanghai")] = ++n;
    */
    int st = 2 * city[string("Shanghai")], ed = 2 * n + 1;
    Add(2 * city[string("Dalian")], ed, 1, 0);
    Add(2 * city[string("Xian")], ed, 1, 0);
    for (int i = 0; i < cnt; i++) {
      int u = f[i].x, v = f[i].y;
      int w = f[i].w;
      Add(2 * u - 1, 2 * u, 1, 0);
      Add(2 * v - 1, 2 * v, 1, 0);
      Add(2 * u, 2 * v - 1, 1, w);
      Add(2 * v, 2 * u - 1, 1, w);
    }
    ll ans = Mcmf(st, ed);
    if (mf < 2)
      printf("-1\n");
    else
      printf("%lld\n", ans);
    for (int i = 0; i <= 2 * n + 1; i++)
      hd[i] = -1;
    tot = 0;
  }
  return 0;
}
