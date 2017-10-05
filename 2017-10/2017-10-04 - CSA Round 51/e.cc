#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[61][32], C[61][61];

int main(int argc, char *argv[]) {
  for (int i = 0; i <= 60; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  f[0][0] = 1;
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j <= 30; j++) {
      if (j) f[i][j] += f[i - 1][j - 1];
      f[i][j] += f[i - 1][j + 1];
    }
  }
  int n;
  ll K;
  cin >> n >> K;
  for (int i = n * 2, now = 0, flag = 1; i >= 1; i--) {
    ll val = C[i - 1][(i + now) / 2];
    if (now < 0) flag = false;
    if (flag) val -= f[i - 1][now + 1];
    if (val < K) {
      cout << ")";
      K -= val;
      now--;
    } else {
      cout << "(";
      now++;
    }
  }
  return 0;
}
