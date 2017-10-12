#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    a[i] = {t, i};
  }
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  vector<int> b(n);
  for (int i = 1; i < n; i++) {
    b[i] = a[i - 1].first - a[i].first;
  }
  vector<vector<pair<int, int>>> f(20, vector<pair<int, int>>(n));
  vector<int> lg(n + 1);
  for (int i = 1, j = 0; i <= n; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  for (int i = 1; i < n; i++) {
    f[0][i] = {b[i], i};
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
    }
  }
  auto rmq = [&lg, &f](int l, int r) {
    int j = lg[r - l + 1];
    return max(f[j][l], f[j][r - (1 << j) + 1]);
  };
  vector<int> mx(4), mz(4);
  for (int j = n; j; j--) {
    for (int i = 0; i + 2 < j; i++) {
      int k = j, x = i + 1;
      int low = x / 2 + x % 2;
      low = max(low, (k - x) / 3 + ((k - x) % 3 > 0));
      low = max(low, k - x - x * 2);
      //int low = 1, high = (k - x) / 2;
      
      /*while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> vec = {x, mid, k - x - mid};
        sort(vec.begin(), vec.end());
        if (vec[2] > vec[0] * 2) low = mid + 1;
        else high = mid - 1;
        }*/
      if (low <= (k - x) / 2) {
        auto ret = rmq(i + low + 1, k - low);
        int v = ret.first;
        vector<int> tx = {a[i].first - a[i + 1].first, v, a[j - 1].first - a[j].first};
        if (tx > mx) {
          mx = tx;
          mz = {i, ret.second - 1, j - 1};
        }
      }
    }
  }
  vector<int> ans(n);
  for (int i = 0, h = 0; i < n; i++) {
    ans[a[i].second] = h + 1;
    if (i == mz[h]) h++;
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == 4) ans[i] = -1;
    cout << ans[i] << " ";
  }
  return 0;
}
