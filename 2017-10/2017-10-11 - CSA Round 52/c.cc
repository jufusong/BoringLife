#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<pair<int, int>> g[N];
int a[N];
vector<int> vec;

int dfs1(int u, int fa) {
  a[u] = 1;
  for (auto e : g[u]) {
    if (e.first != fa) {
      a[u] += dfs1(e.first, u);
    }
  }
  return a[u];
}

void dfs2(int u, int fa) {
  for (auto e : g[u]) {
    if (e.first != fa) {
      if (e.second == 1) {
        vec.push_back(a[e.first]);
      } else {
        dfs2(e.first, u);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  dfs1(1, 0);
  dfs2(1, 0);
  sort(vec.begin(), vec.end());
  int sum = 0;
  for (auto x : vec) {
    sum += x;
  }
  int cnt = vec.size();
  if (sum < n - K) {
    cout << -1 << endl;
    return 0;
  }
  for (auto x : vec) {
    if (sum - x >= n - K) {
      sum -= x;
      cnt--;
    }
  }
  cout << cnt << endl;
  return 0;
}
