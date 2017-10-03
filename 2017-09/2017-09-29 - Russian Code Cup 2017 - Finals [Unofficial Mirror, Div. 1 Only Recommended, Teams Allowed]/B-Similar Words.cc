#include <bits/stdc++.h>

using namespace std;

const int N = 2000005;

int ch[N][26], cnt = 0;

vector<int> insert(string s) {
  vector<int> ret(1, 0);
  for (int i = 0, now = 0; i < (int)s.size(); i++) {
    int c = s[i] - 'a';
    if (!ch[now][c]) {
      ch[now][c] = ++cnt;
      fill(ch[cnt], ch[cnt] + 26, 0);
    }
    now = ch[now][c];
    ret.push_back(now);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  vector<set<pair<int, int>>> a(1000005);
  int T;
  cin >> T;
  while (T--) {
    cnt = 0;
    fill(ch[0], ch[0] + 26, 0);
    int n, mx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      mx = max(mx, (int)s.size());
      auto v1 = insert(s);
      auto v2 = insert(s.substr(1));
      for (int i = 1; i <= (int)s.size(); i++) {
        a[i].insert({v1[i], v2[i - 1]});
      }
    }
    int ans = 0;
    set<int> se;
    for (int i = mx; i >= 1; i--) {
      set<int> ns;
      for (auto e : a[i]) {
        if (!se.count(e.first)) {
          ns.insert(e.second);
          ans++;
        }
      }
      se = ns;
      a[i].clear();
    }
    cout << ans << endl;
  }
  return 0;
}
