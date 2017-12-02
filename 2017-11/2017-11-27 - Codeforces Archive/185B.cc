#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

int main(int argc, char *argv[]) {
  double S, a, b, c;
  cin >> S >> a >> b >> c;
  a += eps, b += eps, c += eps;
  double x1, x2;
  double l = 0, r = S;
  for (int i = 0; i < 200; i++) {
    double m1 = (l + r) / 2, m2 = (m1 + r) / 2;
    auto cal = [&x2](double b, double c, double S) {
      double l = eps, r = S - eps;
      for (int i = 0; i < 200; ++i) {
        double m1 = (l + r) / 2, m2 = (m1 + r) / 2;
        if (b * log(m1) + c * log(S - m1) < b * log(m2) + c * log(S - m2)) l = m1;
        else r = m2;
      }
      x2 = l;
      return b * log(l) + c * log(S - l);
    };
    if (a * log(m1) + cal(b, c, S - m1) < a * log(m2) + cal(b, c, S - m2)) l = m1;
    else r = m2;
    x1 = l;
  }
  printf("%.10f %.10f %.10f\n", x1, x2, S - x1 - x2);
  return 0;
}
