#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K;
  cin >> n >> K;
  vector<ll> a(1e7 + 5, 0);
  auto b = a;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[t]++;
  }
  int mx = -1;
  for (int i = 1e7; i >= 1; i--) {
    if (i * 2 <= 1e7) a[i] += a[i * 2] + a[i * 2 + 1];
    b[i] = a[i] + b[i + 1];
    if (i * 2 - 1 <= 1e7) a[i] += a[i * 2 - 1] + a[i * 2];
    if (b[i] >= K) {
      mx = i;
      break;
    }
  }
  cout << mx << endl;
  return 0;
}
