#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 998244353;

vector<int> PreInverse(int n, int md = mod) {
  vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (ll)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}

struct Binomal {
  int n, md;
  vector<int> factorial, inv_factorial;
  Binomal(int n, int mod) : n(n), md(mod) {
    factorial.resize(n + 1);
    inv_factorial = PreInverse(n, md);
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factorial[i] = (ll)factorial[i - 1] * i % md;
      inv_factorial[i] = (ll)inv_factorial[i - 1] * inv_factorial[i] % md;
    }
  }
  int Choose(int n, int k) {
    if (k > n) return 0;
    return (ll)factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] % md;
  }
};

int main(int argc, char *argv[]) {
  Binomal bn(5000, mod);
  auto cal = [&](int x, int y) {
    ll ans = 0;
    for (int i = 0; i <= x && i <= y; i++) {
      ans = (ans + (ll)bn.Choose(x, i) * bn.Choose(y, i) % mod * bn.factorial[i]) % mod;
    }
    return ans;
  };
  int a, b, c;
  cin >> a >> b >> c;
  cout << cal(a, b) * cal(b, c) % mod * cal(a, c) % mod << endl;
  return 0;
}
