#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int x = 0;
  set<char> se;
  for (auto c : s) {
    if (string("aeiou").find(c) != string::npos) {
      x = 0, se.clear();
    } else {
      x++, se.insert(c);
      if (x >= 3 && se.size() > 1) {
        cout << ' ';
        x = 1, se = set<char>{c};
      }
    }
    cout << c;
  }
  return 0;
}
