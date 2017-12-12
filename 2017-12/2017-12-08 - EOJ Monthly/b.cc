#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    cout << 0 << endl;
  } else if (n == 2) {
    long long x = (m + 1) / 2, y = m / 2;
    cout << x * (x - 1) + y * (y - 1) << endl;
  } else if (n == 3 && m == 3) {
    cout << 28 << endl;
  } else {
    long long x = n * m;
    cout << x * (x - 1) / 2 << endl;
  }
  return 0;
}
