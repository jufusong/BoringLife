#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<long long>> a(51, vector<long long>(4, 0));
  a[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    a[i] = a[i - 1];
    for (int j = 1; j <= 3 && j + 1 <= i; j++) {
      a[i][j] += a[i - j - 1][j] + a[i - j - 1][0];
    }
  }
  cout << a[5][1] + a[5][2] + a[5][3] << endl;
  cout << a[50][1] + a[50][2] + a[50][3] << endl;
  return 0;
}
