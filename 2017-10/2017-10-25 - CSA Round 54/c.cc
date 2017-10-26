#include <bits/stdc++.h>

using namespace std;

template<class T>
struct RMQ {
  vector<vector<T>> f;
  vector<int> lg;
  RMQ(const vector<T>& a) {
    int n = a.size();
    lg.assign(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      if (i == (1 << (j + 1))) j++;
      lg[i] = j;
    }
    f.assign(lg.back() + 1, vector<T>(a.size()));
    f[0] = a;
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T query(int l, int r) {
    if (l > r) swap(l, r);
    int j = lg[r - l + 1];
    return min(f[j][l], f[j][r - (1 << j) + 1]);
  }
};

int main(int argc, char *argv[]) {
  int n, K;
  cin >> n >> K;
  vector<pair<int, int>> a(n);
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    a[i] = {t, -i};
  }
  RMQ<pair<int, int>> rmq(a);
  for (int i = 0; i < n - 1; i++) {
    auto x = rmq.query(i + 1, min(n - 1, i + K));
    if (x.first < a[i].first) {
      swap(a[i], a[-x.second]);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i].first << " ";
  }
  return 0;
}
