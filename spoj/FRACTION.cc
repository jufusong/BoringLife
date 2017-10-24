#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, Q;
    scanf("%d%d", &n, &Q);
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        if (__gcd(i, j) == 1) {
          vec.push_back({i, j});
        }
      }
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first * y.second > x.second * y.first;
      });
    vec.push_back({0, 1});
    reverse(vec.begin(), vec.end());
    while (Q--) {
      int k;
      scanf("%d", &k);
      printf("%d/%d\n", vec[k - 1].first, vec[k - 1].second);
    }
  }
  return 0;
}
