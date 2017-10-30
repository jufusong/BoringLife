#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3000005;

int phi[N];
void euler_totient(int n)
{
  for (int i = 1; i <= n; i ++)  phi[i] = i;
  for (int i = 2; i <= n; i += 2)  phi[i] /= 2;
  for (int i = 3; i <= n; i += 2) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i){
        phi[j] = phi[j]/i*(i-1);
      }
    }
  }
}

typedef long long ll;

int main(int argc, char *argv[]) {
  euler_totient(N - 1);
  vector<ll> f(N), g(N);
  f[2] = 1;
  ll Z = 100;
  ll ans = 1;
  for (int i = 3; i < N; i++) {
    f[i] = f[i - 1] + (ll)phi[i] / 2 * i;
    g[i] = g[i - 1] + phi[i];
    if (f[i] >= Z) {
      ans += (Z - f[i - 1]) / i * 2;
      cout << ans << endl;
      break;
    }
    ans += phi[i];
  }
  return 0;
}
