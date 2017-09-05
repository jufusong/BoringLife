#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

int main(int argc, char *argv[]) {
  int n, K, cnt = 0;
  cin >> n >> K;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] - eps < 0) cnt++;
  }
  if (n - cnt < K) {
    for (int i = 0; i < n; i++) {
      printf("%.10f ", a[i] - eps < 0 ? 0.0 : 1.0);
    }
    return 0;
  }
  vector<double> dp(1 << n);
  dp[0] = 1;
  vector<double> ans(n);
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) < K) {
      double sum = 0.0;
      for (int j = 0; j < n; j++) {
        if (!((1 << j) & i)) {
          sum += a[j];
        }
      }
      for (int j = 0; j < n; j++) {
        if (!((1 << j) & i)) {
          if (a[j] - eps > 0) {
            dp[(1 << j) | i] += dp[i] * a[j] / sum;
          }
        }
      }
    } else {
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          ans[j] += dp[i];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%.10f ", ans[i]);
  }
  return 0;
}
