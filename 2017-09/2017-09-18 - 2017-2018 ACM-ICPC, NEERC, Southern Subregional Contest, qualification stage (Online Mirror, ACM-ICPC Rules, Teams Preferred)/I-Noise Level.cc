#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m, q, p;
  cin >> n >> m >> q >> p;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> b(n, vector<int>(m));
  vector<vector<bool>> c(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '*' && a[i][j] != '.') {
        int now = q * (a[i][j] - 'A' + 1);
        b[i][j] += now;
        queue<pair<int, int>> q;
        q.push({i * 1000 + j, now / 2});
        c[i][j] = true;
        vector<pair<int, int>> vec;
        vec.push_back({i, j});
        while (!q.empty()) {
          int x = q.front().first / 1000, y = q.front().first % 1000;
          int v = q.front().second;
          q.pop();
          int dx[] = {-1, 0, 0, 1};
          int dy[] = {0, -1, 1, 0};
          for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] != '*' && !c[tx][ty]) {
              b[tx][ty] += v;
              c[tx][ty] = true;
              vec.push_back({tx, ty});
              if (v / 2 > 0) {
                q.push({tx * 1000 + ty, v / 2});
              }
            }
          }
        }
        for (auto e : vec) {
          c[e.first][e.second] = false;
        }
      }
    }
  }
  int ans = 0;
  for (auto v : b) {
    for (auto x : v) {
      if (x > p) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
