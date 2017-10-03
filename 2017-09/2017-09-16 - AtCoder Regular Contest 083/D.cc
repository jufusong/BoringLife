#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  bool flag = true;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool ff = true;
      for (int k = 0; k < n; k++) {
        if (k != i && k != j) {
          if (a[i][j] > a[i][k] + a[k][j]) flag = false;
          if (a[i][j] == a[i][k] + a[k][j]) ff = false;
        }
      }
      if (ff) ans += a[i][j];
    }
  }
  cout << (flag ? ans : -1) << endl;
  return 0;
}
