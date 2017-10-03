#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e18;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m, K;
  cin >> n >> m >> K;
  vector<ll> a(1000001, -1), b(1000001, -1);
  vector<vector<pair<pair<int, int>, int>>> g(1000001);
  for (int i = 0; i < m; i++) {
    int d, t, f, c;
    cin >> d >> t >> f >> c;
    g[d].push_back({{t, f}, c});
  }
  vector<int> c(n + 1, -1);
  int cnt = 0;
  ll sum = 0;
  for (int i = 1; i <= 1000000; i++) {
    for (auto e : g[i]) {
      if (e.first.second == 0) {
        int u = e.first.first;
        if (c[u] == -1) {
          cnt++;
          sum += e.second;
          c[u] = e.second;
        } else if (c[u] > e.second) {
          sum -= c[u] - e.second;
          c[u] = e.second;
        }
      }
    }
    if (cnt == n) a[i] = sum;
  }
  cnt = sum = 0;
  fill(c.begin(), c.end(), -1);
  for (int i = 1000000; i >= 1; i--) {
    for (auto e : g[i]) {
      if (e.first.first == 0) {
        int u = e.first.second;
        if (c[u] == -1) {
          cnt++;
          sum += e.second;
          c[u] = e.second;
        } else if (c[u] > e.second) {
          sum -= c[u] - e.second;
          c[u] = e.second;
        }
      }
    }
    if (cnt == n) b[i] = sum;
  }
  ll ans = inf;
  for (int i = 1; i + K + 1 <= 1000000; i++) {
    if (a[i] != -1 && b[i + K + 1] != -1) {
      ans = min(ans, a[i] + b[i + K + 1]);
    }
  }
  cout << (ans == inf ? -1 : ans) << endl;
  return 0;
}
