#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps = 1e-8;

ll C(int n, int m) {
  double ans = 1;
  for (int i = 1; i <= m; i++) {
    ans = ans * (n - i + 1) / (m - i + 1);
  }
  return ans + eps;
}

int a[205][205];

int main(int argc, char *argv[]) {
  int K;
  cin >> K;
  map<ll, pair<int, int>> mp;
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= i / 2; j++) {
      ll val = C(i, j);
      if (val > K) break;
      if (!mp.count(val)) {
        mp[val] = {i, j};
      }
    }
  }
  int nl = 1, nr = 1;
  bool flag = false;
  while (K) {
    int x, y, z;
    for (auto e : mp) {
      if (e.first <= K) {
        x = e.first, y = e.second.first, z = e.second.second;
      } else {
        break;
      }
    }
    K -= x;
    nl = y - z + nl - 1, nr = z + nr - 1;
    if (!flag) y++;
    flag = true;
  }
  return 0;
}
