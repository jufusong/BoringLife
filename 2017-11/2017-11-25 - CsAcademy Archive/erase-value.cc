#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, sum = 0;;
  cin >> n;
  vector<int> a(1001);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    sum += t;
    a[t] += t;
  }
  int ans = sum;
  for (auto x : a) {
    ans = min(ans, sum - x);
  }
  cout << ans << endl;
  return 0;
}
