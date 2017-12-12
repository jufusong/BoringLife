#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powMod(long long x, long long y, long long z = mod) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % z) {
    if (y & 1) ret = ret * x % z;
  }
  return ret;
}

map<int, int> mp;

int solve(int x) {
  if (x == 1) return 1;
  if (mp.count(x)) return mp[x];
  mp[x] = powMod(2, x - 1);
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      mp[x] = (mp[x] - solve(x / i) + mod) % mod;
      if (i != x / i) {
        mp[x] = (mp[x] - solve(i) + mod) % mod;        
      }
    }
  }
  mp[x] = (mp[x] - solve(1) + mod) % mod;
  return mp[x];
}

int main(int argc, char *argv[]) {
  int x, y;
  cin >> x >> y;
  if (y % x) {
    cout << 0 << endl;
    return 0;
  }
  cout << solve(y / x) << endl;
  return 0;
}
