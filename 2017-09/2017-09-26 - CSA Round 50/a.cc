#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int x = 0, y = 0;
  for (auto c : s) {
    if (c == 'N') {
      x--;
    }
    if (c == 'S') {
      x++;
    }
    if (c == 'W') {
      y--;
    }
    if (c == 'E') {
      y++;
    }
  }
  cout << abs(x) + abs(y) << endl;
  return 0;
}
