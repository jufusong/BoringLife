#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    mp[t]++;
  }
  if (mp.size() == 2 && mp.begin()->second == mp.rbegin()->second) {
    cout << "YES" << endl;
    cout << mp.begin()->first << " " << mp.rbegin()->first << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
