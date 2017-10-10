#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b[n - 1] = a[n - 1];
  c[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < b[i + 1]) {
      b[i] = b[i + 1] - a[i];
    } else {
      c[i] = 1;
      b[i] = a[i] - b[i + 1];
    }
  }
  for (int i = 0, S = 0; i < n; i++) {
    S ^= c[i];
    if (S) {
      cout << '+';
    } else {
      cout << "-";
    }
  }
  return 0;
}
