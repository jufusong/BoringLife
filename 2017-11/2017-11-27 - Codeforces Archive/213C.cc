#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  std::vector<std::vector<int>> a(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<vector<int>>> f(2, vector<vector<int>>(n, vector<int>(n, -inf)));
  f[0][0][0] = a[0][0];
  int dx[] = {0, 1}, dy[] = {1, 0};
  int now = 0;
  for (int i = 0; i < 2 * (n - 1); ++i) {
    f[now ^ 1] = vector<vector<int>>(n, vector<int>(n, -inf));
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        for (int z1 = 0; z1 < 2; ++z1) {
          for (int z2 = 0; z2 < 2; ++z2) {
            int x1 = j, y1 = i - j, x2 = k, y2 = i - k;
            if (y1 >= 0 && y1 + dy[z1] < n && y2 >= 0 && y2 + dy[z2] < n && x1 + dx[z1] < n && x2 + dx[z2] < n) {
              int tx1 = x1 + dx[z1], tx2 = x2 + dx[z2];
              int w = a[tx1][i + 1 - tx1];
              if (tx1 != tx2) {
                w += a[tx2][i + 1 - tx2];
              }
              f[now ^ 1][tx1][tx2] = max(f[now ^ 1][tx1][tx2], f[now][x1][x2] + w);
            }
          }
        }
      }
    }
    now ^= 1;
  }
  cout << f[now][n - 1][n - 1] << endl;
  return 0;
}
