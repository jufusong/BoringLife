#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 777777777;

int main(int argc, char *argv[]) {
  vector<vector<ll>> C(1001, vector<ll>(1001));
  for (int i = 0; i <= 1000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  for (int n = 1; n <= 1 << 8; n <<= 1) {
    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    f[0][0][0] = 1;
    auto add = [](ll &x, ll y) { x = (x + y) % mod; };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= j; k++) {
          for (int h = 0; j + h <= n; h++) {
            if (h == i + 1) {
              add(f[i + 1][j + h][k], f[i][j][k] * C[n - j][h]);
            } else {
              add(f[i + 1][j + h][k + h], f[i][j][k] * C[n - j][h]);
            }
          }
        }
      }
    }
    printf("a[%d] = {", n);
    for (int i = 0; i <= n; i++) {
      if (i) putchar(',');
      printf("%lld", f[n][n][i]);
    }
    printf("};\n");
  }
  return 0;
}
