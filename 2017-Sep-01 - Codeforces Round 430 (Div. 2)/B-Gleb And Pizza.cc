#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int R, d, n, cnt = 0;
  cin >> R >> d >> n;
  d = R - d;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    if (x * x + y * y >= (d + r) * (d + r) && x * x + y * y <= (R - r) * (R - r)) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
