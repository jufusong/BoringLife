#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<long long>> a(51, vector<long long>(4, 0));
  a[0][0] = 1;
  for (int i = 1; i <= 50; ++i) {
    a[i][0] += a[i - 1][0] + a[i - 1][3];
    a[i][1] += a[i - 1][0];
    a[i][2] += a[i - 1][1];
    a[i][3] += a[i - 1][2] + a[i - 1][3];
  }
  cout << a[50][0] + a[50][3] << endl;
  return 0;
}
