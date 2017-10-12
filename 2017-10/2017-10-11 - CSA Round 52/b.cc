#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<ll> a, b(10001);
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    if (t) a.push_back(t);
    b[t]++;
  }
  ll ans = b[0] * (b[0] - 1) * (b[0] - 2) / 6;
  for (int i = 1; i <= 5000; i++) {
    ans = ans + b[0] * b[i] * (b[i] - 1) / 2;
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      int x = b[a[i] + a[j]];
      ans += x;
    }
  }
  cout << ans << endl;
  return 0;
}
