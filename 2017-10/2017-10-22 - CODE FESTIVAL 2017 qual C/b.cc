#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> f(n + 1, vector<int>(2));
  f[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    for (int j = t - 1; j <= t + 1; j++) {
      if (j & 1) {
        f[i][1] += f[i - 1][1];
        f[i][0] += f[i - 1][0];
      } else {
        f[i][0] += f[i - 1][1] + f[i - 1][0];
      }
    }
  }
  cout << f[n][0] << endl;
  return 0;
}
