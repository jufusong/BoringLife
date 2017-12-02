#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<long long> a(2000001, 0);
  for (int i = 1; i <= 2000000; ++i) {
    string s = to_string(i);
    int s1 = 0, s2 = 0;
    for (int j = 0; j < s.size(); ++j) {
      ((s[j] - '0') & 1) ? s1 += s[j] - '0' : s2 += s[j] - '0';
    }
    a[i] = a[i - 1] + abs(s1 - s2);
  }
  vector<long long> f(1000001, 0);
  for (int i = 1; i <= 1000000; ++i) {
    f[i] = f[i - 1] + a[i + i] + a[i + i - 1] - 2 * a[i];
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << f[n] << endl;
  }
  return 0;
}
