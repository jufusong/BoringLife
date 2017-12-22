#include <bits/stdc++.h>
#include "/home/palayutm/pcl/number-theory/prime_sieve.hpp"
#include "/home/palayutm/pcl/number-theory/miller_rabin.hpp"

using namespace std;
using miller_rabin::powMod;

int main(int argc, char *argv[]) {
  auto ret = primeSieve(10000000).second;
  int cnt = 1;
  for (auto p : ret) {
    long long md = (long long)p * p;
    long long reminder = (powMod(p - 1, cnt, md) + powMod(p + 1, cnt, md)) % md;
    if (reminder > 1e10) {
      cout << cnt << endl;
      return 0;
    }
    cnt++;
  }
  return 0;
}
