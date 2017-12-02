#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a(6), b(6);
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 6; i++) {
    cin >> b[i];
  }
  map<int, int> mp;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      mp[a[i] + b[j]]++;
    }
  }
  int ans = 0;
  for (auto x : mp) {
    if (x.second > mp[ans]) {
      ans = x.first;
    }
  }
  cout << ans << endl;
  return 0;
}
