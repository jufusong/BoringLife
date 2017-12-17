#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    [](int n) {
      for (int i = 0; i < 100; i++) {
        if (n >= 3 * i && (n - 3 * i) % 7 == 0) {
          cout << "YES" << endl;
          return;
        }
      }
      cout << "NO" << endl;
    }(n);
  }
  return 0;
}
