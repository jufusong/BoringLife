#include <bits/stdc++.h>

using namespace std;

struct SimpleBinomial {
  int n, md;
  vector<vector<int>> C;
  SimpleBinomial(int n, int mod) : n(n), md(mod) {
    C = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
      C[i][0] = C[i][i] = 1;
      for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
        if (C[i][j] >= mod) C[i][j] -= mod;
      }
    }
  }
  int choose(int n, int k) { return C[n][k]; }
}bi(1000, 1e9);

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
      cout << bi.choose(n, i) << " ";
    }
    cout << endl;
  }
  return 0;
}
