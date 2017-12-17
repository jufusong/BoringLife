#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int, int>> solve(vector<tuple<int, int, int, int>> a) {
  vector<int> aux;
  for (auto e : a) {
    auto [u, d, l, r] = e;
    aux.push_back(l);
    aux.push_back(r);
  }
  sort(aux.begin(), aux.end());
  aux.erase(unique(aux.begin(), aux.end()), aux.end());
  auto getIndex = [&aux](int v) {
    return lower_bound(aux.begin(), aux.end(), v) - aux.begin();
  };

  sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
      return get<2>(x) < get<2>(y);
    });

  map<pair<int, int>, tuple<int, int, int, int>> mp;
  for (auto e : a) {
    auto [u, d, l, r] = e;
    for (;;) {
      auto it = mp.lower_bound({d, u});
      auto update = [&](auto e) {
        auto [u1, d1, l1, r1] = e;
        u = max(u, u1), d = min(d, d1), l = min(l, l1), r = max(r, r1);
      };
      if (it != mp.end() && it->first.second <= u) {
        update(it->second);
        mp.erase(it);
        continue;
      }
      if (it != mp.begin() && (--it)->first.second >= l) {
        update(it->second);
        mp.erase(it);
        continue;
      }
      break;
    }
    mp[{d, u}] = {u, d, l, r};
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
