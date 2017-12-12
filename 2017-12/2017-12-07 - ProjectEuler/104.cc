#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9;

int main(int argc, char *argv[]) {
  long long f1 = 1, f2 = 1;
  auto check = [](long long x) {
    string s = to_string(x);
    set<char> se(s.begin(), s.end());
    return !se.count('0') && se.size() == 9;
  };
  for (int i = 3; ; ++i) {
    long long f3 = (f1 + f2) % mod;
    if (check(f3)) {
      long double s5 = sqrtl(5);
      long double v = (i * log(0.5 + s5 / 2)) - log(s5);
      long long x = 0;
      int len = v / log(10);
      x = exp(v - (len - 8) * log(10));
      if (check(x)) {
        cout << i << endl;
        break;
      }
    }
    f1 = f2, f2 = f3;
  }
  return 0;
}
