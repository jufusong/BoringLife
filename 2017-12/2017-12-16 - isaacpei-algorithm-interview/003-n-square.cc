#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int, int>> solve(vector<tuple<int, int, int, int>> a) {
  list<tuple<int, int, int, int>> li = {a.begin(), a.end()};
  for (auto it1 = li.begin(); it1 != li.end();) {
    bool ok = false;
    for (auto it2 = li.begin(); it2 != it1; it2++) {
      auto [u1, d1, l1, r1] = *it1;
      auto [u2, d2, l2, r2] = *it2;
      if (min(u1, u2) >= max(d1, d2) && min(r1, r2) >= max(l1, l2)) {
        li.emplace_back(max(u1, u2), min(d1, d2), min(l1, l2), max(r1, r2));
        li.erase(it2);
        it1 = li.erase(it1);
        ok = true;
        break;
      }
    }
    if (!ok) it1++;
  }
  return {li.begin(), li.end()};
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> a;
  for (int i = 0; i < n; ++i) {
    int u, d, l, r;
    cin >> u >> d >> l >> r;
    a.emplace_back(u, d, l, r);
  }
  auto ans = solve(a);
  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    auto [u, d, l, r] = x;
    cout << u << " " << d << " " << l << " " << r << endl;
  }
  return 0;
}
