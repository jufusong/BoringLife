#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  vector<bool> vis(n);
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      vis[i] = true;
      int cnt = 1;
      for (int j = a[i]; !vis[j]; j = a[j]) {
        vis[j] = true;
        cnt++;
      }
      vec.push_back(cnt);
    }
  }
  sort(vec.begin(), vec.end());
  if (vec.size() >= 2) {
    int t = vec.back();
    vec.pop_back();
    vec.back() += t;
  }
  ll ans = 0;
  for (auto x : vec) {
    ans += (ll)x * x;
  }
  cout << ans << endl;
  return 0;
}
