#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, K;
  cin >> n >> m >> K;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> vec;
  for (int i = 0, j = m - 1; i < m / 2; i++, j--) {
    int cnt = 0, c2 = 0;
    for (int k = 0; k < (n + 1) / 2; k++) {
      c2 += (a[k][i] != a[k][j]);
      if (n - 1 - k == k) {
        cnt += (a[k][i] != a[k][j]);
        continue;
      }
      c2 += (a[n - 1 - k][i] != a[n - 1 - k][j]);
      vector<int> vec = {a[k][i], a[k][j], a[n - 1 - k][i], a[n - 1 - k][j]};
      int x = 4;
      map<int, int> mp;
      for (auto t : vec) {
        mp[t]++;
      }
      int mx = 0;
      for (auto e : mp) {
        mx = max(mx, e.second);
      }
      cnt += (x - mx);
    }
    //        cout << cnt << " " << c2 << endl;
    vec.push_back({cnt - c2, c2});
  }
  sort(vec.begin(), vec.end());
  auto solve = [&a, &vec](int K) {
    int ret = 0;
    for (auto e : vec) {
      if (K > 0) {
        K -= 2;
        ret += e.first + e.second;
      } else {
        ret += e.second;
      }
    }
    return ret;
  };
  int vx = 0, vy = 0;
  if (m & 1) {
    vy = 1;
    for (int k = 0; k < n / 2; k++) {
      if (a[k][m / 2] != a[n - 1 - k][m / 2]) {
        vx++;
      }
    }
  }
  int ans = solve(K);
  if (vy) {
    ans = min(ans, solve(K - 1) + vx);
  }
  cout << ans << endl;
  return 0;
}
