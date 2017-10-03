#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    mp[t]++;
  }
  int mx = 0;
  for (int i = 0; i <= 100000; i++) {
    mx = max(mx, mp[i] + mp[i - 1] + mp[i + 1]);
  }
  cout << mx << endl;
  return 0;
}
