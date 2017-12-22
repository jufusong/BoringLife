#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    ok &= (a[i] == 1 || a[i - 1] == 1);
  }
  if (ok) {
    cout << "perfect" << endl;
  } else {
    cout << "ambiguous" << endl;
    for (int i = 1; i <= n; i++) {
      a[i] += a[i - 1];
    }
    vector<int> b(1, 0), c(1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = a[i - 1] + 1; j <= a[i]; j++) {
        b.push_back(a[i - 1]);
        int sz = 0;
        if (i == 1) sz = 1;
        else sz = a[i - 1] - a[i - 2];
        if ((j & 1) && (sz != 1)) {
          c.push_back(a[i - 1] - 1);
        } else {
          c.push_back(a[i - 1]);
        }
      }
    }
    for (auto x : b) {
      cout << x << " ";
    }
    cout << endl;
    for (auto x : c) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
