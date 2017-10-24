#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    long long ans = 0;
    int n, K;
    cin >> n >> K;
    for (int i = 1, last = 0; i <= n; i++) {
      int t;
      cin >> t;
      if (t > K) last = i;
      ans += last;
    }
    cout << ans << endl;
  }
  return 0;
}
