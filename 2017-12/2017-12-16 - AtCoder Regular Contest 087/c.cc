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
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (mp[i] >= i) {
      sum += i;
    }
  }
  cout << n - sum << endl;
  return 0;
}
