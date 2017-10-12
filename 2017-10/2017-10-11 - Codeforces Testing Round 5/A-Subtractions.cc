#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    function<int(int, int)> gcd = [&](int x, int y) {
      return y ? x / y + gcd(y, x % y) : 0;
    };
    cout << gcd(a, b) << endl;
  }
  return 0;
}
