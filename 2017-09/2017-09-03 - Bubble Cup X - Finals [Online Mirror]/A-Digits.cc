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

void dfs(string s, int now, int last, int p, string t, string zz) {
  if (p == (int)s.size()) {
    auto ret = solve(to_string(now + last));
    if (ret.second < 10) {
      cout << zz << endl;
      cout << t << endl;
      cout << ret.first << endl;
      exit(0);
    }
    return;
  }
  if (p > 0) {
    dfs(s, now + last, s[p] - '0', p + 1, t + "+" + s[p], zz);
  }
  dfs(s, now, last * 10 + s[p] - '0', p + 1, t + s[p], zz);
}

int main(int argc, char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  auto ret = solve(s);
  dfs(to_string(ret.second), 0, 0, 0, "", ret.first);
  auto Z = [](string s) {
    string t;
    int sum = 0;
    for (int i = 0; i < (int)s.size(); ) {
      int k = rand() % 2;
      if (i == (int)s.size() - 1) k = 0;
      if (k == 0) {
        sum += s[i] - '0';
        if (i) t += "+";
        t += s[i];
        i++;
      } else {
        sum += (s[i] - '0') * 10 + s[i + 1] - '0';
        if (i) t += "+";
        t += s[i];
        t += s[i + 1];
        i += 2;
      }
    }
    return make_pair(sum, t);
  };
  while (true) {
    auto xx = Z(s);
    dfs(to_string(xx.first), 0, 0, 0, "", xx.second);
  }
  return 0;
}
