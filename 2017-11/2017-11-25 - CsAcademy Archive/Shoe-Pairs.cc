#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<int, int> mp1, mp2;
  for (int i = 0; i < n; i++) {
    int t;
    string s;
    cin >> t >> s;
    if (s[0] == 'L') {
      mp1[t]++;
    } else {
      mp2[t]++;
    }
  }
  int ans = 0;
  for (auto e : mp1) {
    ans += min(e.second, mp2[e.first]);
  }
  cout << ans << endl;
  return 0;
}
