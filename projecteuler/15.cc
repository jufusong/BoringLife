#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, const char *argv[]) {
  vector<vector<ll>> C(41, vector<ll>(40));
  for (int i = 0; i <= 40; i++) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
    }
  }
  cout << C[40][20] << endl;
  return 0;
}

