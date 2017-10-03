#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    vector<pair<int, int>> vec;
    vec.push_back({-p, inf});
    for (int x, y;;) {
      cin >> x;
      if (x == -1) break;
      cin >> y;
      vec.push_back({-y, x});
    }
    sort(vec.begin(), vec.end());
    if (vec[0].second != inf) {
      int x = -vec[0].first;
      int y = -vec[1].first;
      a[vec[0].second] += min(x, y + y / 10);
    }
  }
  int K;
  cin >> K;
  while (K--) {
    int p;
    cin >> p;
    cout << a[p] << endl;
  }
  return 0;
}
