#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  while (cin >> n) {
    if (n == 0) {
      cout << "*" << endl;
      return 0;
    }
    vector<int> a(101);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int l, r, k;
      cin >> l >> r >> k;
      for (int j = l; j <= r - 1; j++) {
        a[j] += k;
        ans = max(ans, a[j]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
