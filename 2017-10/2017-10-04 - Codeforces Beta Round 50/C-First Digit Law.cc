#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<double> a(n + 1);
  auto cal = [](ll x) {
    if (x == 0) return 0LL;
    string s = to_string(x);
    ll ret = 0;
    for (ll i = 0, b = 1; i < s.size(); i++, b *= 10) {
      if (i == s.size() - 1 && s[0] == '1') {
        ret += x - b + 1;
      } else {
        ret += b;
      }
    }
    return ret;
  };
  for (int i = 1; i <= n; i++) {
    ll x, y;
    cin >> x >> y;
    a[i] = (cal(y) - cal(x - 1)) * 1.0 / (y - x + 1);
  }
  vector<vector<double>> f(n + 1, vector<double>(n + 1));
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      f[i + 1][j] += f[i][j] * (1 - a[i + 1]);
      f[i + 1][j + 1] = f[i][j] * a[i + 1];
    }
  }
  int K;
  cin >> K;
  double ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i * 100 >= n * K) {
      ans += f[n][i];
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
