#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> f(n, vector<int>(n));
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      f[i][i] = a[i];
    }
    for (int d = 1; d < n; d++) {
      for (int i = 0; i + d < n; i++) {
        f[i][i + d] = max(a[i] - f[i + 1][i + d], a[i + d] - f[i][i + d - 1]);
      }
    }
    printf("%d\n", f[0][n - 1]);
  }
  return 0;
}
