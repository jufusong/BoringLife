#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  string s;
  for (int i = 'a'; i <= 'z'; i++) {
    int j = 2;
    for (j = 2; j * (j - 1) / 2 <= n; j++);
    j--;
    s += string(j, (char)i);
    n -= j * (j - 1) / 2;
  }
  cout << s << endl;
  return 0;
}
