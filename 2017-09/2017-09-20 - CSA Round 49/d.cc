#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T, A;
  cin >> T >> A;
  vector<vector<int>> a(T + 1, vector<int>(A + 1));
  for (int i = 1; i <= T; i++) {
    for (int j = 1; j <= A; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<double>> b(T + 1, vector<double>(A + 1));
  b[T][0] = 1;
  for (int j = 0; j < A; j++) {
    for (int i = 1; i <= T; i++) {
      double p = a[i][j + 1] / 100.0;
      b[i][j + 1] += b[i][j] * p;
      b[i - 1][j + 1] += b[i][j] * (1 - p);
    }
  }
  double ans = 0;
  for (int i = 1; i <= A; i++) {
    ans += i * b[0][i];
  }
  for (int i = 1; i <= T; i++) {
    ans += A * b[i][A];
  }
  printf("%.10f\n", ans);
  return 0;
}
