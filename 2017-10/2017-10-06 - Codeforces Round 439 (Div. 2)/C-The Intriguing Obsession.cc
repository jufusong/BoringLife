#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 998244353;

int main(int argc, char *argv[]) {
  vector<vector<ll>> C(5001, vector<ll>(5001));
  for (int i = 0; i <= 5000; i++) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  vector<ll> J(5001, 1);
  for (int i = 1; i <= 5000; i++) {
    J[i] = J[i - 1] * i % mod;
  }
  auto cal = [&C, &J](int x, int y) {
    ll ans = 0;
    for (int i = 0; i <= x && i <= y; i++) {
      ans = (ans + C[x][i] * C[y][i] % mod * J[i]) % mod;
    }
    return ans;
  };
  int a, b, c;
  cin >> a >> b >> c;
  cout << cal(a, b) * cal(b, c) % mod * cal(a, c) % mod << endl;
  return 0;
}
