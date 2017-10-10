#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a, b;
  for (int i = 0; i < n; i++) {
    int t, s;
    cin >> t >> s;
    t ? a.push_back({i + 1, s}) : b.push_back({i + 1, s});
  }
  for (int h1 = 0, h2 = 0; h1 < a.size() && h2 < b.size();) {
    int v = min(a[h1].second, b[h2].second);
    cout << a[h1].first << " " << b[h2].first << " " << v << endl;
    a[h1].second -= v, b[h2].second -= v;
    a[h1].second || h1 == a.size() - 1 ? h2++ : h1++;
  }
  return 0;
}
