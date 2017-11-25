#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, z, w;
  cin >> n >> z >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> f(n, vector<int>(2));
  for (int i = n - 1; i >= 0; i--) {
    int v1 = (i > 0 ? a[i - 1] : w);
    int v2 = (i > 0 ? a[i - 1] : z);
    f[i][0] = abs(a.back() - v1);
    f[i][1] = abs(a.back() - v2);
    for (int j = i + 1; j < n; j++) {
      f[i][0] = max(f[i][0], f[j][1]);
      f[i][1] = min(f[i][1], f[j][0]);
    }
  }
  cout << f[0][0] << endl;
  return 0;
}
