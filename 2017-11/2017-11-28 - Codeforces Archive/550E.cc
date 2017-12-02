#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  string s;
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    s += (char)(t + '0');
    if (t == 0) {
      st.push_back(i);
    }
  }
  string t = s;
  if (s.back() == '1') {
    cout << "NO" << endl;
    return 0;
  }
  bool flag = false;
  if (n >= 2) {
    if (s[n - 2] == '0' && st.size() == 2) {
      cout << "NO" << endl;
      return 0;
    }
    flag = (s[n - 2] == '0');
  }
  cout << "YES" << endl;
  for (int i = 0; i < t.size(); ++i) {
    if (flag && i == n - 1) cout << "))";
    if (i) cout << "->";
    if (flag && (i == st[0] + 1 || i == st[0])) cout << "(";
    cout << t[i];
  }
  return 0;
}
