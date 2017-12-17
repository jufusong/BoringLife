#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int, int>> solve(vector<tuple<int, int, int, int>> a) {
  bool flag = true;
  for (; flag; ) {
    flag = false;
    for (int i = 0; i < a.size() && !flag; i++) {
      for (int j = i + 1; j < a.size() && !flag; j++) {
        auto [u1, d1, l1, r1] = a[i];
        auto [u2, d2, l2, r2] = a[j];
        if (min(u1, u2) >= max(d1, d2) && min(r1, r2) >= max(l1, l2)) {
          a.erase(a.begin() + j);
          a.erase(a.begin() + i);
          a.emplace_back(max(u1, u2), min(d1, d2), min(l1, l2), max(r1, r2));
          flag = true;
        }
      }
    }
  }
  return a;
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
