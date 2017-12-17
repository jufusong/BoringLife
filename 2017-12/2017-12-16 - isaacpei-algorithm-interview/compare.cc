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

vector<tuple<int, int, int, int>> solve2(vector<tuple<int, int, int, int>> a) {
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
  int dd = 0;
  while (true) {
    cout << dd++ << endl;
    vector<tuple<int, int, int, int>> a;
    for (int i = 0; i < 500; i++) {
      int u = rand() % 100, d = rand() % 100, l = rand() % 100, r = rand() % 100;
      a.emplace_back(u, d, l, r);
    }
    auto ret1 = solve(a);
    auto ret2 = solve2(a);
    sort(ret1.begin(), ret1.end());
    sort(ret2.begin(), ret2.end());
    assert(ret1 == ret2);
  }
  return 0;
}
