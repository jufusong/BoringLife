#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

int main(int argc, char *argv[]) {
  std::gcd(1, 2);
  int n;
  cin >> n;
  double mx = 2;
  int p = -1;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    if (y / x + eps < mx) {
      p = i + 1;
      mx = y / x + eps;
    }
  }
  cout << p << endl;
  return 0;
}
