#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, A, B, k, f;
  cin >> n >> A >> B >> k >> f;
  vector<pair<string, string>> a;
  map<pair<string, string>, int> mp;
  for (int i = 0; i < n; i++) {
    string s, t;
    cin >> s >> t;
    int cost = (i && s == a.back().second ? B : A);
    a.push_back({s, t});
    if (s > t) swap(s, t);
    mp[make_pair(s, t)] += cost;
  }
  vector<int> vec;
  for (auto e : mp) {
    vec.push_back(e.second);
  }
  sort(vec.begin(), vec.end(), greater<int>());
  int ans = 0;
  for (auto x : vec) {
    if (x > f && k) {
      ans += f;
      k--;
    } else {
      ans += x;
    }
  }
  cout << ans << endl;
  return 0;
}
