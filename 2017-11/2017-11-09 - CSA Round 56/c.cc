#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct DisjointSet {
  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  vector<int> pre;
  vector<int> a;
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    a[fv] |= a[fu];
    pre[fu] = fv;
  }
};

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  DisjointSet ds(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  vector<int> a(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  ds.a = a;
  for (int i = 1; i < n; i++) {
    q.push({(a[i - 1] & a[i]), i - 1});
  }
  auto check = [&q, &ds](int x, int y, int v) {
    int fu = ds.find(x), fv = ds.find(y);
    if (fu == fv) return false;
    int v1 = ds.a[fu], v2 = ds.a[fv];
    if ((v1 & v2) == v) return true;
    q.push({v1 + v2 - (v1 | v2), x});
    return false;
  };
  for (int i = 0; i < n - K; i++) {
    auto u = q.top();
    q.pop();
    while (!check(u.second, u.second + 1, u.first)) {
      u = q.top();
      q.pop();
    }
    ans -= u.first;
    ds.merge(u.second, u.second + 1);
  }
  cout << ans << endl;
  return 0;
}
