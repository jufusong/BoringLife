#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  int mn = 1e9, sum = 0;;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mn = min(mn, abs(a[i]));
  }
  sort(a.begin(), a.end());
  for (int i = 0; K && i < n; i++) {
    if (a[i] < 0) {
      K--;
      sum -= 2 * a[i];
    }
  }
  if (K & 1) {
    sum -= 2 * mn;
  }
  cout << sum << endl;
  return 0;
}
