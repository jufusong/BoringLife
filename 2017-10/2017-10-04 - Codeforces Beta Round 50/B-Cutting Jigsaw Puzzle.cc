#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int x, y;
  cin >> x >> y;
  vector<string> a(x);
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  set<vector<vector<int>>> se;
  int ans = 0, ax = x, ay = y;
  for (int w = 1; w <= x; w++) {
    for (int h = 1; h <= y; h++) {
      if (x % w == 0 && y % h == 0) {
        bool flag = true;
        se.clear();
        for (int i = 0; i < x; i += w) {
          for (int j = 0; j < y; j += h) {
            vector<vector<int>> b(w, vector<int>(h));
            for (int ii = i; ii < i + w; ii++) {
              for (int jj = j; jj < j + h; jj++) {
                b[ii - i][jj - j] = a[ii][jj];
              }
            }
            auto rotate = [](vector<vector<int>>& b) {
              vector<vector<int>> c(b[0].size(), vector<int>(b.size()));
              for (int jj = 0, tx = 0, ty = 0; jj < b[0].size(); jj++) {
                for (int ii = b.size() - 1; ii >= 0; ii--) {
                  c[tx][ty] = b[ii][jj];
                  ty++;
                  if (ty == b.size()) {
                    ty = 0, tx++;
                  }
                }
              }
              b = c;
            };
            for (int z = 0; z < 4; z++) {
              rotate(b);
              flag &= !se.count(b);
            }
            se.insert(b);
          }
        }
        if (flag) {
          ans++;
          if (w * h < ax * ay) {
            ax = w, ay = h;
          }
        }
      }
    }
  }
  cout << ans << endl << ax << " " << ay << endl;
  return 0;
}
