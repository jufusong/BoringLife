#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

vector<int> g[N];

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < N; i++) {
      g[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto bfs = [&n](int st) {
      vector<int> dis(n + 1, inf);
      dis[st] = 0;
      queue<int> q;
      q.push(st);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
          if (dis[v] == inf) {
            dis[v] = dis[u] + 1;
            q.push(v);
          }
        }
      }
      int mx = -1, p = -1;
      for (int i = 1; i <= n; i++) {
        if (dis[i] > mx) {
          mx = dis[i];
          p = i;
        }
      }
      return make_pair(mx, p);
    };
    auto ret = bfs(1);
    int tu = ret.second;
    ret = bfs(tu);
    g[tu].push_back(ret.second);
    g[ret.second].push_back(tu);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, bfs(i).first);
    }
    cout << mx << endl;
  }
  return 0;
}
