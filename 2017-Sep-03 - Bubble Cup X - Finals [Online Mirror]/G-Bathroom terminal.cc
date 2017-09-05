#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
set<string> se;

int dfs(string& s, int p, string t) {
  if (p == s.size()) {
    if (se.count(t)) return 0;
    se.insert(t);
    return mp[t];
  }
  if (s[p] != '?') {
    return dfs(s, p + 1, t + s[p]);
  } else {
    int sum = dfs(s, p + 1, t);
    for (int i = 'a'; i <= 'e'; i++) {
      sum += dfs(s, p + 1, t + (char)i);
    }
    return sum;
  }
}

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s]++;
  }
  for (int i = 0; i < m; i++) {
    se.clear();
    string t;
    cin >> t;
    cout << dfs(t, 0, "") << endl;
  }
  return 0;
}
