#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int f[10][10][10];

int main(int argc, char *argv[]) {
  for (int i = 0; i <= 9; i++) {
    f[0][i][i == 4 || i == 7]++;
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = (j == 4 || j == 7); k <= 9; k++) {
        for (int z = 0; z <= 9; z++) {
          f[i][j][k] += f[i - 1][z][k - (j == 4 || j == 7)];
        }
      }
    }
  }
  vector<int> a(10);
  int m;
  cin >> m;
  string s = to_string(m + 1);
  for (int i = 0; i < s.size() - 1; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        a[k] += f[i][j][k];
      }
    }
  }
  for (int i = 0, x = 0; i < s.size(); i++) {
    for (int j = (i == 0); j < s[i] - '0'; j++) {
      for (int k = x; k <= 9; k++) {
        a[k] += f[s.size() - i - 1][j][k - x];
      }
    }
    x += (s[i] == '4' || s[i] == '7');
  }
  int ans = 0;
  function<void(int, int, int)> dfs = [&](int p, int sum, int v) {
    if (p == 7) {
      if (sum < 0) {
        ans = (ans + v) % mod;
      }
      return;
    }
    for (int i = 0; i < 10; i++) {
      if (a[i] > 0) {
        ll t = (ll)v * a[i] % mod;
        a[i]--;
        dfs(p + 1, sum + (p == 0 ? -1 : 1) * i, t);
        a[i]++;
      }
    }
  };
  dfs(0, 0, 1);
  cout << ans << endl;
  return 0;
}
