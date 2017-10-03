#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<ll> b(n + 2), c(n + 2);
  auto d = b, e = b;
  for (int i = 1, now = 0; i <= n; i++) {
    b[i] = b[i - 1];
    if (a[i] <= now) {
      b[i] += now + 1 - a[i];
    }
    now = max(now + 1, a[i]);
    d[i] = now;
  }
  for (int i = n, now = 0; i >= 1; i--) {
    c[i] = c[i + 1];
    if (a[i] <= now) {
      c[i] += now + 1 - a[i];
    }
    now = max(now + 1, a[i]);
    e[i] = now;
  }
  ll ans = 1e18;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, b[i] + c[i + 1]) + (d[i] == e[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
