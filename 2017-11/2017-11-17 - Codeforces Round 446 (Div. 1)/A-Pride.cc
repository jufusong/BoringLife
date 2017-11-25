#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += (a[i] == 1);
  }
  if (cnt) {
    cout << n - cnt << endl;
    return 0;
  }
  int x = n + 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (__gcd(a[i], a[j]) == 1) {
        x = min(x, j - i);
      }
    }
  }
  if (x == n + 1) {
    cout << -1 << endl;
  } else {
    cout << n - 1 + x << endl;
  }
  return 0;
}
