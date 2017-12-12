#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool vis[N];

vector<int> toposort(vector<vector<int>> g) {
  int n = g.size();
  vector<int> in(n);
  for (int i = 0; i < n; ++i) {
    for (auto x: g[i]) {
      in[x]++;
    }
  }
  int zz = -1;
  vector<int> ret;
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      ret.push_back(i);
      q.push(i);
      if (!vis[i]) zz = i;
    }
  }
  if (zz == -1) return {};
  ret.erase(find(ret.begin(), ret.end(), zz));
  ret.insert(ret.begin(), zz);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v: g[u]) {
      in[v]--;
      if (in[v] == 0) {
        ret.push_back(v);
        q.push(v);
      }
    }
  }
  return ret.size() == n ? ret : vector<int>();
}

int main(int argc, char *argv[]) {
  int n, m, K;
  cin >> n >> K >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> g(K);
  vis[a[0][0]] = true;
  for (int i = 1; i < n; ++i) {
    int p = -1;
    vis[a[i][0]] = true;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != a[i - 1][j]) {
        p = j;
        break;
      }
    }
    if (p == -1) {
      cout << -1 << endl;
      return 0;
    }
    g[a[i - 1][p]].push_back(a[i][p]);
  }
  auto vec = toposort(g);
  if (!vec.empty()) {
    vector<int> ans(K, 0);
    for (int i = 0; i < vec.size(); ++i) {
      ans[vec[i]] = i;
    }
    for (auto x : ans) {
      cout << x << " ";
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
