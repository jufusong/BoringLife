#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int N = 50;
  vector<vector<long long>> a(1000, vector<long long>(N + 1, 0));
  a[0][0] = 1;
  for (int i = 1; i < 1000; ++i) {
    for (int j = 1; j <= N; j++) {
      a[i][j] += a[i - 1][j - 1];
    }
    a[i][0] += a[i - 1][0] + a[i - 1][N];
    a[i][N] += a[i - 1][N];
    if (a[i][0] + a[i][N] > 1e6) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
