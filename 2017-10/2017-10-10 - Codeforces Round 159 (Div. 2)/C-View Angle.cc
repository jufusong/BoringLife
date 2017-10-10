#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<double> vec;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    vec.push_back(atan2(y, x));
  }
  sort(vec.begin(), vec.end());
  vec.push_back(vec[0] + 2 * acos(-1));
  double mx = 0;
  for (int i = 1; i < vec.size(); i++) {
    mx = max(mx, vec[i] - vec[i - 1]);
  }
  printf("%.10f\n", 360.0 - 180.0 * mx / acos(-1));
  return 0;
}
