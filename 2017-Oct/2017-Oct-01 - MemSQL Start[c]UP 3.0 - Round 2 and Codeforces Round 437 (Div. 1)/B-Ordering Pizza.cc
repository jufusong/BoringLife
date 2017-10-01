#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n, S;
  cin >> n >> S;
  vector<tuple<int, int, int>> vec;
  ll sum = 0, ans = 0;
  for (int i = 0, s, a, b; i < n; i++) {
    cin >> s >> a >> b;
    vec.push_back({s, a, b});
    sum += s;
    ans += (ll)s * b;
  }
  if (sum % S > 0) {
    vec.push_back({S - sum % S, 0, 0});
  }
  sort(vec.begin(), vec.end(), [](const tuple<int, int, int>& x, const tuple<int, int, int>& y) {
      return get<2>(x) - get<1>(x) < get<2>(y) - get<1>(y);
    });
  ll pr = 0, ret = ans;
  for (int i = 0; i < (int)vec.size(); i++) {
    ll s, a, b;
    tie(s, a, b) = vec[i];
    pr += s;
    if (s >= pr % S) {
      ll t = s - pr % S;
      ret = max(ret, ans + (a - b) * t);
    }
    ans += (a - b) * s;
    if (pr % S > 0  && pr % S + get<0>(vec[i + 1]) < S) continue;
    ll extra = 0;
    if (pr % S > 0) {
      ll ts, ta, tb;
      tie(ts, ta, tb) = vec[i + 1];
      extra = (ta - tb) * (S - pr % S);
    }
    ret = max(ret, ans + extra);
  }
  cout << ret << endl;
  return 0;
}
