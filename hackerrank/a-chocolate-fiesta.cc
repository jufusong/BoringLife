#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> f(n + 1, vector<int>(2));
  f[0][0] = 1;
  for (int i = 1, t; i <= n; i++) {
    cin >> t;
    t %= 2;
    f[i][1] = (f[i - 1][t ^ 1] + f[i - 1][1]) % mod;
    f[i][0] = (f[i - 1][t] + f[i - 1][0]) % mod;
  }
  cout << (f[n][0] + mod - 1) % mod << endl;
  return 0;
}
