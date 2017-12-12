#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  long long md = -1;
  for (int i = 1; i < n; ++i) {
    int x = -1, y = -1;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] > a[i - 1][j]) {
        if (x != -1 && x != a[i][j] - a[i - 1][j]) {
          cout << "NO" << endl;
          return 0;
        }
        x = a[i][j] - a[i - 1][j];
      } else {
        if (y != -1 && y != a[i - 1][j] - a[i][j]) {
          cout << "NO" << endl;
          return 0;
        }
        y = a[i - 1][j] - a[i][j];
      }
    }
    if (x != -1 && y != -1) {
      if (md != -1 && md != x + y) {
        cout << "NO" << endl;
        return 0;
      }
      md = x + y;
    }
  }
  if (md == -1) md = 1e9 + 5;
  vector<int> b(n, 0);
  auto c = a[0];
  for (int i = 0; i < n; i++) {
    b[i] = (md - c[0] + a[i][0]) % md;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((b[i] + c[j]) % md != a[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  cout << md << endl;
  for (auto x : b) {
    cout << x << " ";
  }
  cout << endl;
  for (auto x : c) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
