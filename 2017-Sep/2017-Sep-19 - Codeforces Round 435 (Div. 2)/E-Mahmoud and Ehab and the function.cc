#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e18;

int main(int argc, char *argv[]) {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(m);
  ll s1 = 0;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    if (i & 1) s1 -= t;
    else s1 += t;
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  ll s2 = 0;
  set<ll> se;
  for (int i = 0; i < m; i++) {
    if (i < n - 1) {
      if (i & 1) s2 += a[i];
      else s2 -= a[i];
    } else {
      if (n & 1) s2 -= a[i];
      else s2 += a[i];
      se.insert(s2);
      s2 += a[i - n + 1];
      s2 = -s2;
    }
  }
  auto query = [&se](ll sum) {
    auto it = se.lower_bound(-sum);
    ll ans = inf;
    if (it != se.end()) ans = min(ans, abs(*it + sum));
    if (it != se.begin()) {
      --it;
      ans = min(ans, abs(sum + *it));
    }
    return ans;
  };
  cout << query(s1) << endl;
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    if ((r - l + 1) & 1) {
      if (l & 1) s1 += x;
      else s1 -= x;
    }
    cout << query(s1) << endl;
  }
  return 0;
}
