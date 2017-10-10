#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, K;
  cin >> n >> m >> K;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0, sum = K; i <= n; i++) {
    if (sum >= m) {
      cout << i << endl;
      return 0;
    }
    if (i == n) break;
    sum += a[i] - 1;
  }
  cout << -1 << endl;
  return 0;
}
