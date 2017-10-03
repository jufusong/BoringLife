#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  cout << (s.size() >= 4 && s.substr(0, 4) == "YAKI" ? "Yes" : "No") << endl;
  return 0;
}
