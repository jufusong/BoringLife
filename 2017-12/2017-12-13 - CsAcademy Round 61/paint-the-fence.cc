#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2, 0);
  vector<pair<int, int>> vec;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    vec.push_back({l, r});
    a[l]++, a[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (a[i] == 0);
    if (a[i] != 1) a[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  for (auto e: vec) {
    cout << a[e.second] - a[e.first - 1] + cnt << endl;
  }
  return 0;
}
