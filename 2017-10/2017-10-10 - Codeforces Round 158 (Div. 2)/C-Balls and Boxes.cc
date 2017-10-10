#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  vector<ll> a(n + 1);
  int minn = 2e9, p = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < minn) {
      minn = a[i];
      p = i;
    }
  }
  ll sum = (ll)minn * n;
  for (int i = 1; i <= n; i++) {
    a[i] -= minn;
  }
  for (int i = x; ;) {
    if (a[i] == 0) {
      a[i] = sum;
      break;
    }
    a[i]--;
    sum++;
    i--;
    if (i == 0) i = n;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
