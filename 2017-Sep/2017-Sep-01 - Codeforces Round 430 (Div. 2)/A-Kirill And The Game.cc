#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  bool flag = false;
  for (ll i = x; i <= y; i++) {
    if (i * k >= l && i * k <= r) {
      flag = true;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}
