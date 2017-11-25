#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll n, K;
  cin >> K >> n;
  if (K % 2 == 0) {
    cout << K / 2;
    for (int i = 2; i <= n; i++) {
      cout << " " << K;
    }
    return 0;
  }
  vector<ll> a(n + 2);
  vector<int> b(n + 2, (K + 1) / 2);
  int p;
  for (p = n; p >= 0; p--) {
    a[p] = K * a[p + 1] + 1;
    if (a[p] > p) break;
  }
  ll S = a[p] - p;
  for (int j = p + 1; j <= n; j++) {
    int z = (S - 2) / (a[j] * 2);
    if (S < 2) {
      b[j] = 0;
      break;
    }
    b[j] = z + 1;
    S = S - z * a[j] * 2 - 2;
  }
  for (int i = 1; i <= n && b[i]; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
