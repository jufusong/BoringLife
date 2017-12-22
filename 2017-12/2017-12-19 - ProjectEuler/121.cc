#include <bits/stdc++.h>

using namespace std;

double f[16][16];

int main(int argc, char *argv[]) {
  f[0][0] = 1;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j <= i; j++) {
      f[i + 1][j + 1] += f[i][j] / (i + 2);
      f[i + 1][j] += f[i][j] * (i + 1) / (i + 2);
    }
  }
  double S = 0;
  for (int i = 8; i <= 15; i++) {
    S += f[15][i];
  }
  cout << (1 - S) / S + 1 << endl;
  return 0;
}
