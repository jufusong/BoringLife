#include <bits/stdc++.h>

using namespace std;

int f[101][101];
pair<int, int> pre[101][101];

int main(int argc, char *argv[]) {
  int n, K;
  cin >> n >> K;
  string s;
  cin >> s;
  vector<vector<int>> a(s.size() + 1, vector<int>(K));
  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j < K; j++) {
      for (int k = min((int)s.size(), i + 1); k >= 1; k--) {
        if (s.substr(0, k) == s.substr(i - k + 1, k - 1) + (char)(j + 'a')) {
          a[i][j] = k;
          break;
        }
      }
    }
  }
  vector<int> b(n + 1);
  string t;
  cin >> t;
  for (int i = 1; i <= t.size(); i++) {
    if (t[i - 1] == '1') {
      for (int j = 0; j < s.size(); j++) {
        if (b[j + i] != 0 && b[j + i] != s[j]) {
          cout << "No solution" << endl;
          return 0;
        }
        b[j + i] = s[j];
      }
    }
  }
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s.size(); j++) {
      if (f[i][j]) {
        if (b[i + 1]) {
          f[i + 1][a[j][b[i + 1] - 'a']] = 1;
          pre[i + 1][a[j][b[i + 1] - 'a']] = {j, b[i + 1] - 'a'};
        } else {
          for (int k = 0; k < K; k++) {
            f[i + 1][a[j][k]] = 1;
            pre[i + 1][a[j][k]] = {j, k};
          }
        }
      }
    }
    if (i + 1 >= s.size() && t[i + 1 - s.size()] != '1') {
      f[i + 1][s.size()] = 0;
    }
  }
  int p = -1;
  for (int i = 0; i <= s.size(); i++) {
    if (f[n][i]) {
      p = i;
      break;
    }
  }
  if (p == -1) {
    cout << "No solution" << endl;
    return 0;
  }
  string ans;
  for (int i = n; i >= 1; i--) {
    //    cout << p << endl;
    ans += (char)(pre[i][p].second + 'a');
    assert(f[i][p]);
    p = pre[i][p].first;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
