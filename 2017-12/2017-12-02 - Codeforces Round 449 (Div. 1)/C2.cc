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

ull seed;

inline ull rnd() {
  ull ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}

int main(int argc, char *argv[]) {
  int n, m, vmax;
  cin >> n >> m >> seed >> vmax;
  list<pair<ull, int>> vec;
  for (int i = 1; i <= n; i++) {
    auto v = rnd() % vmax + 1;
    vec.push_back({v, 1});
  }
  for (int i = 0; i < m; ++i) {
    int op = rnd() % 4 + 1;
    int l = rnd() % n + 1, r = rnd() % n + 1;
    if (l > r) swap(l, r);
    ull x, y;
    if (op == 3) {
      x = rnd() % (r - l + 1) + 1;
    } else {
      x = rnd() % vmax + 1;
    }
    if (op == 4) {
      y = rnd() % vmax + 1;
    }
    auto split = [&vec](int l, int r) {
      int sum = 0;
      auto ret1 = vec.begin(), ret2 = vec.end();
      for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (sum + 1 < l && sum + it->second >= l) {
          vec.insert(it, {it->first, it->second - (l - sum - 1)});
          it->second -= (l - sum - 1);
          sum = l - 1;
        }
        if (sum == l - 1) ret1 = it;
        if (sum + it->second > r) {
          auto t = it;
          ++t;
          vec.insert(t, {it->first, it->second - (sum + it->second - r)});
          it->second -= (sum + it->second - r);
        }
        sum += it->second;
        if (sum >= r) {
          ret2 = it;
          ret2++;
          break;
        }
      }
      return make_pair(ret1, ret2);
    };
    if (op == 1) {
      int sum = 0;
      auto e = split(l, r);
      for (auto it = e.first; it != e.second; ++it) {
        it->first += x;
      }
    }
    if (op == 2) {
      auto e = split(l, r);
      int sum = 0;
      e.first->first = x;
      while (true) {
        auto it = e.first;
        ++it;
        if (it == e.second) break;
        e.first->second += it->second;
        vec.erase(it);
      }
    }
    if (op == 3) {
      auto e = split(l, r);
      
    }
    if (op == 4) {
      auto e = split(l, r);
      ull ret = 0;
      for (auto it = e.first; it != e.second; ++it) {
        ret = (ret + powMod(it->first, x, y) * it->second) % y;
      }
      printf("%llu\n", ret);
    }
  }
  return 0;
}
