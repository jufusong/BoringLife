#include <bits/stdc++.h>

using namespace std;

const double inf = 1e12;
const double eps = 1e-10;

int main(int argc, char *argv[]) {
  int n, R;
  cin >> n >> R;
  vector<tuple<int, int, int>> a(n + 1);
  for (int i = 1, f, s, p; i <= n; i++) {
    cin >> f >> s >> p;
    a[i] = {f, s, p};
  }
  double low = 0, high = 1e9;
  for (int z = 0; z < 100; z++) {
    double mid = (low + high) / 2;
    vector<vector<double>> b(n + 2, vector<double>(R + 1000, mid));
    for (int i = 0; i <= R; i++) {
      b[n + 1][i] = 0;
    }
    for (int i = n; i >= 1; i--) {
      int f, s, p;
      tie(f, s, p) = a[i];
      for (int j = 0; j <= R; j++) {
        b[i][j] = min(mid, p / 100.0 * (f + b[i + 1][j + f]) + (100 - p) / 100.0 * (s + b[i + 1][j + s]));
      }
    }
    //    cout << b[1][0] << " " << mid << endl;
    //    printf("%.12f %.12f\n", b[1][0], mid);
    if (b[1][0] >= mid) low = mid;
    else high = mid;
  }
  printf("%.10f\n", low);
  return 0;
}
