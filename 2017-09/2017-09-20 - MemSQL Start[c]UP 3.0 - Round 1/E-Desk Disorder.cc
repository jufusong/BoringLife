#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

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
  int n;
  cin >> n;
  DisjointSet ds(2 * n);
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
    ds.merge(vec[i].first, vec[i].second);
  }
  vector<int> a(2 * n + 1), b(2 * n + 1);
  for (int i = 1; i <= 2 * n; i++) {
    a[ds.find(i)]++;
  }
  for (auto e : vec) {
    b[ds.find(e.first)]++;
    if (e.first == e.second) b[ds.find(e.first)]++;
  }
  ll ans = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (i == ds.find(i) && a[i] > 1) {
      if (b[i] == a[i]) ans = ans * 2 % mod;
      else if (b[i] < a[i]) ans = ans * a[i] % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
