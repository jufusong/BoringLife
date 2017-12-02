#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  int a = 0, b = 0;
  cin >> s;
  for (auto c : s) {
    if (c == 'N') a++;
    if (c == 'S') a--;
    if (c == 'W') b++;
    if (c == 'E') b--;
  }
  cout << abs(a) + abs(b) << endl;
  return 0;
}
