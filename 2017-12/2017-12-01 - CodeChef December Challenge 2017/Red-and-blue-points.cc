#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const double eps = 1e-8;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a.emplace_back(x, y, 0);
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      a.emplace_back(x, y, 1);
    }
    int ans = n + m;
    for (int i = 0; i < a.size(); ++i) {
      vector<tuple<double, int>> vec;
      int X = get<0>(a[i]), Y = get<1>(a[i]), tp = get<2>(a[i]);
      for (int j = 0; j < a.size(); ++j) {
        if (j != i) {
          int x1 = get<0>(a[j]) - X, y1 = get<1>(a[j]) - Y, tp = get<2>(a[j]);
          vec.emplace_back(arg(complex<double>(x1, y1)), tp);
        }
      }
      auto angle = [&X, &Y](const tuple<int, int, int>& x) {
        int x1 = get<0>(x) - X, y1 = get<1>(x) - Y;
        return arg(complex<double>(x1, y1));
      };
      sort(vec.begin(), vec.end());
      int s0 = (tp == 0), s1 = (tp == 1);
      double now = 0;
      int h1 = 0, p = 0;
      while (true) {
        while (p < vec.size() && get<0>(vec[p]) - eps <= now) {
          get<1>(vec[p]) ? s1++ : s0++;
          p++;
        };
        while (h1 < vec.size() && get<0>(vec[h1]) - eps <= now - PI) {
          get<1>(vec[h1]) ? s1-- : s0--;
          h1++;
        }
        ans = min(ans, s0 + m - s1);
        ans = min(ans, s1 + n - s0);
        if (now + eps >= PI) break;
        double d1 = (p < vec.size() ? get<0>(vec[p]) : PI);
        double d2 = (h1 < vec.size() ? get<0>(vec[h1]) + PI : PI);
        now = min(d1, d2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
