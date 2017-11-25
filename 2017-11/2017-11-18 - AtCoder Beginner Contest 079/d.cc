#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(10, vector<int>(10));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      if (t != -1) ans += a[t][1];
    }
  }
  cout << ans << endl;
  return 0;
}
