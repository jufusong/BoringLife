#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll x, y;
  while (cin >> x >> y) {
    cout << y * (x - y + 1) << endl;
  }
  return 0;
}
