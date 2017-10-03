#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int ans = 0, n;
  string s;
  cin >> n >> s;
  s += 'A';
  for (int i = 0, now = 0; i < (int)s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      string t = s.substr(now, i - now);
      ans = max(ans, (int)set<char>(t.begin(), t.end()).size());
      now = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
