#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  multiset<int> se;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].second >> a[i].first;
  }
  sort(a.begin(), a.end());
  for (auto e : a) {
    int v = e.second;
    auto it = se.lower_bound(v);
    if (it != se.begin()) {
      it--;
      se.erase(it);
      se.insert(v);
    } else {
      se.insert(v);
    }
  }
  cout << se.size() << endl;
  return 0;
}
