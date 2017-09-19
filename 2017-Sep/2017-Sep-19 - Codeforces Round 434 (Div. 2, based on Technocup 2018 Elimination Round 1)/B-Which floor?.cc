#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  set<int> ans;
  for (int i = 1; i <= 100; i++) {
    bool flag = true;
    for (auto e : a) {
      flag &= ((e.first - 1) / i == e.second - 1);
    }
    if (flag) ans.insert((n - 1) / i + 1);
  }
  cout << (ans.size() == 1 ? *ans.begin(): -1) << endl;
  return 0;
}
