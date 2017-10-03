#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int ans = 0;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        set<int> se;
        if (i > 0 && b[i - 1][j] != 'X') se.insert(a[i - 1][j]);
        if (j > 0 && b[i][j - 1] != 'X') se.insert(a[i][j - 1]);
        if (i > 0 && j > 0 && b[i - 1][j - 1] != 'X') se.insert(a[i - 1][j - 1]);
        for (int k = 0; k < 5; k++) {
          if (!se.count(k)) {
            a[i][j] = k;
            break;
          }
        }
        if (b[i][j] == 'K') ans ^= a[i][j];
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][j] == 'K') {
          int x = (ans ^ a[i][j]);
          if (i > 0 && b[i - 1][j] != 'X' && (x ^ a[i - 1][j]) == 0) cnt++;
          if (j > 0 && b[i][j - 1] != 'X' && (x ^ a[i][j - 1]) == 0) cnt++;
          if (i > 0 && j > 0 && b[i - 1][j - 1] != 'X' && (x ^ a[i - 1][j - 1]) == 0) cnt++;
        }
      }
    }
    if (cnt == 0) {
      cout << "LOSE" << endl;
    } else {
      cout << "WIN " << cnt << endl;
    }
  }
  return 0;
}
