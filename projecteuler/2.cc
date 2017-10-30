#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a(10004);
  int ans = 0;
  a[0] = 1, a[1] = 1;
  for (int i = 2; ; i++) {
    a[i] = a[i - 1] + a[i - 2];
    if (a[i] > 4000000) break;
    if (a[i] % 2 == 0) ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
