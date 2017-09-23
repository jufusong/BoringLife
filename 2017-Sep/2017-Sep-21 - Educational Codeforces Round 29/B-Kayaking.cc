#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  n *= 2;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> b;
      for (int k = 0; k < n; k++) {
        if (k != i && k != j) {
          b.push_back(a[k]);
        }
      }
      sort(b.begin(), b.end());
      int mx = 0;
      for (int k = 0; k < n - 2; k += 2) {
        mx += b[k + 1] - b[k];
      }
      ans = min(ans, mx);
    }
  }
  cout << ans << endl;
  return 0;
}
