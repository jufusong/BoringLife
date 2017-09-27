#include <bits/stdc++.h>

using namespace std;

vector<int> pre[101][2001];
int dp[101][2001];

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> vec;
  for (int i = 1; i <= n; i++) {
    int t, d, p;
    cin >> t >> d >> p;
    vec.push_back({t, d, p, i});
  }
  sort(vec.begin(), vec.end(), [](const tuple<int, int, int, int>& x, const tuple<int, int, int, int>& y) {
      return get<1>(x) < get<1>(y);
    });
  for (int i = 1; i <= n; i++) {
    int t, d, p, id;
    tie(t, d, p, id) = vec[i - 1];
    for (int j = 0; j <= 2000; j++) {
      pre[i][j] = pre[i - 1][j];
      dp[i][j] = dp[i - 1][j];
    }
    for (int j = 0; j < d - t; j++) {
      if (dp[i - 1][j] + p > dp[i][j + t]) {
        dp[i][j + t] = dp[i - 1][j] + p;
        pre[i][j + t] = pre[i - 1][j];
        pre[i][j + t].push_back(id);
      }
    }
  }
  int mx = 0;
  for (int i = 0; i <= 2000; i++) {
    if (dp[n][i] > dp[n][mx]) {
      mx = i;
    }
  }
  cout << dp[n][mx] << endl;
  cout << pre[n][mx].size() << endl;
  for (auto x : pre[n][mx]) {
    cout << x << " ";
  }
  return 0;
}
