#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  int p = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (abs(a[i]) > abs(a[p])) {
      p = i;
    }
  }
  cout << 2 * n - 1 << endl;
  for (int i = 0; i < n; i++) {
    cout << p + 1 << " " << i + 1 << endl;
  }
  if (a[p] < 0) {
    for (int i = n - 1; i >= 1; i--) {
      cout << i + 1 << " " << i << endl;
    }
  } else {
    for (int i = 2; i <= n; i++) {
      cout << i - 1 << " " << i << endl;
    }
  }
  return 0;
}
