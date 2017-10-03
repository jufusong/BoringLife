#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2100000;

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
  if (k > n) return 0;
  return factorial[n] * powMod(factorial[k], mod - 2, mod) % mod *
    powMod(factorial[n - k], mod - 2, mod) % mod;
}

int main(int argc, char *argv[]) {
  int n, m, A, Q;
  cin >> n >> m >> A >> Q;
  mod = 2;
  for (;powMod(A, mod, Q) != 1; mod++);
  init();
  ll sum = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    sum = (sum + C(m, i)) % mod;
    ans[i] = powMod(A, sum, Q);
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans) {
    printf("%d ", x);
  }
  return 0;
}
