#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  string s, t;
  int K;
  while (cin >> s >> K >> t) {
    map<pair<string, int>, int> mp;
    mp[make_pair(s, K)] = 0;
    set<pair<string, int>> se;
    se.insert(make_pair(s, K));
    queue<pair<string, int>> q;
    q.push({s, K});
    int minn = inf;
    auto insert = [&mp, &q, &se, &t, &minn] (string s, int v, int d) {

      auto st = make_pair(s, v);
      if (!mp.count(st) || mp[st] > d) {
        mp[st] = d;
        if (s == t) {
          minn = min(minn, d);
        }
        if (d < minn && !se.count(st)) {
          se.insert(st);
          q.push(st);
        }
      }
    };
    while (!q.empty()) {
      auto u = q.front();
      string tx = u.first;
      int ty = u.second, d = mp[u];
      q.pop();
      se.erase(u);
      if (ty > 0) {
        insert(tx, ty - 1, d + 1);
      }
      if (ty < tx.size()) {
        insert(tx, ty + 1, d + 1);
      }
      set<char> hh(tx.begin(), tx.end());
      for (int i = 'a'; i <= 'g'; i++) {
        string xx = tx;
        if (!hh.count(i)) {
          xx.insert(xx.begin() + ty, i);
          insert(xx, ty + 1, d + 2);
        }
      }
      if (ty > 0) {
        string xx = tx;
        xx.erase(xx.begin() + ty - 1);
        insert(xx, ty - 1, d + 2);
      }
      if (ty < tx.size()) {
        string xx = tx;
        xx.erase(xx.begin() + ty);
        insert(xx, ty, d + 2);
      }
    }
    int ans = inf;
    for (int i = 0; i < 10; i++) {
      auto st = make_pair(t, i);
      if (mp.count(st)) {
        ans = min(ans, mp[st]);
      }
    }
    if (ans == inf) {
      puts("-1");
    } else {
      printf("%.1f\n", ans / 2.0);
    }
  }
  return 0;
}
