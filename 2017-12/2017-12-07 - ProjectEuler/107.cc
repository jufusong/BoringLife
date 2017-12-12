#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
  std::vector<int> pre;

  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void merge(int u, int v) { pre[find(u)] = find(v); }
};

int main(int argc, char *argv[]) {
  vector<tuple<int, int, int>> edge;
  for (int i = 0; i < 40; ++i) {
    for (int j = 0; j < 40; ++j) {
      int x;
      cin >> x;
      if (x != -1 && i < j) {
        edge.emplace_back(x, i, j);
      }
    }
  }
  sort(edge.begin(), edge.end());
  DisjointSet ds(40);
  int sum = 0;
  for (auto e : edge) {
    int x, u, v;
    tie(x, u, v) = e;
    if (ds.find(u) == ds.find(v)) {
      sum += x;
    }
    ds.merge(u, v);
  }
  cout << sum << endl;
  return 0;
}
