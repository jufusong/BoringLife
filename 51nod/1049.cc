#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  ll v = 0;
  cin >> n;
  vector<ll> f(n + 1);
  for (int i = 1, t; i <= n; i++) {
    cin >> t;
    f[i] = max(f[i - 1], 0LL) + t;
    v = max(v, f[i]);
  }
  cout << v << endl;
  return 0;
}
