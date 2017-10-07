#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  for (auto it = s.begin(); it != s.end(); it++) {
    if (*it == '0') {
      s.erase(it);
      cout << s << endl;
      return 0;
    }
  }
  s.erase(s.begin());
  cout << s << endl;
  return 0;
}
