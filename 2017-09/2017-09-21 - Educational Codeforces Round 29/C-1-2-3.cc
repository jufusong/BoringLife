#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll n;
  int nx, ny;
  cin >> n >> nx >> ny;
  vector<vector<int>> a(4, vector<int>(4));
  auto b = a, c = a, d = a;
  c[3][2] = c[2][1] = c[1][3] = 1;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> b[i][j];
    }
  }
  d[nx][ny] = 1;
  vector<vector<pair<int, int>>> e(4, vector<pair<int, int>>(4));
  ll sx = c[nx][ny], sy = c[ny][nx];
  e[nx][ny] = {sx, sy};
  for (int i = 2; i <= n; i++) {
    int tx = a[nx][ny], ty = b[nx][ny];
    nx = tx, ny = ty;
    sx += c[nx][ny], sy += c[ny][nx];
    if (d[nx][ny]) {
      int l = (i - d[nx][ny]);
      ll dx = sx - e[nx][ny].first, dy = sy - e[nx][ny].second;
      int step = (n - i) % l;
      sx += (n - i) / l * dx, sy += (n - i) / l * dy;
      while (step--) {
        int tx = a[nx][ny], ty = b[nx][ny];
        nx = tx, ny = ty;
        sx += c[nx][ny], sy += c[ny][nx];
      }
      break;
    } else {
      d[nx][ny] = i;
      e[nx][ny] = {sx, sy};
    }
  }
  cout << sx << " " << sy << endl;
  return 0;
}
