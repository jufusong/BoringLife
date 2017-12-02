#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

std::vector<int> preInverse(int n, int md) {
  std::vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (long long)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}

struct Binomial {
  int n, md;
  std::vector<int> factorial, inv_factorial;
  Binomial(int n, int mod) : n(n), md(mod) {
    factorial.resize(n + 1);
    inv_factorial = preInverse(n, md);
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factorial[i] = (long long)factorial[i - 1] * i % md;
      inv_factorial[i] = (long long)inv_factorial[i - 1] * inv_factorial[i] % md;
    }
  }
  int choose(int n, int k) {
    if (k > n) return 0;
    return (long long)factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] % md;
  }
}bn(100005, mod);

int main(int argc, char *argv[]) {
  int n, K;
  string s;
  cin >> n >> K >> s;
  reverse(s.begin(), s.end());
  long long  now = 1, ans = 0, S = 0;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    ans = (ans + now * (c - '0') % mod * bn.choose(n - 1 - i, K)) % mod;
    now = now * 10 % mod;
  }
  if (K == 0) {
    cout << ans << endl;
    return 0;
  }
  now = 1;
  for (int i = 1; i < n; ++i) {
    S = (S + now * bn.choose(n - 1 - i, K - 1)) % mod;
    ans = (ans + S * (s[i] - '0')) % mod;
    now = now * 10 % mod;
  }
  cout << ans << endl;
  return 0;
}
