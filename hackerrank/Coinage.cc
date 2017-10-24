#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 1;
    vector<pair<int, int>> b = {{1, 0}, {2, 0}, {5, 0}, {10, 0}};
    for (int i = 0; i < 4; i++) {
      cin >> b[i].second;
    }
    for (auto e : b) {
      int x = e.first, y = e.second;
      for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= y && i + j * x <= n; j++) {
          a[i + j * x] += a[i];
        }
      }
    }
    cout << a[n] << endl;
  }
  return 0;
}
