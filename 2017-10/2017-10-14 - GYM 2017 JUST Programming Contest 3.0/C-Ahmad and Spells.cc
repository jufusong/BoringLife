#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll n, m, K, X, S;
    scanf("%lld%lld%lld%lld%lld", &n, &m, &K, &X, &S);
    vector<pair<ll, ll>> a(m);
    for (int i = 0; i < m; i++) {
      scanf("%lld", &a[i].second);
    }
    for (int i = 0; i < m; i++) {
      scanf("%lld", &a[i].first);
    }
    vector<pair<ll, ll>> b(K);
    for (int i = 0; i < K; i++) {
      scanf("%lld", &b[i].second);
    }
    for (int i = 0; i < K; i++) {
      scanf("%lld", &b[i].first);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 1; i < m; i++) {
      a[i].second = min(a[i].second, a[i - 1].second);
    }
    for (int i = 1; i < K; i++) {
      b[i].second = max(b[i].second, b[i - 1].second);
    }
    ll ans = n * X;
    for (int i = 0; i < K; i++) {
      if (b[i].first <= S) {
        ans = min(ans, (n - b[i].second) * X);
      }
    }
    for (int i = 0, h = K - 1; i < m && a[i].first <= S; i++) {
      while (h >= 0 && a[i].first + b[h].first > S) h--;
      if (h >= 0) {
        ans = min(ans, (n - b[h].second) * a[i].second);
      } else {
        ans = min(ans, n * a[i].second);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
