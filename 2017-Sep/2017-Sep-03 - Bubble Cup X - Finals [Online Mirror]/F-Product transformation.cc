#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll factorial[N], mod;

void init() {
  factorial[0] = 1;
  for (int i = 1; i < N; i++) {
    factorial[i] = factorial[i - 1] * i % mod;
  }
}

ll powMod(ll n, ll m, ll mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = n * n % mod) {
    if (m & 1) ans = ans * n % mod;
  }
  return ans;
}

ll C(int n, int k) {
  return factorial[n] * powMod(factorial[k], mod - 2, mod) % mod *
    powMod(factorial[n - k], mod - 2, mod) % mod;
}

int main(int argc, char *argv[]) {

  
  return 0;
}
