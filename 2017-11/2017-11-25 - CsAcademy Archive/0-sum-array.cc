#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int ans = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] * 2 == sum) {
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
