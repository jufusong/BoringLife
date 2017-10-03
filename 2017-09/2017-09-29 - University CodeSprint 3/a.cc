#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int x = s[0] - '0', y = s[2] - '0';
  if (s[1] == '-') {
    cout << x - y << endl;
  } else {
    cout << x + y << endl;
  }
  return 0;
}
