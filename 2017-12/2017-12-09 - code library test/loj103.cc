#include <bits/stdc++.h>

using namespace std;

vector<int> getFail(string s) {
  vector<int> fail(s.size() + 1);
  fail[0] = -1;
  int p = -1;
  for (int i = 0; i < s.size(); i++) {
    while (p != -1 && s[i] != s[p]) p = fail[p];
    fail[i + 1] = ++p;
  }
  return fail;
}

int main(int argc, char *argv[]) {
  string s, t;
  cin >> s >> t;
  auto fail = getFail(t);
  int cnt = 0, p = 0;
  for (int i = 0; i < s.size(); i++) {
    while (p != -1 && s[i] != t[p]) p = fail[p];
    if (++p == t.size()) {
      cnt++, p = fail[p];
    }
  }
  cout << cnt << endl;
  return 0;
}
