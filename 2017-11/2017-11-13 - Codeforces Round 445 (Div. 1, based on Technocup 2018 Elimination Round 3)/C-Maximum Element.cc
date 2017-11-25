#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

vector<int> preInverse(int n, int md = mod) {
  vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (ll)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}

struct Binomial {
  int n, md;
  vector<int> factorial, inv_factorial;
  Binomial(int n, int mod) : n(n), md(mod) {
    factorial.resize(n + 1);
    inv_factorial = preInverse(n, md);
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factorial[i] = (ll)factorial[i - 1] * i % md;
      inv_factorial[i] = (ll)inv_factorial[i - 1] * inv_factorial[i] % md;
    }
  }
  int choose(int n, int k) {
    if (k > n) return 0;
    return (ll)factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] % md;
  }
}b(1e6 + 5, mod);

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<ll> f(n + 1);
  ll ans = b.factorial[n];
  for (int i = 0; i < n; i++) {
    if (i <= k) {
      f[i] = b.factorial[n - 1];
    } else {
      int j = i - k - 1;
      f[i] = f[j] * b.choose(n - 1 - j, k + 1) % mod * b.factorial[k] % mod * b.factorial[n - 1 - i - k] % mod * b.inv_factorial[n - 1 - j] % mod;
      f[i] = (f[i - 1] - f[i] + mod) % mod;
    }
    //    cout << f[i] << endl;
    ans = (ans - f[i] + mod) % mod;
  }
  cout << ans << endl;
  return 0;
}
