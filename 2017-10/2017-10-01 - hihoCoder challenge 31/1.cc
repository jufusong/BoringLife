#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = a.back() - a[0];
  if (k >= n) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = n - 1; i >= 1; i--) {
    a[i] -= a[i - 1];
  }
  sort(a.begin() + 1, a.end(), greater<int>());
  for (int i = 1; i < k; i++) {
    ans -= a[i];
  }
  cout << ans << endl;
  return 0;
}
