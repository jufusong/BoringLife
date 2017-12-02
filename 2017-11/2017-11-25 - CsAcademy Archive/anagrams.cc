#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<vector<int>, int> mp;
  for (int i = 0; i < n; i++) {
    vector<int> a(26);
    string s;
    cin >> s;
    for (auto c : s) {
      a[c - 'a']++;
    }
    mp[a]++;
  }
  int ans = 0;
  for (auto e : mp) {
    ans = max(ans, e.second);
  }
  cout << ans << endl;
  return 0;
}
