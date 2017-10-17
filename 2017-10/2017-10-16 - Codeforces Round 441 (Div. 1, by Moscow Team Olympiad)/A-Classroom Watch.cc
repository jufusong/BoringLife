#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = n - 1; i >= max(0, n - 900); i--) {
    string s = to_string(i);
    int cnt = 0;
    for (auto c : s) {
      cnt += c - '0';
    }
    if (i + cnt == n) {
      ans.push_back(i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x << endl;
  }
  return 0;
}
