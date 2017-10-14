#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].first, &a[i].second);
      mp[a[i].first]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += mp[a[i].second];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
