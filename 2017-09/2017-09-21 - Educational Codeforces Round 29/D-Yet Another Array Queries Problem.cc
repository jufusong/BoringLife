#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, q, m;
  cin >> n >> q >> m;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<tuple<int, int, int>> a;
  for (int i = 0, t, l, r; i < q; i++) {
    cin >> t >> l >> r;
    a.push_back({t, l, r});
  }
  reverse(a.begin(), a.end());
  for (int i = 0, k; i < m; i++) {
    cin >> k;
    for (auto e : a) {
      int t, l, r;
      tie(t, l, r) = e;
      if (k >= l && k <= r) {
        if (t == 1) {
          k = (k == l ? r : k - 1);
        } else {
          k = l + r - k;
        }
      }
    }
    cout << c[k - 1] << " ";
  }
  return 0;
}
