#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    a += t;
  }
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    b += t;
  }
  cout << (a == b ? 0 : a > b ? 1 : 2) << endl;
  return 0;
}
