#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a;
  int n;
  string s;
  cin >> n >> s;
  cout << (s[0] == 'S' && s.back() == 'F' ? "YES" : "NO") << endl;
  return 0;
}
