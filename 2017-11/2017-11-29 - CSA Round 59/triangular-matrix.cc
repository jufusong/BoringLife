#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<bool>> a(n + 1, vector<bool>(n + 1, 0));
  a[0][0] = true;
  vector<string> vec(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> vec[i];
    int mx = 255;
    for (int j = 1; j <= i; ++j) {
      if (a[i - 1][j] || a[i - 1][j - 1]) {
        mx = min(mx, (int)vec[i][j - 1]);
      }
    }
    for (int j = 1; j <= i; ++j) {
      a[i][j] = ((a[i - 1][j] || a[i - 1][j - 1]) && vec[i][j - 1] == mx);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[n][i]) {
      string s;
      s += vec[n][i - 1];
      int now = i;
      for (int j = n - 1; j >= 1; j--) {
        if (!a[j][now]) now--;
        s += vec[j][now - 1];
      }
      reverse(s.begin(), s.end());
      cout << s << endl;
      return 0;
    }
  }
  return 0;
}
