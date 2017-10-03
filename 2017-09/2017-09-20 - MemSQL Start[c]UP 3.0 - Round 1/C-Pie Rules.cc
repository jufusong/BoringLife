#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  b[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    b[i] = max(b[i + 1] - a[i], -b[i + 1] + a[i]);
  }
  cout << (sum - b[0]) / 2 << " " << (sum + b[0]) / 2 << endl;
  return 0;
}
