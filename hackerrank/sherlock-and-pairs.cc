#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, t; i < n; i++) {
      cin >> t;
      mp[t]++;
    }
    ll ans = 0;
    for (auto e : mp) {
      ans += (ll)e.second * (e.second - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
