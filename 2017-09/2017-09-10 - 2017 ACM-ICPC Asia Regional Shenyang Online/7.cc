#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define clr(x, y) memset(x, y, sizeof(x))
#define MP(x, y) make_pair(x, y)
#define RS(n) scanf("%s", n)
#define ALL(t) (t).begin(), (t).end()
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define ROF(i, n, m) for (int i = n; i >= m; i--)
#define IT iterator
#define FF first
#define SS second

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> PII;

void RI(int &x) {
  x = 0;
  char c = getchar();
  while (!(c >= '0' && c <= '9' || c == '-'))
    c = getchar();
  bool flag = 1;
  if (c == '-') {
    flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (!flag)
    x = -x;
}
void RII(int &x, int &y) { RI(x), RI(y); }
void RIII(int &x, int &y, int &z) { RI(x), RI(y), RI(z); }
void RC(char &c) {
  c = getchar();
  while (c == ' ' || c == '\n')
    c = getchar();
}
char RC() {
  char c = getchar();
  while (c == ' ' || c == '\n')
    c = getchar();
  return c;
}

/**************************************END
 * define***************************************/

const ll mod = 1e9 + 7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

const int N = 100005;

vector<PII> g[N];
int fa[N], sz[N], dep[N], son[N], cost[N], cnt, pos[N], top[N];
int tree[N * 4];

void init() {
  FOR(i, 0, N - 1) g[i].clear();
  clr(son, -1), clr(fa, 0), clr(sz, 0), clr(dep, 0);
  clr(cost, 0), clr(pos, 0), clr(top, 0);//, clr(flag, 0);
  clr(tree, 0);
  cnt = 0;
}

void dfs1(int u) {
  sz[u] = 1;
  FOR(i, 0, SIZE(g[u]) - 1) {
    int v = g[u][i].FF;
    if (v == fa[u])
      continue;
    dep[v] = dep[u] + 1;
    fa[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) {
      son[u] = v;
    }
  }
}

void dfs2(int u, int tp) {
  pos[u] = ++cnt;
  top[u] = tp;
  if (son[u] != -1)
    dfs2(son[u], tp);
  FOR(i, 0, SIZE(g[u]) - 1) {
    int v = g[u][i].FF;
    if (v != son[u] && v != fa[u]) {
      dfs2(v, v);
    }
  }
}

void pushup(int pos) {
  tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}


void update2(int l, int r, int pos, int L, int R) {
  if (l >= L && r <= R) {
    tree[pos] = 0;
    return;
  }
  if (!tree[pos]) return;
  //    pushdown(pos);
  int m = (l + r) / 2;
  if (m >= L)
    update2(l, m, pos * 2, L, R);
  if (m + 1 <= R)
    update2(m + 1, r, pos * 2 + 1, L, R);
  pushup(pos);
}

int query(int l, int r, int pos, int L, int R) {
  if (l >= L && r <= R) {
    return tree[pos];
  }
  if (!tree[pos]) return 0;
  int m = (l + r) / 2, sum = 0;
  if (m >= L)
    sum += query(l, m, pos * 2, L, R);
  if (m + 1 <= R)
    sum += query(m + 1, r, pos * 2 + 1, L, R);
  return sum;
}

int find(int u, int v) {
  int f1 = top[u], f2 = top[v];
  int sum = 0;
  while (f1 != f2) {
    if (dep[f1] < dep[f2]) {
      swap(f1, f2);
      swap(u, v);
    }
    sum += query(1, cnt, 1, pos[f1], pos[u]);
    u = fa[f1];
    f1 = top[u];
  }
  if (u == v) return sum;
  if (dep[u] > dep[v])
    swap(u, v);
  sum += query(1, cnt, 1, pos[son[u]], pos[v]);
  return sum;
}

void change(int u, int v) {
  int f1 = top[u], f2 = top[v];
  while (f1 != f2) {
    if (dep[f1] < dep[f2]) {
      swap(f1, f2);
      swap(u, v);
    }
    update2(1, cnt, 1, pos[f1], pos[u]);
    u = fa[f1];
    f1 = top[u];
  }
  if (u == v)
    return;
  if (dep[u] > dep[v])
    swap(u, v);
  update2(1, cnt, 1, pos[son[u]], pos[v]);
}

void update (int l, int r, int pos, int loc, int val){
  if (l == r){
    tree[pos] = val;
    return;
  }
  //  if (flag[pos])          pushdown (pos);
  int m = (l + r)/2;
  if (m >= loc)   update (l, m, pos*2, loc, val);
  else            update (m+1, r, pos*2+1, loc, val);
  pushup (pos);
}

void build(int n) {
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  //  update(1, cnt, 1, 1, -INF);
  FOR(i, 1, n) {
    FOR(j, 0, SIZE(g[i]) - 1) {
      int u = i, v = g[i][j].FF;
      if (dep[u] > dep[v])
        update(1, cnt, 1, pos[u], g[i][j].SS);
      else
        update(1, cnt, 1, pos[v], g[i][j].SS);
    }
  }
}

struct DisjointSet {
  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  vector<int> pre;
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void Union(int u, int v) { pre[find(u)] = find(v); }
};

int main() {
  int T, cas = 1;
  RI(T);
  while (T--) {
    printf("Case #%d:\n", cas++);
    init();
    int n, m;
    RII(n, m);
    DisjointSet ds(n);
    vector<pair<int, int>> eg;
    FOR(i, 0, m - 1) {
      int u, v;
      RII(u, v);
      if (ds.find(u) == ds.find(v)) {
        eg.push_back({u, v});
      } else {
        g[u].PB(MP(v, 1));
        g[v].PB(MP(u, 1));
        ds.Union(u, v);
      }
    }
    build(n);
    for (auto e : eg) {
      change(e.first, e.second);
    }
    int Q;
    RI(Q);
    while (Q--) {
      int op, u, v;
      RIII(op, u, v);
      if (op == 1) {
        change(u, v);
      } else {
        printf("%d\n", find(u, v));
      }
    }
  }
}
