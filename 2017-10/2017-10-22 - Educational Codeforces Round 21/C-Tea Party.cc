#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    w -= (a[i].first + 1) / 2;
  }
  if (w < 0) {
    cout << -1 << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  return 0;
}
