#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  string s = to_string(n);
  int t = s[0] - '0' + 1;
  for (int i = 1; i < s.size(); t *= 10, i++);
  cout << t - n << endl;
  return 0;
}
