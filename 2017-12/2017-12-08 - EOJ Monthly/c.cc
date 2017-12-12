#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<vector<int>> vec(26);
  for (int i = 0; i < s.size(); ++i) {
    vec[s[i] - 'a'].push_back(i);
  }
  sort(vec.begin(), vec.end(), [](const vector<int>& v1, const vector<int>& v2) {
      return v1.size() > v2.size();
    });
  vector<int> a;
  for (auto& v : vec) {
    for (auto x : v) {
      a.push_back(x);
    }
  }
  vector<int> ans(s.size());
  if (vec[0].size() * 2 > s.size()) {
    cout << "impossible" << endl;
  } else {
    int offset = vec[0].size();
    for (int i = 0; i < a.size(); ++i) {
      ans[a[i]] = a[(i + offset) % a.size()];
    }
    for (auto x : ans) {
      cout << s[x];
    }
  }
  return 0;
}
