#include <bits/stdc++.h>

using namespace std;

int f[500005][5];

int main(int argc, char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  s += '0';
  vector<int> a;
  for (int i = 0, cnt = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      cnt++;
    } else {
      a.push_back(cnt);
      cnt = 0;
    }
  }
  for (int i = 1; i < a.size(); i++) {
    f[i][0] = max(max(f[i - 1][0], f[i - 1][3]), max(f[i - 1][1], f[i - 1][2]));
    if (a[i] && a[i - 1]) {
      f[i][1] = max(f[i - 1][0] + a[i - 1], f[i - 1][1] + a[i - 1] - 1);
      f[i][2] = f[i - 1][0] + a[i] - 1;
      f[i][3] = f[i - 1][0] + a[i];
      if (a[i - 1] >= 2) {
        f[i][2] = max(f[i][2], max(f[i - 1][1] + a[i] - 1, f[i - 1][2] + a[i] - 1));
        f[i][3] = max(f[i][3], max(f[i - 1][1] + a[i], f[i - 1][2] + a[i]));
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < 4; i++) {
    mx = max(mx, f[a.size() - 1][i]);
  }
  cout << mx << endl;
  return 0;
}
