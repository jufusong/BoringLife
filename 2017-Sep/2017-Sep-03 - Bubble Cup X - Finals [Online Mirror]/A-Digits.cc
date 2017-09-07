#include <bits/stdc++.h>

using namespace std;

pair<string, int> solve(string s) {
  int sum = 0;
  string t;
  for (int i = 0; i < (int)s.size(); i++) {
    sum += s[i] - '0';
    t += s[i];
    if (i != (int)s.size() - 1) t += "+";
  }
  return make_pair(t, sum);
}

void dfs(string s, int now, int last, int p, string t) {
  if (p == (int)s.size()) {
    auto ret = solve(to_string(now + last));
    if (ret.second < 10) {
      cout << t << endl;
      cout << ret.first << endl;
      exit(0);
    }
    return;
  }
  dfs(s, now, last * 10 + s[p] - '0', p + 1, t + s[p]);
  if (p > 0) {
    dfs(s, now + last, s[p] - '0', p + 1, t + "+" + s[p]);
  }
}

int main(int argc, char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  auto ret = solve(s);
  cout << ret.first << endl;
  dfs(to_string(ret.second), 0, 0, 0, "");
  return 0;
}
