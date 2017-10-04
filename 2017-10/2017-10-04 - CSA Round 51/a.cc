#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  double minn = 1, p = 0;
  for (int i = 1; i <= n; i++) {
    double x, y;
    cin >> x >> y;
    if (y / x + eps < minn) {
      minn = y / x;
      p = i;
    }
  }
  cout << p << endl;
  return 0;
}
