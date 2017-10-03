#include <bits/stdc++.h>

using namespace std;

struct A{
  int g, p, t, id;
};

int main(int argc, char *argv[]) {
  int n, w, h;
  scanf("%d%d%d", &n, &w, &h);
  map<int, vector<A>> mp;
  vector<pair<int, int>> ans(n);
  for (int i = 0; i < n; i++) {
    int g, p, t;
    scanf("%d%d%d", &g, &p, &t);
    mp[t - p].push_back(A{g, p, t, i});
  }
  for (auto e : mp) {
    vector<pair<int, int>> vec;
    for (A& x : e.second) {
      if (x.g == 1) vec.push_back({x.p, h});
      else vec.push_back({w, x.p});
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.second == y.second ? x.first < y.first : x.second > y.second;
      });
    auto& vv = e.second;
    sort(vv.begin(), vv.end(), [](const A& x, const A& y){
        if (x.g != y.g) {
          return x.g > y.g;
        }
        if (x.g == 2) {
          return x.p > y.p;
        }
        return x.p < y.p;
      });
    for (int i = 0; i < (int)vv.size(); i++) {
      ans[vv[i].id] = vec[i];
    }
  }
  for (auto x : ans) {
    printf("%d %d\n", x.first, x.second);
  }
  return 0;
}
