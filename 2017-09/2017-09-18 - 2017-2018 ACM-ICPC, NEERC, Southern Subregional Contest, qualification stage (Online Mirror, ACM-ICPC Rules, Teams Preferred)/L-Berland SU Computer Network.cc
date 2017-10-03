#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  map<set<int>, int> mp;
  for (int i = 1; i <= n; i++) {
    int now = 0;
    while (now < n - 1) {
      int t;
      char c;
      cin >> t >> c;
      now += t;
      set<int> se;
      for (int j = 0, v; j < t; j++) {
        cin >> v;
        if (now != n - 1 || j != t - 1) cin >> c;
        se.insert(v);
      }
      if (mp.count(se)) {
        cout << -1 << endl;
        return 0;
      }
      mp[se] = i;
    }
  }
  vector<pair<int, int>> vec;
  set<set<int>> a;
  map<set<int>, int> m2;
  for (int i = 1; i <= n; i++) {
    a.insert(set<int>{i});
    m2[set<int>{i}] = i;
  }
  for (;;) {
    bool flag = false;
    for (auto x : a) {
      if (mp.count(x)) {
        flag = true;
        int p = mp[x];
        for (auto y : a) {
          if (y.count(p)) {
            vec.push_back({m2[x], p});
            a.erase(x), a.erase(y);
            x.insert(y.begin(), y.end());
            a.insert(x);
            m2[x] = p;
            break;
          }
        }
        break;
      }
    }
    if (!flag) break;
  }
  if ((int)vec.size() == n - 1) {
    cout << n - 1 << endl;
    for (auto e : vec) {
      cout << e.first << " " << e.second << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
