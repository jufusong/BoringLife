#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll n) {
  if (n <= 1) return false;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (isPrime(n) ? "Yes" : "No") << endl;
  }
  return 0;
}
