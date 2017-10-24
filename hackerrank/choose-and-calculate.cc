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
}bi(1e5, mod);

int main(int argc, char *argv[]) {
  int n, K;
  cin >> n >> K;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + a[i] * (bi.choose(i, K - 1) - bi.choose(n - i - 1, K - 1))) % mod;
  }
  cout << (ans + mod) % mod << endl;
  return 0;
}
