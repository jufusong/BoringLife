#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 'a'; i <= 'z'; i++) {
    if (count(s.begin(), s.end(), i) == 1) {
      cout << (char)i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
