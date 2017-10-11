#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100005;
const int inf = 1e9 + 2;

namespace fw {
  int in[N];

  int lowbit(int n) {return n & (-n);}

  void update(int p, int val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }

  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int, int>> a(n);
  for (int i = 0, t, s, f; i < n; i++) {
    cin >> t >> s >> f;
    a[i] = {t, s, f, i};
  }
  vector<ll> ans(n);
  sort(a.begin(), a.end());
  vector<set<pair<int, int>>> s2(m + 1);
  vector<set<int>> s1(m + 1);
  for (ll T = 1, h = 0, now = 1; ;) {
    while (h < a.size() && get<0>(a[h]) <= T) {
      int s, f, id;
      tie(ignore, s, f, id) = a[h];
      fw::update(s, 1);
      s2[s].insert({f, id});
      h++;
    }
    for (auto e : s2[now]) {
      s1[e.first].insert(e.second);
      fw::update(e.first, 1);
    }
    fw::update(now, -(int)s2[now].size());
    s2[now].clear();
    for (auto x : s1[now]) {
      ans[x] = T;
    }
    fw::update(now, -(int)s1[now].size());
    s1[now].clear();
    int x = fw::query(N - 1) - fw::query(now), y = fw::query(now);
    if (x == 0 && y == 0 && h == a.size()) break;
    ll delta = inf;
    if (x >= y) {
      int low = now, high = m;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (fw::query(mid) - fw::query(now)) high = mid - 1;
        else low = mid + 1;
      }
      delta = min(delta, low - now);
    } else {
      int low = 1, high = now;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (fw::query(now) - fw::query(mid)) low = mid + 1;
        else high = mid - 1;
      }
      delta = min(delta, now - low);
    }
    if (h < a.size()) {
      delta = min(delta, get<0>(a[h]) - T);
    }
    T += delta;
    if (x || y) now += (x >= y ? delta : -delta);
  }
  for (auto x : ans) {
    cout << x << endl;
  }
  return 0;
}
