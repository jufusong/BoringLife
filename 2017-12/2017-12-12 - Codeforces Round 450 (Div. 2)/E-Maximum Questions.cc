#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  string s;
  cin >> n >> s >> m;
  vector<vector<int>> a(4, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      a[j][i] += a[j][i - 1];
    }
    if (s[i - 1] == '?') continue;
    a[(s[i - 1] == 'a') << 1 | (i & 1)][i]++;
  }
  auto add = [](pair<int, int> x, pair<int, int> y) {
    return make_pair(x.first + y.first, x.second + y.second);
  };
  vector<pair<int, int>> f(n + 1);
  for (int i = m, z = 1; i <= n; i++, z ^= 1) {
    f[i] = f[i - 1];
    if (a[z][i] - a[z][i - m] == 0 && a[2 + (z ^ 1)][i] - a[2 + (z ^ 1)][i - m] == 0) {
      int v = m - (a[z ^ 1][i] - a[z ^ 1][i - m]) - (a[2 + z][i] - a[2 + z][i - m]);
      f[i] = max(f[i], add(f[i - m], {1, -v}));
    }
  }
  cout << -f[n].second << endl;
  return 0;
}
