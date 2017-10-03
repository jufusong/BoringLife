#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  while (cin >> n) {
    if (n == 0) {
      cout << "*" << endl;
      return 0;
    }
    vector<int> vx, vy;
    vector<tuple<int, int, int, int>> pt;
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      pt.push_back(make_tuple(x1, y1, x2, y2));
      vx.push_back(x1), vx.push_back(x2);
      vy.push_back(y1), vy.push_back(y2);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    auto getIndex = [](int v, const vector<int> &vec) {
      return lower_bound(vec.begin(), vec.end(), v) - vec.begin() + 1;
    };
    vector<vector<int>> a(vx.size() + 1, vector<int>(vy.size() + 1));
    for (auto e : pt) {
      int x1, y1, x2, y2;
      tie(x1, y1, x2, y2) = e;
      x1 = getIndex(x1, vx), y1 = getIndex(y1, vy);
      x2 = getIndex(x2, vx), y2 = getIndex(y2, vy);
      //      cout << x1 << " " << y1 << "  " << x2 << " " << y2 << endl;
      a[x1][y1]++, a[x1][y2]--, a[x2][y1]--, a[x2][y2]++;
    }
    ll ans = 0;
    for (int i = 1; i < (int)vx.size(); i++) {
      for (int j = 1; j < (int)vy.size(); j++) {
        a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        ll x = vx[i] - vx[i - 1];
        ll y = vy[j] - vy[j - 1];
        if (a[i][j]) ans += x * y;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
