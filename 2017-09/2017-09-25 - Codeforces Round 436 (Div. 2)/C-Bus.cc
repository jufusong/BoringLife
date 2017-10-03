#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int a, b, f, k, cnt = 0;
  cin >> a >> b >> f >> k;
  auto ee = []() {
    cout << -1 << endl;
    exit(0);
  };
  auto solve = [&a, &b, &cnt, &ee](int f, int& now) {
    if (now >= a) now -= a;
    else {
      if (now < f) {
        cnt++;
        now = b - f;
        if (now < f) ee();
      }
      if (now >= a) now -= a;
      else {
        now = b - (a - f);
        cnt++;
        if (now < 0) ee();
      }
    }
  };
  for (int i = 1, now = b; i <= k; i++) {
    if (i & 1) {
      solve(f, now);
    } else {
      solve(a - f, now);
    }
  }
  cout << cnt << endl;
  return 0;
}
