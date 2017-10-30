#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll v = 600851475143LL, p;
  for (ll i = 2; i * i <= v; i++) {
    while (v % i == 0) {
      v /= i;
      p = i;
    }
  }
  p = max(p, v);
  cout << p << endl;
  return 0;
}
