#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll powMod(ll n, ll m, ll mod) {
  ll ans = 1;
  for (; m; m >>= 1, n = n * n % mod) {
    if (m & 1) ans = ans * n % mod;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> pr(100000 + 1);
  for (int i = 1; i <= 100000; i++) {
    for (int j = i + i; j <= 100000; j += i) {
      pr[j].push_back(i);
    }
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  auto cal = [&a](int x) {
    int id = lower_bound(a.begin(), a.end(), x) - a.begin();
    return (int)a.size() - id;
  };
  ll ans = 0;
  for (int i = 1; i <= 100000; i++) {
    vector<int> b(pr[i].size() + 1);
    b.back() = cal(i);
    int k = pr[i].size() + 1;
    ll t = (powMod(k, b.back(), mod) - powMod(k - 1, b.back(), mod) + mod) % mod;
    for (int j = pr[i].size() - 1; j >= 0; j--) {
      b[j] = cal(pr[i][j]);
      t = t * powMod(j + 1, b[j] - b[j + 1], mod) % mod;
    }
    ans = (ans + t) % mod;
  }
  cout << ans << endl;
  return 0;
}
