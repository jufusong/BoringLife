#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, S, E;
    cin >> n >> S >> E;
    S--, E--;
    vector<vector<int>> a(n, vector<int>(10));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (auto c : s) {
        a[i][c - '0']++;
      }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < 10; k++) {
          cnt += min(a[i][k], a[j][k]);
        }
        if (cnt == 17) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    queue<int> q;
    vector<int> dis(n, -1);
    q.push(S);
    dis[S] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (dis[v] == -1) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }
    cout << dis[E] << endl;
  }
  return 0;
}
