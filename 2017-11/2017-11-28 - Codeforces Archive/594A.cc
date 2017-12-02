#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mx = a[n / 2] - a[0];
  for (int i = 0; i < n - n / 2; ++i) {
    mx = min(mx, a[i + n / 2] - a[i]);
  }
  cout << mx << endl;
  return 0;
}
