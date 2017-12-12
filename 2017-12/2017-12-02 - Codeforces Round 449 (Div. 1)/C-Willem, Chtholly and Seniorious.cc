#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

typedef unsigned long long ull;

ull powMod(ull x, ull y, ull z) {
  ull ret = 1;
  for (; y; y >>= 1, x = x * x % z) {
    if (y & 1) ret = ret * x % z;
  }
  return ret;
}

ull a[100005];
ull seed;

inline ull rnd() {
  ull ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}

int main(int argc, char *argv[]) {
  int n, m, vmax;
  cin >> n >> m >> seed >> vmax;
  for (int i = 1; i <= n; i++) {
    a[i] = rnd() % vmax + 1;
  }
  for (int i = 0; i < m; ++i) {
    int op = rnd() % 4;
    int l = rnd() % n + 1, r = rnd() % n + 1;
    if (l > r) swap(l, r);
    ull x, y;
    if (op == 2) {
      x = rnd() % (r - l + 1) + 1;
    } else {
      x = rnd() % vmax + 1;
    }
    if (op == 3) {
      y = rnd() % vmax + 1;
    }
    if (op == 0) {
      for (int i = l; i <= r; ++i) {
        a[i] += x;
      }
    } 
    if (op == 1) {
      for (int i = l; i <= r; ++i) {
        a[i] = x;
      }
    }
    if (op == 2) {
      /*      if (a[l] == a[r] && a[l] == a[(r + l) / 2]) {
        printf("%llu\n", a[l]);
        continue;
        }*/
      vector<ull> vec = {a + l, a + r + 1};
      nth_element(vec.begin(), vec.begin() + x - 1, vec.end());
      printf("%llu\n", vec[x - 1]);
    }
    if (op == 3) {
      /* if (a[l] == a[r] && a[l] == a[(r + l) / 2]) {
        auto ret = powMod(a[l], x, y);
        printf("%llu\n", ret * (r - l + 1) % y);
        continue;
        }*/
      ull ret = 0, last = -1;
      for (int i = l; i <= r; i++) {
        /*        if (i > l && a[i] == a[i - 1]) {
          ret += last;
          if (ret >= y) ret -= y;
          continue;
          }*/
        last = powMod(a[i], x, y);
        ret += last;
        if (ret >= y) ret -= y;
      }
      printf("%llu\n", ret);
    }
  }
  return 0;
}


