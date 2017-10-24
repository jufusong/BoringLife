#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<pair<int, int>> v1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != 'x') {
      v1.push_back({s[i], i});
    }
  }
  auto v2 = v1;
  reverse(v2.begin(), v2.end());
  for (int i = 0; i < v1.size(); ++i) {
    if (v1[i].first != v2[i].first) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (v1.empty()) {
    cout << 0 << endl;
    return 0;
  }
  int n = s.size();
  int ans = max(v1[0].second, n - v2[0].second - 1) * 2 + 1;
  for (int i = 1; i < v1.size(); i++) {
    ans += max(v1[i].second - v1[i - 1].second, -v2[i].second + v2[i - 1].second);
  }
  cout << ans - n << endl;
  return 0;
}
