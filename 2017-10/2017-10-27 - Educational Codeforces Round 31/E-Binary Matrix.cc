#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  vector<int> pre;
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void merge(int u, int v) { pre[find(u)] = find(v); }
};

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  DisjointSet d1(m);
  vector<int> a1(m);
  for (int i = 0; i < n; i++) {
    DisjointSet d2(m);
    vector<int> a2(m);
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      for (int k = 0; k < 4; k++) {
        int v = (s[j] >= '0' && s[j] <= '9' ? s[j] - '0' : s[j] - 'A' + 10);
        a2[j * 4 + k] = (((1 << (3 - k)) & v) > 0);
      }
    }
    vector<int> vis(m, -1);
    for (int j = 0; j < m; j++) {
      if (a2[j]) {
        if (a1[j]) {
          int fa = d1.find(j);
          if (vis[fa] == -1) {
            vis[fa] = j;
          } else {
            d2.merge(j, vis[fa]);
          }
        }
      }
    }
    for (int j = 0; j < m; ++j) {
      if (a1[j] && vis[d1.find(j)] == -1) {
        ans++;
        vis[d1.find(j)] = -2;
      }
    }
    for (int j = 1; j < m; ++j) {
      if (a2[j] && a2[j - 1]) {
        d2.merge(j, j - 1);
      }
    }
    a1 = a2, d1 = d2;
  }
  vector<bool> vv(m);
  for (int i = 0; i < m; i++) {
    if (a1[i] && !vv[d1.find(i)]) {
      ans++;
      vv[d1.find(i)] = true;
    }
  }
  cout << ans << endl;
  return 0;
}
