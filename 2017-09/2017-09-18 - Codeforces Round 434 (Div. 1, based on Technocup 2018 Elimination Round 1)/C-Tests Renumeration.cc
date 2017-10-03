#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, cnt = 0;
  cin >> n;
  vector<pair<string, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    cnt += a[i].second;
  }
  set<string> s1, s2;
  for (int i = 1; i <= n; i++) {
    if (i <= cnt) {
      s1.insert(to_string(i));
    } else {
      s2.insert(to_string(i));
    }
  }
  set<string> s3, s4, s5, s6;
  for (auto e : a) {
    string s = e.first;
    int t = e.second;
    if (s1.count(s)) {
      s1.erase(s);
      if (t != 1) s3.insert(s);
    } else if (s2.count(s)){
      s2.erase(s);
      if (t != 0) s4.insert(s);
    } else {
      t == 1 ? s5.insert(s) : s6.insert(s);
    }
  }
  vector<pair<string, string>> op;
  if (!s3.empty() && s5.empty() && s6.empty()) {
    op.push_back({*s3.begin(), "z"});
    s6.insert("z");
    s1.insert(*s3.begin());
    s3.erase(s3.begin());
  }
  for (; !s1.empty() || !s2.empty(); ) {
    if (!s1.empty()) {
      string s = *s1.begin();
      s1.erase(s1.begin());
      if (!s4.empty()) {
        s2.insert(*s4.begin());
        op.push_back({*s4.begin(), s});
        s4.erase(s4.begin());
      } else {
        op.push_back({*s5.begin(), s});
        s5.erase(s5.begin());
      }
    } else {
      string s = *s2.begin();
      s2.erase(s2.begin());
      if (!s3.empty()) {
        s1.insert(*s3.begin());
        op.push_back({*s3.begin(), s});
        s3.erase(s3.begin());
      } else {
        op.push_back({*s6.begin(), s});
        s6.erase(s6.begin());
      }
    }
  }
  cout << op.size() << endl;
  for (auto e : op) {
    cout << "move " << e.first << " " << e.second << endl;
  }
  return 0;
}
