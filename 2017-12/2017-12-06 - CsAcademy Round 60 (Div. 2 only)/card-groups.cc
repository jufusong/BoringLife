#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<long long> a, b;
  long long S = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    S -= y;
    i < n / 2 ? a.push_back(x + y) : b.push_back(x + y);
  }
  auto solve = [](vector<long long> a) {
    vector<pair<long long, int>> ret;
    for (int i = 0; i < 1 << a.size(); ++i) {
      long long sum = 0;
      for (int j = 0; j < a.size(); ++j) {
        if ((1 << j) & i) {
          sum += a[j];
        }
      }
      ret.push_back({sum, i});
    }
    sort(ret.begin(), ret.end(), [](const pair<long long, int>& x, const pair<long long, int>& y) {
        if (x.first != y.first) return x.first < y.first;
        return __builtin_popcount(x.second) < __builtin_popcount(y.second);
        });
    vector<pair<long long, int>> ans;
    ans.push_back(ret[0]);
    for (int i = 1; i < ret.size(); ++i) {
      if (ret[i].first != ret[i - 1].first || __builtin_popcount(ret[i].second) != __builtin_popcount(ret[i - 1].second)) {
        ans.push_back(ret[i]);
      }
    }
    return ans;
  };
  auto vec1 = solve(a), vec2 = solve(b);
  int p = -1;
  long long ans;
  for (auto x : vec1) {
    long long val = x.first;
    int num = x.second;
    int cnt = __builtin_popcount(num);
    auto it = lower_bound(vec2.begin(), vec2.end(), pair<long long, int>{-S - val, 0});
    while (it != vec2.end() && it->first + val == -S) {
      int cc = cnt + __builtin_popcount(it->second);
      if (p == -1 || abs(n - 2 * p) > abs(n - 2 * cc)) {
        p = cc;
        ans = (((long long)it->second << a.size()) | num);
      }
      ++it;
    }
  }
  if (p == -1) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      cout << !(bool)((1LL << i) & ans);;
    }
  }
  return 0;
}
