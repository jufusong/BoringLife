#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, cnt = 0;
    cin >> n;
    if (n & 1) {
      if (n < 9) {
        cout << -1 << endl;
        continue;
      }
      n -= 9;
      cnt++;
    }
    if (n < 4 && n != 0) {
      cout << -1 << endl;
      continue;
    }
    cout << cnt + n / 4 << endl;
  }
  return 0;
}
