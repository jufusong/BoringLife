#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

struct A{
  int& x;
  A(){}
};

ll powMod(ll x, ll y, ll z = mod) {
  ll ret = 1;
  for (; y; y >>= 1, x = x * x % z) {
    if (y & 1) ret = ret * x % z;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (n == 1) cout << m << endl;
    else {
      cout << (ll)m * (m - 1) % mod * powMod(m - 2, n - 2) % mod << endl;
    }
  }
  return 0;
}
