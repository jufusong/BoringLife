#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  s = "0+" + s + "+0";
  std::vector<pair<ll, ll>> a(s.size() + 1);
  auto cal = [](pair<ll, ll> x, pair<ll, ll> y, char op) {
    if (op == '*') {
      if (x.second == 0) {
        x.first *= y.first;
      } else {
        x.second *= y.first;
      }
      if (y.second) {
        x.first += x.second;
        x.second = y.second;
      }
    } else {
      x.first += x.second;
      if (y.second == 0) {
        x.second = y.first;
      } else {
        x.first += y.first;
        x.second = y.second;
      }
    }
    return x;
  };
  a[s.size() - 1] = {0, 0};
  for (int i = s.size() - 3; i >= 0; i -= 2) {
    a[i] = cal(a[i + 2], {s[i] - '0', 0}, s[i + 1]);
  }
  for (auto& e : a) {
    e = {e.second, e.first};
  }
  pair<ll, ll> now = {0, 0};
  ll mx = a[0].first + a[0].second;
  for (int i = 2; i < s.size(); i += 2) {
    pair<ll, ll> t = {s[i] - '0', 0};
    for (int j = i + 2; j + 2 < s.size(); j += 2) {
      t = cal(t, {s[j] - '0', 0}, s[j - 1]);
      ll z = t.first + t.second;
      auto ret = cal(cal(now, {z, 0}, s[i - 1]), a[j + 2], s[j + 1]);
      mx = max(mx, ret.first + ret.second);
    }
    now = cal(now, {s[i] - '0', 0}, s[i - 1]);
  }
  cout << mx << endl;
  return 0;
}
