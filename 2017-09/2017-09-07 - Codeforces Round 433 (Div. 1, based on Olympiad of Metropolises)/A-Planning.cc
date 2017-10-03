#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<int> a(n);
  priority_queue<pair<int, int>> q;
  for (int i = 1; i <= n + k; i++) {
    if (i <= n) {
      int x;
      cin >> x;
      q.push({x, i});
    }
    if (i > k) {
      auto u = q.top();
      q.pop();
      ans += (ll)u.first * (i - u.second);
      a[u.second - 1] = i;
    }
  }
  cout << ans << endl;
  for (auto x : a) {
    cout << x << " ";
  }
  return 0;
}
