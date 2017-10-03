#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int n, m, k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  vector<pair<pair<int, int>, int>> a(q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
  }
  int low = 0, high = inf;
  while (low <= high) {
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    int mid = (low + high) / 2;
    for (auto e : a) {
      if (e.second <= mid) {
        b[e.first.first][e.first.second]++;        
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
      }
    }
    bool flag = false;
    for (int i = k; i <= n; i++) {
      for (int j = k; j <= m; j++) {
        flag |= (b[i][j] - b[i - k][j] - b[i][j - k] + b[i - k][j - k] == k * k);
      }
    }
    if (flag) high = mid - 1;
    else low = mid + 1;
  }
  cout << (low > inf ? -1 : low) << endl;
  return 0;
}
