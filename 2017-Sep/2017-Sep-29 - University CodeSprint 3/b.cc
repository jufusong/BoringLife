#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(n));
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int v = max(abs(j - y), abs(i - x));
        if (v < w) {
          a[i][j] += w - v;
        }
      }
    }
  }
  int mx = 0;
  for (auto& vec : a) {
    for (auto x : vec) {
      mx = max(mx, x);
    }
  }
  cout << mx << endl;
  return 0;
}
