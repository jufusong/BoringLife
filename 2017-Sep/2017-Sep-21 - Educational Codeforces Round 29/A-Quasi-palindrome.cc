#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  auto check = [](string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
  };
  for (int i = 0; i < 20; i++) {
    if (check(s)) {
      cout << "YES" << endl;
      return 0;
    }
    s = '0' + s;
  }
  cout << "NO" << endl;
  return 0;
}
