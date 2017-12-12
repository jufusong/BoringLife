#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  vector<tuple<int, int, int>> a, b;
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a.emplace_back(x1 + x2, y1 + y2, i);
    b.emplace_back(y1 + y2, x1 + x2, i);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<bool> vis(n);
  long long ans = 1e18;
  for (int i = n - K - 1; i < n; ++i) {
    for (int j = 0; n - i - 1 + j <= K; ++j) {
      for (int k = 0; k < j; ++k) {
        vis[get<2>(a[k])] = true;
      }
      for (int k = i + 1; k < n; ++k) {
        vis[get<2>(a[k])] = true;
      }
      int d = K - (n - i - 1) - j;
      int S = i - j + 1, h = 0;
      for (int k = 0; k < n; k++) {
        if (!vis[get<2>(b[k])]) {
          S--;
          while (h < n && S <= d) {
            S += !vis[get<2>(b[h++])];
          }
          if (h) ans = min(ans, (long long)max(1, (get<0>(a[i]) - get<0>(a[j]) + 1) / 2) * ((long long)max(1, (get<0>(b[k]) - get<0>(b[h - 1]) + 1) / 2)));
        }
      }
      for (int k = 0; k < j; ++k) {
        vis[get<2>(a[k])] = false;
      }
      for (int k = i + 1; k < n; ++k) {
        vis[get<2>(a[k])] = false;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
