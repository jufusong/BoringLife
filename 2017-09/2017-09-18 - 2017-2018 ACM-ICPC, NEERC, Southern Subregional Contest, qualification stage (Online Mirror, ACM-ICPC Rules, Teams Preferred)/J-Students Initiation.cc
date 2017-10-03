#include <bits/stdc++.h>

using namespace std;

const int N = 20005;
const int M = 100000;
const int inf = 1e9;

typedef int TYPE;

struct Edge{
  int v, next, id;
  TYPE w;
}g[M];

int cnt, head[N], cur[N], st, ed, num, d[N], vd[N];
void init(int n)
{
  memset(head, -1, sizeof(head));
  memset(vd, 0, sizeof(vd));
  memset(d, 0, sizeof(d));
  cnt = 0;
  vd[0] = num = n;
}
void addedge(int u, int v, TYPE w, int id)
{
  g[cnt].v = v, g[cnt].w = w, g[cnt].next = head[u], g[cnt].id = id, head[u] = cnt ++;
  g[cnt].v = u, g[cnt].w = 0, g[cnt].next = head[v], g[cnt].id = id, head[v] = cnt ++;
}
TYPE sap(int u, TYPE flow)
{
  if (u == ed)  return flow;
  TYPE ans = 0;
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    TYPE w = g[i].w;
    if (d[v] < d[u] && w) {
      TYPE f = sap(v, min(flow - ans, w));
      ans += f;
      g[i].w -= f;
      g[i^1].w += f;
      if(ans == flow)  return ans;
    }
  }
  if (!(--vd[d[u]]))      d[st] = num + 2;
  vd[++d[u]] ++;
  return ans;
}
TYPE maxflow()
{
  TYPE ans = 0;
  while (d[st] < num)  ans += sap(st, inf);
  return ans;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vec;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    vec.push_back({u, v});
  }
  int low = 0, high = n;
  auto check = [&vec, &n, &m](int mid){
    init(n + m + 2);
    st = n + m + 1, ed = n + m + 2;
    for (int i = 0; i < m; i++) {
      addedge(st, i + 1, 1, -1);
      int u = vec[i].first, v = vec[i].second;
      addedge(i + 1, u + m, 1, i);
      addedge(i + 1, v + m, 1, i);
    }
    for (int i = 1; i <= n; i++) {
      addedge(i + m, ed, mid, -1);
    }
    return maxflow() == m;
  };
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(mid)) high = mid - 1;
    else low = mid + 1;
  }
  cout << low << endl;
  check(low);
  for (int i = 0; i < cnt; i += 2) {
    if (g[i].v > m && g[i].v <= n + m && g[i ^ 1].v <= m && g[i ^ 1].v >= 1 && g[i ^ 1].w == 1) {
      int id = g[i].id;
      cout << g[i].v - m << " " << (vec[id].first == g[i].v - m ? vec[id].second : vec[id].first) << endl;
    }
  }
  return 0;
}
