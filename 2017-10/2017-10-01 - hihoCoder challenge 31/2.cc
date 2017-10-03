#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll f[61][61][61][61];
bool vis[61][61][61][61];

int main(int argc, char *argv[]) {
  vector<ll> J(100, 1);
  for (int i = 1; i <= 90; i++) {
    J[i] = J[i - 1] * i % mod;
  }
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mp[t]++;
  }
  vector<pair<int, int>> a = {mp.begin(), mp.end()};
  queue<tuple<int, int, int, int>> q;
  f[0][0][0][0] = J[a[0].second];
  q.push(make_tuple(0, 0, 0, 0));
  vis[0][0][0][0] = true;
  auto add = [](ll& x, ll y) {
    x = (x + y) % mod;
  };
  ll ans = 0;
  while (!q.empty()) {
    int x1, y1, x2, y2;
    tie(x1, y1, x2, y2) = q.front();
    q.pop();
    //    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << f[x1][y1][x2][y2] << endl;
    if (x1 == (int)a.size() - 1 || x2 == (int)a.size() - 1) {
      add(ans, f[x1][y1][x2][y2]);
      continue;
    }
    int p = max(x1, x2) + 1;
    if (a[p].second == 1) {
      if (a[p].first - a[x1].first >= a[x1].first - a[y1].first) {
        add(f[p][x1][x2][y2], (ll)f[x1][y1][x2][y2] * J[a[p].second] % mod);
        if (!vis[p][x1][x2][y2]) {
          q.push(make_tuple(p, x1, x2, y2));
          vis[p][x1][x2][y2] = true;
        }
      }
      if (a[p].first - a[x2].first >= a[x2].first - a[y2].first) {
        add(f[x1][y1][p][x2], (ll)f[x1][y1][x2][y2] * J[a[p].second] % mod);
        if (!vis[x1][y1][p][x2]) {
          q.push(make_tuple(x1, y1, p, x2));
          vis[x1][y1][p][x2] = true;
        }
      }
    }
    if (a[p].second == 2) {
      for (int i = 1; i < a[p].second; i++) {
        if (a[p].first - a[x1].first >= a[x1].first - a[y1].first && a[p].first - a[x2].first >= a[x2].first - a[y2].first) {
          add(f[p][x1][p][x2], (ll)f[x1][y1][x2][y2] * J[a[p].second] % mod);
          if (!vis[p][x1][p][x2]) {
            q.push(make_tuple(p, x1, p, x2));
            vis[p][x1][p][x2] = true;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
