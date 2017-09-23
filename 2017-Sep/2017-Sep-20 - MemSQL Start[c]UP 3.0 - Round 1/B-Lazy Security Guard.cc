#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, ans = 1e9;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, i + n / i + (n % i > 0));
  }
  cout << ans * 2 << endl;
  return 0;
}
