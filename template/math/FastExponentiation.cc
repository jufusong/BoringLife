

typedef long long ll;
const int mod = 1e9 + 7;

ll powMod(ll n, ll m, ll md = mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = n * n % md) {
    if (m & 1) ans = ans * n % md;
  }
  return ans;
}

