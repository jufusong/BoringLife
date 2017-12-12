#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    mp[t]++;
  }
  vector<pair<int, int>> a = {mp.begin(), mp.end()};
  sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
      return x.second > y.second;
    });
  int sum = 0;
  for (int i = k; i < a.size(); i++) {
    sum += a[i].second;
  }
  cout << sum << endl;
  return 0;
}
