#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 2e18;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> vv(1 << n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < 1 << n; i++) {
    ll val = 1, cnt = 0;
    for (int j = 0; j < n; j++) {
      if ((1 << j) & i) {
        ll g = __gcd(val, (ll)a[j]);
        int t = a[j] / g;
        if (inf / val >= t)  val *= t;
        else val = inf;
      }
    }
    vv[i] = val;
  }
  int Q;
  cin >> Q;
  while (Q--) {
    ll L, R;
    cin >> L >> R;
    auto cal = [&vv, &a, &n](ll x) {
      ll ret = 0;
      for (int i = 1; i < 1 << n; i++) {
        ll val = vv[i], cnt = __builtin_popcount(i);
        if (cnt & 1)
          ret += x / val;
        else
          ret -= x / val;
      }
      return ret;
    };
    cout << cal(R) - cal(L - 1) << endl;
  }
  return 0;
}
