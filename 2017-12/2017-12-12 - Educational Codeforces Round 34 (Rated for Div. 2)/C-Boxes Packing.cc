#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    mp[t]++;
  }
  int mx = 0;
  for (auto e : mp) {
    mx = max(mx, e.second);
  }
  cout << mx << endl;
  return 0;
}
