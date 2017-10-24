#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> f(s.size() + 1, vector<int>(t.size() + 1));
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
      else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
  }
  int x = s.size(), y = t.size();
  string z;
  for (;x && y;) {
    if (s[x - 1] == t[y - 1]) {
      z += s[x - 1];
      x--, y--;
    } else {
      if (f[x][y] == f[x - 1][y]) {
        x--;
      } else {
        y--;
      }
    }
  }
  reverse(z.begin(), z.end());
  cout << z << endl;
  return 0;
}
