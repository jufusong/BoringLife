#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, r, k;
  cin >> n >> r >> k;
  int x = n, y = 0;
  for (int i = 0; i <= r && i <= k; i++) {
    if (n - r >= k - i) {
      x = min(x, r - i + k - i);
      y = max(y, r - i + k - i);
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
