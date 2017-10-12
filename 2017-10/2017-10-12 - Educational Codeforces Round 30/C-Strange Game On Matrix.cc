#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m, K;
  cin >> n >> m >> K;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  auto cal = [](vector<int> a, int K) {
    int x = 0, y = 0, n = a.size();
    for (int i = 0, now = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < i + K && j < n; j++) {
        sum += a[j];
      }
      if (sum > x) {
        x = sum, y = now;
      }
      now += a[i];
    }
    return make_pair(x, y);
  };
  int x = 0, y = 0;
  for (int j = 0; j < m; j++) {
    vector<int> b;
    for (int i = 0; i < n; i++) {
      b.push_back(a[i][j]);
    }
    auto ret = cal(b, K);
    x += ret.first, y += ret.second;
  }
  cout << x << " " << y << endl;
  return 0;
}
