#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<vector<int>> a(20, vector<int>(20));
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (i + 4 <= 20) {
        ans = max(ans, a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j]);
      }
      if (j + 4 <= 20) {
        ans = max(ans, a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3]);
      }
      if (i + 4 <= 20 && j + 4 <= 20) {
        ans = max(ans, a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3]);
      }
      if (i >= 3 && j + 4 <= 20) {
        ans = max(ans, a[i][j] * a[i-1][j+1] * a[i-2][j+2] * a[i-3][j+3]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
