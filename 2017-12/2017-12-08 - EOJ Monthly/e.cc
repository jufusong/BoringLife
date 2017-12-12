#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main(int argc, char *argv[]) {
  int n, x, K;
  cin >> n >> x >> K;
  K--;
  vector<int> a(n + 1, 0);
  a[0] = 1;
  for (int i = x; i <= n; i++) {
    if (i * K >= n) {
      for (int j = i; j <= n; j++) {
        a[j] += a[j - i];
        if (a[j] >= mod) a[j] -= mod;
      }
    } else {
      for (int j = n; j >= i; j--) {
        for (int k = 1; i * k <= j && k <= K; k++) {
          a[j] += a[j - i * k];
          if (a[j] >= mod) a[j] -= mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i];
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
  return 0;
}
