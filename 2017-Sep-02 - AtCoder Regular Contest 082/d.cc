#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int cnt = 0, ans = 0;
  for (int i = 1, t; i <= n; i++) {
    cin >> t;
    if (t == i) {
      cnt++;
    } else {
      ans += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  ans += (cnt + 1) / 2;
  cout << ans << endl;
  return 0;
}
