#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  int sz = set<char>(s.begin(), s.end()).size();
  map<int, int> mp;
  int ans = n, cnt = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && cnt < sz) {
      if (!mp[s[j]]) cnt++;
      mp[s[j]]++;
      j++;
    }
    if (cnt == sz) {
      ans = min(ans, j - i);
    }
    if (mp[s[i]] == 1) {
      cnt--;
    }
    mp[s[i]]--;
  }
  cout << ans << endl;
  return 0;
}
