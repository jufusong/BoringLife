#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<vector<ll>, vector<ll>> sieve(ll n) {
  ll v = sqrt(n);
  vector<ll> f(v + 1), g(v + 1);
  for (int i = 1; i <= v; i++) {
    f[i] = i - 1;
    g[i] = n / i - 1;
  }
  for (ll p = 2; p <= v; p++) {
    if (f[p] == f[p - 1]) continue;
    for (ll i = 1; i <= v && n / i >= p * p; i++) {
      ll d = n / i / p;
      if (d <= v) {
        g[i] -= (f[d] - f[p - 1]);
      } else {
        d = n / d;
        g[i] -= (g[d] - f[p - 1]);
      }
    }
    for (ll i = v; i >= p * p; i--) {
      f[i] -= (f[i / p] - f[p - 1]);
    }
  }
  return {f, g};
}

int main(int argc, char *argv[]) {
  ll n;
  cin >> n;
  auto ret = sieve(n);
  ll ans = 0;
  for (ll i = 2; i * i * i <= n; i++) {
    if (ret.first[i] != ret.first[i - 1]) {
      ans++;
    }
  }
  for (ll i = 2; i * i <= n; i++) {
    if (ret.first[i] != ret.first[i - 1]) {
      ll d = n / i;
      ll val = 0;
      if (d >= ret.first.size()) {
        val = ret.second[n / d];
      } else {
        val = ret.first[d];
      }
      ans += val - ret.first[i];
    }
  }
  cout << ans << endl;
  return 0;
}
