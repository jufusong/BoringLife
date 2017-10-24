#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, K;
    cin >> n >> K;
    ll ans = 0;
    vector<int> a(K);
    a[0] = 1;
    for (int i = 0, t, now = 0; i < n; i++) {
      cin >> t;
      now = (now + t) % K;
      ans += a[now];
      a[now]++;
    }
    cout << ans << endl;
  }
  return 0;
}
