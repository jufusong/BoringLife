#include <bits/stdc++.h>

using namespace std;

double eps = 1e-8;

int main(int argc, char *argv[]) {
  int T;
  double R;
  cin >> T >> R;
  vector<double> a(11);
  a[0] = R;
  for (int i = 1; i <= 10; i++) {
    double low = 0.0, high = R;
    for (int j = 0; j < 400; j++) {
      double x = (low + high) / 2;
      double r = a[i - 1];
      if (sqrt(2 * R * x + x * x) + x + r < sqrt(2 * R * r + r * r)) {
        low = x;
      } else {
        high = x;
      }
    }
    a[i] = low;
  }
  while (T--) {
    int k;
    cin >> k;
    printf("%d %.0f\n", k, floor(a[k] + eps));
  }
  return 0;
}
