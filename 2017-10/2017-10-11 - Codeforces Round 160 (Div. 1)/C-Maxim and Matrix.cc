#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  vector<vector<vector<ll>>> f(2, vector<vector<ll>>(61, vector<ll>(61)));
  f[0][0][0] = f[1][1][0] = 1;
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j <= 60; j++) {
      f[0][j][i] += f[0][j][i - 1] + f[1][j][i - 1];
      if (j) f[1][j][i] += f[1][j - 1][i - 1] + f[0][j - 1][i - 1];
    }
  }
  ll n, t;
  cin >> n >> t;
  int cnt = 1;
  while (t % 2 == 0) {
    t /= 2;
    cnt++;
  }
  if (t != 1) {
    cout << 0 << endl;
    return 0;
  }
  n += 2;
  string s;
  while (n) {
    s += (char)(n % 2 + '0');
    n /= 2;
  }
  ll ans = 0;
  ans -= (cnt == 1 ? 1 : 0);
  for (int i = 0; i + 1 < s.size(); i++) {
    ans += f[1][cnt][i];
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (cnt < 0) break;
    for (int j = (i == s.size() - 1 ? 1 : 0); j < s[i] - '0'; j++) {
      ans += f[j][cnt][i];
    }
    cnt -= (s[i] == '1');
  }
  cout << ans << endl;
  return 0;
}
