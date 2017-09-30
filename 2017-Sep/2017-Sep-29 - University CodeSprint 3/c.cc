#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  string s;
  vector<int> dx(4), dy(4);
  cin >> s;
  if (s == "n" || s == "s") {
    dy[1] = 1, dy[2] = -1;
    dx[0] = 1, dx[3] = -1;
    if (s == "n") dx[0] = -1, dx[3] = 1;
  } else {
    dx[1] = 1, dx[2] = -1;
    dy[0] = 1, dy[3] = -1;
    if (s == "w") dy[0] = -1, dy[3] = 1;
  }
  vector<vector<int>> a(n, vector<int>(n));
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= n * n; i++) {
    a[x][y] = i;
    for (int j = 0; j < 4; j++) {
      int tx = x + dx[j], ty = y + dy[j];
      if (tx >= 0 && ty >= 0 && tx < n && ty < n && !a[tx][ty]) {
        x = tx, y = ty;
        break;
      }
    }
  }
  for (auto& vec : a) {
    for (auto x : vec) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
