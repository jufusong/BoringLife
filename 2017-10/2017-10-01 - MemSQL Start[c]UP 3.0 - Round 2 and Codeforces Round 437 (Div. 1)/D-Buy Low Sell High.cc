#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1e16;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  ll ans = 0;
  multiset<int> s1, s2;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    ll x = s1.empty() ? inf : *s1.begin();
    ll y = s2.empty() ? inf : *s2.begin();
    if (x < y) {
      if (x < v) {
        ans += v - x;
        s2.insert(v);
        s1.erase(s1.begin());
      } else {
        s1.insert(v);
      }
    } else {
      if (y < v) {
        ans += v - y;
        s2.insert(v);
        s2.erase(s2.begin());
        s1.insert(y);
      } else {
        s1.insert(v);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
