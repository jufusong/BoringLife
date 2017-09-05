#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  vector<vector<ll>> a(1000001);
  for (int i = 0, t; i < n; i++) {
    scanf("%d", &t);
    a[t].push_back(i);
  }
  ll ans = 0;
  for (int i = 1; i <= 1000000; i++) {
    ll now = 0, sum = (ll)n * n;
    ans += (ll)n * n;
    for (auto x : a[i]) {
      ans -= (x - now) * (x - now);
      now = x + 1;
    }
    ans -= (n - now) * (n - now);
  }
  printf("%.10f\n", 1.0 * ans / ((ll)n * n));
  return 0;
}
