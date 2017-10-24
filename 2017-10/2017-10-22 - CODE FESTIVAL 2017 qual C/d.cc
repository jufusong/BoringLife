#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  map<int, int> mp = {{0, 0}};
  int now = 0, ans = 0;
  for (auto c : s) {
    now ^= (1 << (c - 'a'));
    int x = 1e9;
    if (mp.count(now)) {
      x = mp[now] + 1;
    }
    for (int i = 0; i < 26; i++) {
      int t = (now ^ (1 << i));
      if (mp.count(t)) {
        x = min(x, mp[t] + 1);
      }
    }
    if (mp.count(now)) mp[now] = min(mp[now], x);
    else mp[now] = x;
    ans = x;
  }
  cout << ans << endl;
  return 0;
}
