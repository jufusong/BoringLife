#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll a, b;
  cin >> a >> b;
  if (b - a > 1000) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  for (ll i = a + 1; i <= b; i++) {
    ans = ans * i % 10;
  }
  cout << ans << endl;
  return 0;
}
