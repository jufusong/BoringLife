#include <bits/stdc++.h>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long gcd = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return gcd;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "YES" << endl;
    cout << 1 << endl;
    return 0;
  }
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    a[i] = i + 1;
  }
  stable_sort(a.begin(), a.end(), [&n](int x, int y) {
      return __gcd(x, n) < __gcd(y, n);
    });
  std::vector<int> b(n, 0);
  set<int> se;
  b[0] = a[0];
  std::vector<bool> vis(n);
  vis[b[0]] = true;
  for (int i = 1, now = a[0]; i < n - 1; ++i) {
    int d = __gcd(now, n);
    if (__gcd(a[i], n) > 1 && n != 4) {
      cout << "NO" << endl;
      return 0;
    }
    long long x, y;
    exgcd(now / d, n / d, x, y);
    x = x * (a[i] / d) % n;
    x = (x % (n / d) + n / d) % (n / d);
    for (int i = 0; i < d; i++) {
      if (!vis[x]) {
        break;
      }
      x = (x + n / d) % n;
    }
    if (vis[x]) {
      cout << "NO" << endl;
      return 0;
    }
    vis[x] = true;
    assert(!se.count(x));
    se.insert(x);
    b[i] = x;
    now = a[i];
  }
  cout << "YES" << endl;
  b[n - 1] = n;
  for (auto x : b) {
    cout << x << endl;
  }
  return 0;
}
