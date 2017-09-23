#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, C, U, x1, x2;
  cin >> n >> C >> x1 >> U >> x2;
  int mx = 0;
  for (int i = 0; i <= n; i++) {
    int now = C, nx = x1, cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (cnt < i && now >= U) {
        cnt++, now -= U, nx += x2;
      }
      now += nx;
    }
    mx = max(mx, now);
  }
  cout << mx << endl;
  return 0;
}
