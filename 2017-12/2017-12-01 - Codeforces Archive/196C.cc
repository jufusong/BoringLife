#include <bits/stdc++.h>

using namespace std;

vector<int> g[1501];
int sz[1501], ans[1501];

int dfs1(int u, int fa) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != fa) {
      sz[u] += dfs1(v, u);
    }
  }
  return sz[u];
}

void dfs2(int u, int fa, vector<pair<pair<int, int>, int>> vec) { 
  sort(vec.begin(), vec.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
      return a.first.first < b.first.first;
      });
  ans[vec[0].second] = u;
  int x = vec[0].first.first, y = vec[0].first.second;
  sort(vec.begin() + 1, vec.end(), [x, y](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
      int x1 = a.first.first - x, y1 = a.first.second - y;
      int x2 = b.first.first - x, y2 = b.first.second - y;
      return (long long)x1 * y2 > (long long)x2 * y1;
      });
  vec.erase(vec.begin());
  for (auto v : g[u]) {
    if (v != fa) {
      int cnt = sz[v];
      dfs2(v, u, {vec.begin(), vec.begin() + cnt});
      vec.erase(vec.begin(), vec.begin() + cnt);
    }
  }
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<pair<pair<int, int>, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first.first >> vec[i].first.second;
    vec[i].second = i + 1;
  }
  dfs1(1, -1);
  dfs2(1, -1, vec);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
