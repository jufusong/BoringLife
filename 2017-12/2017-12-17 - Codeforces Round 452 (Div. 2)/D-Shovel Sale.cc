#include <bits/stdc++.h>

using namespace std;

int power(int n, int k) {
  int ret = 1;
  for (int i = 0; i < k; i++) {
    ret *= n;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  if (n < 5) {
    cout << n * (n - 1) / 2 << endl;
    return 0;
  }
  string s = to_string(n);
  if (s[0] >= '5') {
    int ans = n - power(10, s.size() - 1) * 5 + 1;
    if (to_string(n + 1).size() > s.size()) ans--;
    cout << ans << endl;
  } else {
    int len = s.size();
    long long d = power(10, len - 1);
    long long x = n % d;
    long long k = n / d;
    long long ans = k * (d / 2) * k - k;
    string t = to_string(n);
    t.erase(t.begin());
    if (t[0] >= '5') {
      ans += k * (d / 2);
      ans += (x - power(10, t.size() - 1) * 5 + 1) * (k + 1);
      if (to_string(x + 1).size() > t.size()) ans--;
    } else {
      ans += (x + 1) * k;
    }
    cout << ans << endl;
  }
  return 0;
}
