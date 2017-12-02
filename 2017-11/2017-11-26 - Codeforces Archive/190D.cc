#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  map<int, deque<int>> mp;
  ll ans = 0;
  for (int i = 0, mx = -1; i < n; ++i) {
    cin >> a[i];
    mp[a[i]].push_back(i);
    if (mp[a[i]].size() >= k) {
      mx = max(mx, mp[a[i]][0]);
      mp[a[i]].pop_front();
    }
    ans += mx + 1;
  }
  cout << ans << endl;
  return 0;
}
