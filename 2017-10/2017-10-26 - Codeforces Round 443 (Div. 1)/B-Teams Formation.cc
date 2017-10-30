#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K, m;
  cin >> n >> K >> m;
  vector<int> a(n);
  vector<pair<vector<pair<int, int>>, ll>> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(-1);
  vector<pair<int, int>> vec;
  for (int i = 1, cnt = 1; i < n + 1; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      vec.push_back({a[i - 1], cnt % K});
      cnt = 1;
    }
  }
  b.push_back({vec, 0});
  auto combine = [&K] (vector<pair<int, int>> v1, vector<pair<int, int>> v2) {
    reverse(v2.begin(), v2.end());
    while (!v1.empty() && !v2.empty() && v1.back().first == v2.back().first) {
      v1.back().second = (v2.back().second + v1.back().second) % K;
      v2.pop_back();
      if (v1.back().second == 0) {
        v1.pop_back();
      }
    }
    v1.insert(v1.end(), v2.rbegin(), v2.rend());
    return v1;
  };
  for (int i = 1; i < 31; i++) {
    auto ret = combine(b[i - 1].first, b[i - 1].first);
    auto v = b[i - 1].second + b[i - 1].second;
    if (ret.size() > 1010000) {
      vector<pair<int, int>> vec;
      for (int i = 0; i < ret.size(); i++) {
        if (i <= 500000 || i + 500000 >= ret.size()) {
          vec.push_back(ret[i]);
        } else {
          v += ret[i].second;
        }
        if (i == 500001) {
          vec.push_back({-1, 0});
        }
      }
      ret = vec;
    }
    b.push_back({ret, v});
  }
  
  ll val = 0;
  vector<pair<int, int>> now;
  for (int i = 30; i >= 0; i--) {
    if (m >= (1 << i)) {
      m -= (1 << i);
      now = combine(now, b[i].first);
      val += b[i].second;
    }
  }
  for (auto x : now) {
    val += x.second;
  }
  cout << val << endl;
  return 0;
}
