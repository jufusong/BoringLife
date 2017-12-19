#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int ans = 0;
  for (int i = 3; i <= 1000; i++) {
    long long x = i - 1, y = i + 1;
    long long sx = 1, sy = 1;
    long long md = i * i;
    long long mx = 0;
    for (int j = 0; j <= i * i; j++) {
      sx = sx * x % md;
      sy = sy * y % md;
      mx = max(mx, (sx + sy) % md);
    }
    ans += mx;
  }
  cout << ans << endl;
  return 0;
}
