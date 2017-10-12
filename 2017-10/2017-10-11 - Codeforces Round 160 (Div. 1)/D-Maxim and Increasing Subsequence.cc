#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T, n, maxb, t;
  cin >> T >> n >> maxb >> t;
  t = min(t, min(maxb, n));
  while (T--) {
    vector<int> a(n), b(maxb + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < t; i++) {
      for (auto x : a) {
        b[x] = b[x - 1] + 1;
        for (int j = x + 1; j <= maxb && b[x] > b[j]; j++) {
          b[j] = b[x];
        }
      }
    }
    cout << b[maxb] << endl;
  }
  return 0;
}
