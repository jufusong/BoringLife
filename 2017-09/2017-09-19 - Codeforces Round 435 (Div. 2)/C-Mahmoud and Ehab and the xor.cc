#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, x;
  cin >> n >> x;
  if (n == 1) {
    cout << "YES" << endl;
    cout << x << endl;
    return 0;
  }
  if (x == 0 && n == 2) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  int now = (1 << 19) - 1;
  int t = now;
  cout << (1 << 19) - 1 << " ";
  for (int i = 0; i < n - 3; i++) {
    cout << i << " ";
    now ^= i;
  }
  if (n > 2) {
    if (t == (now ^ x ^ (n - 3))) {
      cout << n - 2 << " ";
      now ^= (n - 2);
    } else {
      cout << n - 3 << " ";
      now ^= (n - 3);
    }
  }
  cout << (now ^ x) << endl;
  return 0;
}
