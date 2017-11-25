#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (auto t : a) {
      if (t >= x && t <= y) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
