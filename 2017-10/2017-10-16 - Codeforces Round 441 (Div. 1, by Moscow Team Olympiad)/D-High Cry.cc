#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> lg(n + 1);
  for (int i = 1, j = 0; i <= n; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  vector<vector<int>> f(20, vector<int>(n));
  f[0] = a;
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      f[j][i] = (f[j - 1][i] | f[j - 1][i + (1 << (j - 1))]);
    }
  }
  auto query = [&](int l, int r) {
    int j = lg[r - l + 1];
    return f[j][l] | f[j][r - (1 << j) + 1];
  };
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]].push_back(i);
  }
  ll ans = 0;
  for (auto& e : mp) {
    auto& vec = e.second;
    int val = a[vec[0]], now = 0;
    for (auto x : vec) {
      int low = now, high = x;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (query(mid, x) > val) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      int px = low;
      low = x, high = n - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (query(x, mid) > val) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      ans += (ll)(x - px + 1) * (low - x);
      now = x + 1;
    }
  }
  cout << (ll)n * (n + 1) / 2 - ans << endl;
  return 0;
}
