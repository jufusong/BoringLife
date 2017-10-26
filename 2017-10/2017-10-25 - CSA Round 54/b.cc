#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<string> a(n);
  vector<int> cnt(255);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i][0]]++;
  }
  int ans = 0;
  for (auto& s : a) {
    vector<int> vec(255);
    for (auto c : s) {
      vec[c]++;
    }
    cnt[s[0]]--;
    bool flag = true;
    for (int i = 'a'; i <= 'z'; i++) {
      flag &= (vec[i] <= cnt[i]);
    }
    ans += flag;
    cnt[s[0]]++;
  }
  cout << ans << endl;
  return 0;
}
