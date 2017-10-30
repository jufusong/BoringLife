#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[18][10][1 << 10];

int main(int argc, char *argv[]) {
  for (int i = 0; i <= 9; i++) {
    f[0][i][1 << i] = 1;
  }
  for (int i = 1; i <= 17; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k < 1 << 10; k++) {
        if (k & (1 << j)) {
          for (int h = 0; h < 10; h++) {
            if (k & (1 << h)) {
              f[i][j][k] += f[i - 1][h][k];
              f[i][j][k] += f[i - 1][h][k ^ (1 << j)];
            }
          }
        }
      }
    }
  }
  vector<ll> a(1 << 10);
  for (int i = 0; i <= 17; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int k = 0; k < 1 << 10; k++) {
        a[k] += f[i][j][k];
      }
    }
  }
  __int128 ans = 0;
  for (int i = 0; i < 1 << 10; i++) {
    for (int j = i; j < 1 << 10; j++) {
      if (!(i & j)) {
        ans += (__int128)a[i] * a[j];
      }
    }
  }
  __int128 sum = (__int128)999999999999999999LL * 999999999999999998LL / 2;
  __int128 x = sum - ans;
  cout << (int)(x % 1000267129) << endl;
}
