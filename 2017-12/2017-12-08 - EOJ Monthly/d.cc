#include <bits/stdc++.h>

using namespace std;

const int N = 30005;
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
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> pr(1000001);
  for (int i = 2; i <= 1000000; i++) {
    if (pr[i].empty()) {
      for (int j = i; j <= 1000000; j += i) {
        pr[j].push_back(i);
      }
    }
  }
  int low = 1, high = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    init();
    vector<int> vec;
    for (int i = 0; i < mid; ++i) {
      for (auto x : pr[a[i]]) {
        vec.push_back(x);
      }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    st = mid + vec.size() + 1, ed = mid + vec.size() + 2;
    for (int i = 0; i < mid; ++i) {
      addedge(st, i + 1, 1);
      for (auto x : pr[a[i]]) {
        int idx = lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
        addedge(i + 1, mid + idx, 1);
      }
    }
    for (int i = 0; i < vec.size(); ++i) {
      addedge(mid + i + 1, ed, 1);
    }
    int d = dinic(mid + vec.size() + 2);
    if (d == mid) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << high << endl;
  return 0;
}
