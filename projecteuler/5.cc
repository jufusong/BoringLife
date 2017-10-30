#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll ans = 1;
  for (ll i = 1; i <= 20; i++) {
    ll g = __gcd(ans, i);
    ans = ans / g * i;
  }
  cout << ans << endl;
  return 0;
}
