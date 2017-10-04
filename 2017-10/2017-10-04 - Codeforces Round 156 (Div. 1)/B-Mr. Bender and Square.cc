#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll n, x, y, c;
  cin >> n >> x >> y >> c;
  ll low = 0, high = 2 * n;
  while (low <= high) {
    ll mid = (low + high) / 2;
    ll sum = (1 + mid) * mid * 2 + 1;
    auto cal1 = [](ll a, ll b) {
      if (a >= b) return 0LL;
      ll n = b - a;
      return n + n * (n - 1);
    };
    auto cal2 = [](ll n) {
      if (n < 0) return 0LL;
      return (1 + n) * n / 2;
    };
    sum -= cal1(x - 1, mid) + cal1(n - x, mid) + cal1(y - 1, mid) + cal1(n - y, mid);
    sum += cal2(mid - 1 - (x - 1 + y - 1)) + cal2(mid - 1 - (x - 1 + n - y))
      + cal2(mid - 1 - (n - x + y - 1)) + cal2(mid - 1 - (n - x + n - y));
    if (sum >= c) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << low << endl;
  return 0;
}
