#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> b(n + 2), c(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  ll ans = 0;
  int px = 0, py = 0, pz = 0;
  for (int i = 0; i <= n; i++) {
    b[i] = a[i];
    int p1 = i;
    for (int j = 0; j <= i; j++) {
      if (a[j] * 2 - a[i] > b[i]) {
        b[i] = a[j] * 2 - a[i];
        p1 = j;
      }
    }
    c[i] = a[n] - a[i];
    int p2 = n;
    for (int j = i; j <= n; j++) {
      if (a[j] - a[i] - (a[n] - a[j]) > c[i]) {
        c[i] = a[j] - a[i] - (a[n] - a[j]);
        p2 = j;
      }
    }
    if (c[i] + b[i] >= ans) {
      ans = c[i] + b[i];
      px = p1, py = i, pz = p2;
    }
  }
  cout << px << " " << py << " " << pz << endl;
  return 0;
}
