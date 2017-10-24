#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll choose(int n, int k) {
  ll c = 1, to = min(k, n - k);
  if (k > n) return 0;
  for (int i = 0; i < to; i++) {
    assert(c * (n - i) % (i + 1) == 0);
    c = c * (n - i) / (i + 1);
  }
  return c;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int x, y, K;
    cin >> x >> y >> K;
    string s;
    for (int i = 0, j = 0; i != x || j != y; ) {
      if (i == x) s += 'V', j++;
      else if (j == y) s += 'H', i++;
      else {
        int v = choose(x - i + y - j - 1, x - i - 1);
        if (v > K) {
          s += 'H', i++;
        } else {
          K -= v;
          s += 'V', j++;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
