#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  ll mx = 1e16;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (ll j = i - 1, k = 0; j >= 0; j--) {
      sum += a[i].first - a[j].second - k;
      k += a[j].second - a[j].first;
    }
    for (ll j = i + 1, k = 0; j < n; j++) {
      sum += a[j].first - a[i].second - k;
      k += a[j].second - a[j].first;
    }
    mx = min(mx, sum);
  }
  cout << mx << endl;
  return 0;
}
