#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  ll n, m;
  while (cin >> n >> m) {
    if (n < m) swap(n, m);
    ll gcd = __gcd(n - 1, m - 1);
    ll k = (m - 1) / gcd;
    ll x = (n - 1) / gcd;
    ll ans = (k - 1) * (m - k + 1) + (x - k + 1) * (m - k);
    cout << ans + 1 << endl;
  }
  return 0;
}
