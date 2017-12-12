#include <bits/stdc++.h>

using namespace std;

int query() {
  int k;
  cin >> k;
  return k;
}

int main(int argc, char *argv[]) {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n + 1);
  int l = 1, r = n;
  for (int i = 1; i <= m; i++) {
    int k = query();
    if (k <= c / 2) {
      if (l == 1 || k >= a[l - 1]) {
        a[l] = k;
        cout << l << endl;
        l++;
      } else {
        auto p = upper_bound(a.begin() + 1, a.begin() + l, k) - a.begin();
        a[p] = k;
        cout << p << endl;
      }
    } else {
      if (r == n || k <= a[r + 1]) {
        a[r] = k;
        cout << r << endl;
        r--;
      } else {
        auto p = lower_bound(a.begin() + r + 1, a.begin() + n + 1, k) - a.begin() - 1;
        a[p] = k;
        cout << p << endl;
      }
    }
    if (l > r) break;
  }
  return 0;
}
