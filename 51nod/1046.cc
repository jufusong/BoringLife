#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll powMod(ll x, ll y, ll z) {
  ll ret = 1;
  for (; y; y >>= 1, x = x * x % z) {
    if (y & 1) ret = ret * x % z;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  cout << powMod(a, b, c) << endl;
  return 0;
}
