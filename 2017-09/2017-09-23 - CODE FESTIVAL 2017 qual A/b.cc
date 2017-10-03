#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i * m + j * n - i * j * 2 == k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
