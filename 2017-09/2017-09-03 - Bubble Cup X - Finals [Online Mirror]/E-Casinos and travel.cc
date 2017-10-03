#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

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
  vector<int> in(n + 1);
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    in[u]++, in[v]++;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += (in[i] == 1);
  }
  cout << (powMod(2, n - sum + 1, mod) * sum +  powMod(2, n - sum, mod) * (n - sum)) % mod << endl;
  return 0;
}
