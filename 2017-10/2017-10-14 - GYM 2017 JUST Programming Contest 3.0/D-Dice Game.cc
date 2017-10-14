#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  vector<vector<int>> f(10001, vector<int>(7, inf));
  f[0][1] = 0;
  for (int i = 1; i <= 10000; i++) {
    for (int j = 1; j <= 6 && i - j >= 0; j++) {
      for (int k = 1; k <= 6; k++) {
        if (k + j != 7 && k != j) {
          f[i][j] = min(f[i][j], f[i - j][k] + 1);
        }
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = inf;
    for (int i = 1; i <= 6; i++) {
      ans = min(ans, f[n][i]);
    }
    cout << (ans == inf ? -1 : ans) << endl;
  }
  return 0;
}
