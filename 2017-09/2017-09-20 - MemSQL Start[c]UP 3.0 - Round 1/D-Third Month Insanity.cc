#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 6;

double a[N][N], b[N][N][N], c[N][N][N];

void dfs(int l, int r, int d) {
  if (l == r) {
    b[l][r][l] = 0;
    c[l][r][l] = 1;
  } else {
    int m = (l + r) / 2;
    dfs(l, m, d - 1);
    dfs(m + 1, r, d - 1);
    for (int i = l; i <= r; i++) {
      if (i <= m) {
        for (int j = m + 1; j <= r; j++) {
          c[l][r][i] += c[l][m][i] * c[m + 1][r][j] * a[i][j];
        }
        for (int j = m + 1; j <= r; j++) {
          b[l][r][i] = max(b[l][r][i], b[l][m][i] + b[m + 1][r][j] + (1 << d) * c[l][r][i]);
        }
      } else {
        for (int j = l; j <= m; j++) {
          c[l][r][i] += c[m + 1][r][i] * c[l][m][j] * a[i][j];
        }
        for (int j = l; j <= m; j++) {
          b[l][r][i] = max(b[l][r][i], b[m + 1][r][i] + b[l][m][j] + (1 << d) * c[l][r][i]);
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      cin >> a[i][j];
      a[i][j] /= 100;
    }
  }
  double mx = 0;
  dfs(0, (1 << n) - 1, n - 1);
  for (int i = 0; i < (1 << n); i++) {
    mx = max(mx, b[0][(1 << n) - 1][i]);
  }
  printf("%.10f\n", mx);
  return 0;
}
