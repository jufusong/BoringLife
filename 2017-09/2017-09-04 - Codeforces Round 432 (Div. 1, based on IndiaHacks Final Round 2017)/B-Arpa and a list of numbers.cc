#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  ll x, y;
  cin >> n >> x >> y;
  vector<ll> a(2000005);
  vector<ll> b(2000005);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    a[t]++;
  }
  for (int i = 1; i <= 2000000; i++) {
    b[i] = b[i - 1] + (2000000 - i) * a[i];
    a[i] += a[i - 1];
  }
  ll ans = x * n;
  int K = x / y;
  for (int i = 2; i <= 1000000; i++) {
    ll sum = 0;
    for (int j = 0; j <= 1000000; j += i) {
      int L = min(K, i - 1);
      ll S1 = b[j + i - 1] - b[j + i - 1 - L];
      ll cnt = a[j + i - 1] - a[j + i - 1 - L];
      S1 -= cnt * (2000000 - (j + i));
      sum += S1 * y;
      ll S2 = a[j + i - 1 - L] - a[j];
      sum += S2 * x;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
