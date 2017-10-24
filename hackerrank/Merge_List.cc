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
}bi(201, mod);

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    cout << bi.choose(n + m, n) << endl;
  }
  return 0;
}
