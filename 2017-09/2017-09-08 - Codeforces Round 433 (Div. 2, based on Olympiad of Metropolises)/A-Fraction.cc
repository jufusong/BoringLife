#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = n / 2; i >= 1; i--) {
    if (__gcd(i, n - i) == 1) {
      cout << i << " " << n - i << endl;
      break;
    }
  }
  return 0;
}
