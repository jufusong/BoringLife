#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  vector<ll> vec;
  for (ll i = 1; i <= 1000000; i++) {
    vec.push_back(i * i * i - (i - 1) * (i - 1) * (i - 1));
  }
  int T;
  cin >> T;
  while (T--) {
    ll x;
    cin >> x;
    cout << (*lower_bound(vec.begin(), vec.end(), x) == x ? "YES" : "NO") << endl;
  }
  return 0;
}
