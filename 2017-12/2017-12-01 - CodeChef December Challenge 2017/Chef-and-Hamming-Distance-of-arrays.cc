#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b(n, 0);
    multiset<pair<int, int>> se;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
      se.insert(a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      auto it = se.lower_bound({a[i].first + 1, a[i].second});
      if (it == se.end()) {
        it = se.begin();
      }
      b[a[i].second] =it->first;
      se.erase(it);
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
      });
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += (a[i].first != b[i]);
    }
    cout << cnt << endl;
    for (auto x : b) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
