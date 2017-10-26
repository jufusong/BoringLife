#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n, X;
  cin >> n >> X;
  vector<int> a(n);
  multiset<ll> se;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    se.insert(a[i]);
  }
  vector<int> ans;
  ans.push_back(*se.begin());
  se.erase(se.begin());
  int h = 0;
  ll now = 0;
  for (int i = 1; i < n; i++) {
    ll v = max(0LL, now * n - 1) / i + 1;
    auto it = se.lower_bound(v);
    if (now < X) {
      if (it != se.end()) {
        now++;
        ans.push_back(*it);
        se.erase(it);
      } else {
        ans.push_back(*se.begin());
        se.erase(se.begin());
      }
    } else {
      if (it != se.begin()) {
        --it;
        ans.push_back(*it);
        se.erase(it);
      } else {
        auto ix = se.end();
        --ix;
        int vv = *ix;
        se.erase(ix);
        if (h < i) {
          se.insert(ans[h]);
          ans[h++] = vv;
          i--;
        } else {
          ans.push_back(vv);
        }
      }
    }
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  return 0;
}
