#include <bits/stdc++.h>

using namespace std;

long long f[101][10][3];

int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; i++) {
    f[0][i][2] = 1;
  }
  for (int i = 1; i < 100; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (j > k) f[i][j][0] += f[i - 1][k][0] + f[i - 1][k][2];
        if (j < k) f[i][j][1] += f[i - 1][k][1] + f[i - 1][k][2];
        if (j == k) {
          f[i][j][2] += f[i - 1][k][2];
          f[i][j][0] += f[i - 1][j][0];
          f[i][j][1] += f[i - 1][j][1];
        }
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 1; j < 10; j++) {
      sum += f[i][j][0] + f[i][j][1] + f[i][j][2];
    }
  }
  cout << sum << endl;
  return 0;
}
