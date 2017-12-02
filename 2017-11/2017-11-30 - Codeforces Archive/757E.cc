#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(int argc, char *argv[]) {
  vector<int> a(1000001);
  vector<vector<pair<int, int>>> c(1000001);
  for (int i = 2; i <= 1000000; ++i) {
    if (!a[i]) {
      for (int j = i; j <= 1000000; j += i) {
        a[j]++;
        int cnt = 0, t = j;
        while (t % i == 0) {
          t /= i;
          cnt++;
        }
        c[j].push_back({i, cnt});
      }
    }
  }
  vector<vector<int>> f(1000001, vector<int>(21, 0));
  for (int i = 1; i <= 20; ++i) {
    f[0][i] = 2;
  }
  f[0][0] = 1;
  for (int i = 1; i <= 1000000; ++i) {
    f[i][0] = 1;
    for (int j = 1; j <= 20; ++j) {
      f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mod;
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int r, n;
    scanf("%d%d", &r, &n);
    if (r == 0) {
      printf("%d\n", 1 << a[n]);
    } else {
      long long ans = 1;
      for (auto x : c[n]) {
        ans = ans * f[r][x.second] % mod;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
