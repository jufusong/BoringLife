#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  vector<ll> vb(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    vb[i] = vb[i + 1] + c.end() - upper_bound(c.begin(), c.end(), b[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += vb[upper_bound(b.begin(), b.end(), a[i]) - b.begin()];
  }
  cout << ans << endl;
  return 0;
}
