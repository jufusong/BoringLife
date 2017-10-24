#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  double ans = 0, now = 0;
  for (int i = 0, j = 0; i < n; i++) {
    now += a[i];
    if (i - j + 1 == K) {
      ans += now;
      now -= a[j++];
    }
  }
  printf("%.10f\n", ans / (n - K + 1));
  return 0;
}
