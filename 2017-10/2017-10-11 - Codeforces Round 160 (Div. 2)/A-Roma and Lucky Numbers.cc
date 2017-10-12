#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k, cnt = 0;
  cin >> n >> k;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    int x = 0;
    while (t) {
      x += (t % 10 == 4 || t % 10 == 7);
      t /= 10;
    }
    cnt += (x <= k);
  }
  cout << cnt << endl;
  return 0;
}
