#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  auto solve = [](string s) {
    bool flag = false;
    for (int i = 0; i < 8; i++) {
      bool t = true;
      for (int j = 1; j < 8; j++) {
        t &= (s[j] != s[j - 1]);
      }
      flag |= t;
    }
    return flag;
  };
  bool flag = true;
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    flag &= solve(s);
  }
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}
