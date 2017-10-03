#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  vector<int> b;
  for (int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    a.push_back({l + 1, r + 1});
    b.push_back(l), b.push_back(l + 1), b.push_back(r + 1), b.push_back(r + 2);
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  auto getIndex = [&b](int x) {
    return lower_bound(b.begin(), b.end(), x) - b.begin();
  };
  vector<int> c(b.size());
  for (auto e : a) {
    c[getIndex(e.first)]++;
    c[getIndex(e.second + 1)]--;
  }
  for (int i = 1; i < (int)c.size(); i++) {
    c[i] += c[i - 1];
    if (c[i] > 2) c[i] = 2;
  }
  for (int i = 1; i < (int)c.size(); i++) {
    c[i] += c[i - 1];
  }
  for (int i = 0; i < n; i++) {
    int l = getIndex(a[i].first - 1), r = getIndex(a[i].second);
    if ((r - l) * 2 == c[r] - c[l]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
