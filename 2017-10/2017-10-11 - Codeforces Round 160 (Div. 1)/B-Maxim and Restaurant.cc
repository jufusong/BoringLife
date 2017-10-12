#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[55][55][55];

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int P;
  cin >> P;
  f[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= P; k++) {
        f[i + 1][j][k] += f[i][j][k];
        f[i + 1][j + 1][min(P + 1, k + a[i])] += f[i][j][k];
      }
      f[i + 1][j][P + 1] += f[i][j][P + 1];
    }
  }
  vector<double> J(55);
  for (int i = 1; i <= 50; i++) {
    J[i] = J[i - 1] + log(i);
  }

  vector<double> b(n + 2);
  for (int i = 1; i <= n; i++) {
    ll x = 0;
    for (int j = 0; j <= P; j++) {
      x += f[n][i][j];
    }
    b[i] = exp(log(x) + J[i] + J[n - i] - J[n]);
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * (b[i] - b[i + 1]);
  }
  printf("%.10f\n", ans);
  return 0;
}
