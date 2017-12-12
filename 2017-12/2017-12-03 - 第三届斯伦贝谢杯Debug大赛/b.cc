#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(int argc, char *argv[]) {
  int n, A, B;
  while (~scanf("%d%d%d", &n, &A, &B)) {
    vector<int> a(n + 2);
    for (int i = 0; i < A; ++i) {
      int l, r;
      long long c;
      scanf("%d%d%lld", &l, &r, &c);
      c %= mod;
      a[l] = (a[l] + c) % mod;
      a[r + 1] = (a[r + 1] + mod - c) % mod;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = (a[i] + a[i - 1]) % mod;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = (a[i] + a[i - 1]) % mod;
    }
    for (int i = 0; i < B; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", (a[r] - a[l - 1] + mod) % mod);
    }
  }
  return 0;
}
