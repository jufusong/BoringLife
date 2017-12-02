#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll A, S, K, X, Y;
  cin >> A >> S >> K >> X >> Y;
  ll x = S - A + K * Y, y = X + Y;
  if (x >= 0 && x % y == 0) {
    cout << x / y << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
