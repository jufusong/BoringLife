#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] + a[1] < a[2] || (a[0] + a[1] - a[2]) % 2) {
      cout << -1 << endl;
    } else {
      int x = (a[0] + a[1] - a[2]) / 2;
      printf("0 0 %d 0 %d %d\n", a[2], a[0] - x, x);
    }
  }
  return 0;
}
