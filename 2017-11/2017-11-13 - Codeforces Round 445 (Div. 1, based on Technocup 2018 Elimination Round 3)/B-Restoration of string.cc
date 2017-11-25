#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> g(255, -1);
  vector<int> in(255);
  vector<bool> vv(255);
  for (int i = 0; i < n; i++) {
    vector<bool> v(255);
    string s;
    cin >> s;
    v[s[0]] = vv[s[0]] = true;
    for (int i = 1; i < s.size(); i++) {
      char c = s[i];
      if (v[c] || ((g[s[i - 1]] != -1 || in[c]) && g[s[i - 1]] != s[i])) {
        cout << "NO" << endl;
        return 0;
      }
      v[c] = true;
      g[s[i - 1]] = s[i];
      vv[c] = true;
      in[c]++;
    }
  }
  int cnt = 0;
  for (auto x : vv) {
    cnt += x;
  }
  string s;
  for (int i = 'a'; i <= 'z'; i++) {
    if (!in[i] && vv[i]) {
      for (int j = i; j != -1; j = g[j]) {
        s += (char)j;
      }
    }
  }
  if (s.size() != cnt) {
    cout << "NO" << endl;
    return 0;
  }
  cout << s << endl;
  return 0;
}
