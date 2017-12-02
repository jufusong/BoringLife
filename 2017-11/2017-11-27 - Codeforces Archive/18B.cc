#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n, d, m, l;
  cin >> n >> d >> m >> l;
  for (ll i = 1; i <= n; ++i) {
    ll k = (i - 1) * m + l;
    if (i == n || (k / d + 1) * d < i * m) {
      cout << (k / d + 1) * d << endl;
      return 0;
    }
  }
  return 0;
}
