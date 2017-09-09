#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  auto cal = [](int n) {
    return n * (n - 1) * (n - 2) / 6;
  };
  auto cal1 = [&cal](int n) {
    return cal(n / 2) + cal(n -n / 2);
  };
  auto cal2 = [&cal, &cal1](int n) {
    int x = cal1(n);
    for (int i = 1; i < n; i++) {
      x = min(x, cal(i) + cal(n - i));
    }
    return x;
  };
  auto cal3 = [&cal](int n) {
    int x = n / 3;
    int y = (n - x) / 2;
    int z = n - x - y;
    return x * y * z + cal(x) + cal(y) + cal(z);
  };
  for (int i = 1; i <= 500; i++) {
    if (cal1(i) != cal2(i)) {
      cout << i << endl;
    }
    if (cal3(i) < cal2(i)) {
      cout << i << endl;
    }
  }
  return 0;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int m = n / 2;

    cout << cal1(n) << " " << cal2(n) << endl;
    /*    cout << cal(m) + cal(n - m) << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) cout << 0;
        else {
          if ((i <= m) ^ (j <= m)) {
            cout << 1;
          } else {
            cout << 2;
          }
        }
        if (j != n) cout << ' ';
        else cout << endl;
      }
      }*/
  }
  return 0;
}
