#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n, m, mod;
  cin >> n >> m >> mod;
  vector<int> a(n, 0);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      a[j] += (s[j] == '1');
    }
  }
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    x += (a[i] == 0);
    y += (a[i] == 1);
  }
  vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
  f[x][y] = 1;
  for (int i = m + 1; i <= n; ++i) {
    for (int k = 0; k <= n && k <= 2 * i; k++) {
      if (!((2 * i - k) & 1)) {
        int j = n - k - (2 * i - k) / 2;
        if (j >= 0) {
          if (k >= 2 && j + 2 <= n) {
            f[j][k] = (f[j][k] + (ll)f[j + 2][k - 2] * ((j + 2) * (j + 1) / 2)) % mod;
          }
          if (k + 2 <= n) {
            f[j][k] = (f[j][k] + (ll)f[j][k + 2] * ((k + 2) * (k + 1) / 2)) % mod;
          }
          if (j + 1 <= n) {
            f[j][k] = (f[j][k] + (ll)f[j + 1][k] * (j + 1) * k) % mod;
          }          
        }
      }
    }
  }
  cout << f[0][0] << endl;
  return 0;
}
