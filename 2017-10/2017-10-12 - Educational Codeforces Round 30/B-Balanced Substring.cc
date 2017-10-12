#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, ans = 0;
  string s;
  cin >> n >> s;
  vector<int> a(200001, n + 1);
  a[100000] = -1;
  for (int i = 0, now = 100000; i < n; i++) {
    now += (s[i] == '1' ? 1 : -1);
    a[now] = min(a[now], i);
    ans = max(ans, i - a[now]);
  }
  cout << ans << endl;
  return 0;
}
