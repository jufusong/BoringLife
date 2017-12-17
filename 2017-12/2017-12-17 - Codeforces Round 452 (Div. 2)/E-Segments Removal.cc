#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  set<tuple<int, int, int>> se;
  for (int i = 2, L = 1; i <= n + 1; i++) {
    if (a[i] != a[i - 1]) {
      se.insert({L, i - 1, a[i - 1]});
      L = i;
    }
  }
  priority_queue<tuple<int, int, int>> q;
  for (auto e : se) {
    int l, r, v;
    tie(l, r, v) = e;
    q.push({r - l, -l, v});
  }
  int cnt = 0;
  while (!q.empty()) {
    auto e = q.top();
    q.pop();
    int x, y, v;
    tie(x, y, v) = e;
    int l = -y, r = x + l;
    auto it = se.find({l, r, v});
    if (it != se.end()) {
      cnt++;
      auto it1 = it, it2 = it;
      if (it1 != se.begin()) {
        --it1, ++it2;
        if (it2 != se.end() && get<2>(*it1) == get<2>(*it2)) {
          int l1, r1, l2, r2, v;
          tie(l1, r1, v) = *it1;
          tie(l2, r2, ignore) = *it2;
          int l = l1, r = r1 + (r2 - l2 + 1);
          q.push({r - l, -l, v});
          se.erase(it1);
          se.erase(it2);
          se.insert({l, r, v});
        }
      }
      se.erase(it);
    }
  }
  cout << cnt << endl;
  return 0;
}
