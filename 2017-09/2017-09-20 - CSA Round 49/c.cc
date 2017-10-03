#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<int> cnt(255);
  for (auto c : s) {
    cnt[c]++;
  }
  int mx = cnt['a'];
  for (int i = 'b'; i <= 'z'; i++) {
    if (cnt[i] > mx) {
      mx = cnt[i];
    }
  }
  auto cal = [&s](int mx) {
    vector<int> a;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == mx) {
        a.push_back(i);
      }
    }
    string t;
    for (;;) {
      t += s[a[0]];
      if (a.back() == (int)s.size() - 1) {
        break;
      }
      a[0]++;
      bool flag = true;
      for (int i = 1; i < (int)a.size(); i++) {
        if (s[a[i] + 1] == s[a[0]]) {
          a[i]++;
        } else {
          flag = false;
        }
      }
      if (!flag)
        break;
    }
    return t;
  };
  string ans;
  for (int i = 'a'; i <= 'z'; i++) {
    if (cnt[i] == mx) {
      string s = cal(i);
      if (s.size() > ans.size()) ans = s;
    }
  }
  cout << ans << endl;
  return 0;
}
