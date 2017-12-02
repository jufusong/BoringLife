#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((i + j) & 1) {
          a[i][j] == 'R' ? x2++ : y2++;
        } else {
          a[i][j] == 'R' ? x1++ : y1++;
        }
      }
    }
    cout << min(x2 * 5 + y1 * 3, x1 * 5 + y2 * 3) << endl;
  }
  return 0;
}
