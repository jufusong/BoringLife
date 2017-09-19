#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  vector<int> a(7);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 7; j++) {
      a[j] += s[j] - '0';
    }
  }
  int mx = 0;
  for (auto x : a) {
    mx = max(mx, x);
  }
  cout << mx << endl;
  return 0;
}
